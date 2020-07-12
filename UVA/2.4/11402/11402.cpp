#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> st; vector<char> wait; int N; string A;

int LT(int i) { return i*2+1; }
int RT(int i) { return i*2+2; }

int change(int wait, int prev)
{
	if (wait == 0 || wait == 1)
		return wait;
	if (prev == -1)
		return 2;
	if (prev == 0)
		return 1;
	if (prev == 1)
		return 0;
	if (prev == 2)
		return -1;
}

void st_ru_helper(int i, int L, int R, int a, int b, char d)
{
	if (wait[i] != -1)
	{
		int prev = st[i];
		if (wait[i] == 0) st[i] = 0;
		else if (wait[i] == 1) st[i] = R - L + 1;
		else if (wait[i] == 2) st[i] = (R-L) + 1 - st[i];
		// printf("Changing (%d %d) from %d to %d\n", L, R, prev, st[i]);
		if (L != R)
		{
			wait[LT(i)] = change(wait[i], wait[LT(i)]);
			wait[RT(i)] = change(wait[i], wait[RT(i)]);
		}
		wait[i] = -1;
	}
	if (L > R || L > b || R < a) 
		return;
	else if (L >= a && R <= b)
	{
		int prev = st[i];
		if (d == 0) st[i] = 0;
		else if (d == 1) st[i] = R - L + 1;
		else if (d == 2) st[i] = (R-L) + 1 - st[i];
		// printf("Changing (%d %d) from %d to %d\n", L, R, prev, st[i]);
		if (L != R)
		{
			wait[LT(i)] = change(d, wait[LT(i)]);
			wait[RT(i)] = change(d, wait[RT(i)]);
		}
	}
	else
	{
		int m = (L+R)/2;
		st_ru_helper(LT(i), L, m, a, b, d);
		st_ru_helper(RT(i), m+1, R, a, b, d);
		st[i] = st[LT(i)] + st[RT(i)];
	}
}

void st_ru(int a, int b, char d)
{
	st_ru_helper(0, 0, N-1, a, b, d);	
}

int st_rq_helper(int i, int L, int R, int a, int b)
{
	if (wait[i] != -1)
	{
		int prev = st[i];
		if (wait[i] == 0) st[i] = 0;
		else if (wait[i] == 1) st[i] = R - L + 1;
		else if (wait[i] == 2) st[i] = (R-L) + 1 - st[i];
		// printf("Changing (%d %d) from %d to %d\n", L, R, prev, st[i]);
		if (L != R)
		{
			wait[LT(i)] = change(wait[i], wait[LT(i)]);
			wait[RT(i)] = change(wait[i], wait[RT(i)]);
		}
		wait[i] = -1;
	}
	if (L > R || a > R || b < L) return 0;
	if (L >= a && R <= b) return st[i];
	int m = (L+R)/2;
	return st_rq_helper(LT(i), L, m, a, b) + st_rq_helper(RT(i), m+1, R, a, b);
}

int st_rq(int a, int b) { return st_rq_helper(0, 0, N-1, a, b); }

void st_init_helper(int i, int L, int R)
{
	if (L > R) 
		return;
	else if (L == R) 
		st[i] = A[L] == '1';
	else
	{
		int mid = (L+R)/2;
		st_init_helper(LT(i), L, mid);
		st_init_helper(RT(i), mid+1, R);
		st[i] = st[LT(i)] + st[RT(i)];
	}
}

void st_init(const string &_A)
{
	A = _A;
	N = A.size();
	st.assign(N*4, 0);
	wait.assign(N*4, -1);
	st_init_helper(0, 0, N-1);
}

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		printf("Case %d:\n", t+1);
		string pirates = "";
		int M; cin >> M;
		for (int m = 0; m < M; m++)
		{
			int C; cin >> C;
			string s; cin >> s;
			for (int c = 0; c < C; c++) pirates += s;
		}

		st_init(pirates);
		int Q; cin >> Q;
		int qu = 1;
		for (int q = 0; q < Q; q++)
		{
			char c; int a, b; cin >> c >> a >> b;
			if (c == 'F')
			{
				// printf("Set from %d to %d.\n", a, b);
				st_ru(a, b, 1);
			}
			else if (c == 'E')
			{
				// printf("Clear from %d to %d.\n", a, b);
				st_ru(a, b, 0);
			}
			else if (c == 'I')
			{
				// printf("I from %d to %d.\n", a, b);
				st_ru(a, b, 2);
			}
			else
			{
				// printf("Q from %d to %d.\n", a, b);
				printf("Q%d: %d\n", qu++, st_rq(a, b));
			}
		}
	}
}



