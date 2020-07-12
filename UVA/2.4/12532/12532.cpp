#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SegmentTree 
{
private:
	vector<int> st, A; int N;
	int LT(int i) { return i*2; }
	int RT(int i) { return i*2 + 1; }

	// O(N)
	void build(int i, int L, int R)
	{
		if (L == R)
			st[i] = A[L];
		else
		{
			build(LT(i), L, (L+R)/2);
			build(RT(i), (L+R)/2+1, R);
			int r1 = st[LT(i)], r2 = st[RT(i)];
			st[i] = r1 * r2;
		}
	}

	// O(log N)
	int rq(int i, int L, int R, int a, int b)
	{
		if (a > R || b < L) return -1000;
		if (L >= a && R <= b) return st[i];
		int r1 = rq(LT(i), L, (L+R)/2, a, b);
		int r2 = rq(RT(i), (L+R)/2+1, R, a, b);
		if (r1 == -1000) return r2;
		if (r2 == -1000) return r1;
		return r1 * r2;
	}

	void update(int i, int L, int R, int a, int v)
	{
		if (L == R)
		{
			A[a] = v;
			st[i] = v;
		}
		else
		{
			if (a >= L && a <= (L+R)/2) update(LT(i), L, (L+R)/2, a, v);
			else update(RT(i), (L+R)/2+1, R, a, v);
			int r1 = st[LT(i)], r2 = st[RT(i)];
			st[i] = r1 * r2;
		}
	}

public:
	SegmentTree(const vector<int> &_A)
	{
		A = _A;
		N = (int) A.size();
		st.assign(4*N, 0);
		build(1, 0, N-1);
	}

	int rq(int a, int b) { return rq(1, 0, N-1, a, b); }
	
	void update(int a, int v) { update(1, 0, N-1, a, v); }
};

int main()
{
	int N, K;
	while (scanf("%d %d\n", &N, &K) != EOF)
	{
		string s;
		vector<int> seq(N);
		for (int i = 0; i < N; i++)
		{
			cin >> seq[i];
			if (seq[i] < 0) seq[i] = -1;
			else if (seq[i] > 0) seq[i] = 1;
		}

		SegmentTree st(seq);
		for (int k = 0; k < K; k++)
		{
			char c; int a, b;
			cin >> c >> a >> b;
			if (c == 'C')
			{
				if (b != 0) b = b/abs(b);
				st.update(a-1, b);
			}
			else if (c == 'P')
			{
				int ans = st.rq(a-1, b-1);
				if (ans == 0) cout << "0";
				if (ans == 1) cout << "+";
				if (ans == -1) cout << "-";
			}
		}
		cout << endl;
	}
}
