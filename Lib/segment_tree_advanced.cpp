// Modified from Competitive Programming 3.
#include <iostream>
#include <vector>

using namespace std;

// Perform Range Min/Max/Sum Queries, the index of the smallest number between 
// two indices in a list of numbers.
class SegmentTree 
{
private:
	vector<int> st, A, lazy;
	int N;

	int l(int p) { return p << 1; }

	int r(int p) { return (p << 1) + 1; }

	int conquer(int a, int b)
	{
		if (a == -1) return b;
		if (b == -1) return a;
		return min(a, b);
	}

	void propogate(int p, int L, int R)
	{
		if (lazy[p] != -1)
		{
			st[p] = lazy[p];
			if (L != R)
				lazy[l(p)] = lazy[r(p)] = lazy[p];
			else
				A[L] = lazy[p];
			lazy[p] = -1;
		}
	}

	// O(N)
	void build(int p, int L, int R)
	{
		if (L == R)
		{
			st[p] = A[L];
		}
		else
		{
			build(l(p), L, (L+R)/2);
			build(r(p), (L+R)/2+1, R);
			st[p] = conquer(st[l(p)], st[r(p)]);
		}
	}

	// O(log N)
	int rmq(int p, int L, int R, int i, int j)
	{
		propogate(p, L, R);
		if (i > R || j < L) return -1;
		if (L >= i && R <= j) return st[p];
		int m = (L+R)/2;
		int p1 = rmq(l(p), L, m, i, min(m, j));
		int p2 = rmq(r(p), m+1, R, max(i, m+1), j);
		return conquer(p1, p2);
	}

	// O(log N)
	void update(int p, int L, int R, int i, int j, int val)
	{
		propogate(p, L, R);
		if (i > j) return;
		if (L >= i || R <= j)
		{
			lazy[p] = val;
			propogate(p, L, R);
		}
		else
		{
			int m = (L+R)/2;
			update(l(p), L, m, i, min(m, j), val);
			update(r(p), m+1, R, max(i, m+1), j, val);
			int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
			int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
			st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
		}
	}

public:
	SegmentTree(const vector<int> &_A)
	{
		A = _A;
		N = (int) A.size();
		st.assign(4*N, 0);
		lazy.assign(4*N, -1);
		build(1, 0, N-1);
	}

	int rmq(int i, int j) { return rmq(1, 0, N-1, i, j); }

	void update(int i, int j, int val) { update(1, 0, N-1, i, j, val); }
};

int main()
{
	SegmentTree st({18, 17, 13, 19, 15, 11, 20});
	cout << st.rmq(3, 4) << endl;
	cout << st.rmq(1, 3) << endl;
	cout << st.rmq(4, 6) << endl;
}
