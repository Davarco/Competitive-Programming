#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class SegmentTree 
{
private:
	vector<int> st, A; int N;
	int LT(int i) { return (i << 1); }
	int RT(int i) { return (i << 1) + 1; }

	// O(N)
	void build(int i, int L, int R)
	{
		if (L == R)
			st[i] = A[L];
		else
		{
			build(LT(i), L, (L+R)/2);
			build(RT(i), (L+R)/2+1, R);
			int a = st[LT(i)], b = st[RT(i)];
			st[i] = a + b;
		}
	}

	// O(log N)
	int rq(int i, int L, int R, int a, int b)
	{
		if (a > R || b < L) return -1;
		if (L >= a && R <= b) return st[i];
		int r1 = rq(LT(i), L, (L+R)/2, a, b);
		int r2 = rq(RT(i), (L+R)/2+1, R, a, b);
		if (r1 == -1) return r2;
		if (r2 == -1) return r1;
		return r1 + r2;
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
			int a = st[LT(i)], b = st[RT(i)];
			st[i] = a + b;
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
	
	int update(int a, int v) { update(1, 0, N-1, a, v); }
};

int S, D;

int main()
{
	while (cin >> S >> D)
	{
		int best = -1;
		for (int i = 0; i < (1 << 12); i++)
		{
			vector<int> data(12);
			for (int b = 0; b < 12; b++)
				if ((i >> b) & 1)
					data[b] = S;
				else
					data[b] = -D;
			SegmentTree st(data);
			bool flag = true;
			for (int end = 4; end < 12; end++)
			{
				int q = st.rq(end-4, end);
				if (q > 0) 
				{
					flag = false;
					break;
				}
			}
			if (flag && st.rq(0, 11) > best)
				best = st.rq(0, 11);
		}
		if (best == -1) cout << "Deficit" << endl;
		else cout << best << endl;
	}
}
