#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> A, st, lazy; int N;

int LT(int i) { return i*2+1; }
int RT(int i) { return i*2+2; }

void st_ru_helper(int i, int L, int R, int a, int b, int d)
{
	if (lazy[i] != 0)
	{
		st[i] += (R-L+1) * lazy[i];
		if (L != R)
		{
			lazy[LT(i)] += lazy[i]; 
			lazy[RT(i)] += lazy[i];
		}
		lazy[i] = 0;
	}
	if (L > R || L > b || R < a) 
		return;
	else if (L >= a && R <= b)
	{
		st[i] += (R-L+1) * d;
		if (L != R)
		{
			lazy[LT(i)] += d; 
			lazy[RT(i)] += d;
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

void st_ru(int a, int b, int d)
{
	st_ru_helper(0, 0, N-1, a, b, d);	
}

int st_rq_helper(int i, int L, int R, int a, int b)
{
	if (lazy[i] != 0)
	{
		st[i] += (R-L+1) * lazy[i];
		if (L != R)
		{
			lazy[LT(i)] += lazy[i]; 
			lazy[RT(i)] += lazy[i];
		}
		lazy[i] = 0;
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
		st[i] = A[L];
	else
	{
		int mid = (L+R)/2;
		st_init_helper(LT(i), L, mid);
		st_init_helper(RT(i), mid+1, R);
		st[i] = st[LT(i)] + st[RT(i)];
	}
}

void st_init(const vector<int> &_A)
{
	A = _A;
	N = A.size();
	st.assign(N*4, 0);
	lazy.assign(N*4, 0);
	st_init_helper(0, 0, N-1);
}

int main()
{
	st_init({2, 2, 4, 4, 4, 4, 1, 3, 3, 3});
	cout << st_rq(0, 9) << endl;
	st_ru(0, 0, 3);
	cout << st_rq(0, 9) << endl;
	st_ru(0, 8, 3);
	cout << st_rq(0, 9) << endl;
}

