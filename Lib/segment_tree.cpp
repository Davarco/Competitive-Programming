// Modified from Competitive Programming 3.
#include <iostream>
#include <vector>

using namespace std;

// Perform Range Min Queries, the index of the smallest number between two 
// indices in a list of numbers.
class SegmentTree 
{
private:
	vector<int> st, A;
	int N;

	int left(int p) 
	{
		return p << 1;
	}

	int right(int p)
	{
		return (p << 1) + 1;
	}

	// O(N)
	void build(int p, int L, int R)
	{
		if (L == R)
			st[p] = L;
		else
		{
			build(left(p), L, (L+R)/2);
			build(right(p), (L+R)/2+1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = A[p1] <= A[p2] ? p1 : p2;
		}
	}

	// O(log N)
	int rmq(int p, int L, int R, int i, int j)
	{
		if (i > R || j < L)
			return -1;
		if (L >= i && R <= j) 
			return st[p];
		int p1 = rmq(left(p), L, (L+R)/2, i, j);
		int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
		if (p1 == -1) 
			return p2;
		if (p2 == -1)
			return p1;
		return A[p1] <= A[p2] ? p1 : p2;
	}

public:
	SegmentTree(const vector<int> &_A)
	{
		A = _A;
		N = (int) A.size();
		st.assign(4*N, 0);
		build(1, 0, N-1);
	}

	int rmq(int i, int j)
	{
		return rmq(1, 0, N-1, i, j);
	}
};

int main()
{
	SegmentTree st({18, 17, 13, 19, 15, 11, 20});
	cout << st.rmq(3, 4) << endl;
}
