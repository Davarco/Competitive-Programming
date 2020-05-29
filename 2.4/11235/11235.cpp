#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <map>

using namespace std;

#define NEG 100000
int bounds[200001];


// Perform Range Min/Max/Sum Queries, the index of the smallest number between 
// two indices in a list of numbers.
//
// 0-indexed.
class SegmentTree 
{
public:
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
		{
			st[p] = L; 
			// printf("Equal: %d %d %d\n", L, R, A[st[p]]);
		}
		else
		{
			build(left(p), L, (L+R)/2);
			build(right(p), (L+R)/2+1, R);
			int p1 = st[left(p)], p2 = st[right(p)];
			st[p] = A[p1] > A[p2] ? p1 : p2; 
			// printf("Sum: %d %d %d\n", L, R, A[st[p]]);
		}
	}

	// O(log N)
	int rmq(int p, int L, int R, int i, int j)
	{
		if (i > R || j < L)
			return -1;
		// printf("RMQ: %d %d\n", L, R);
		if (L >= i && R <= j) 
			return st[p];
		int p1 = rmq(left(p), L, (L+R)/2, i, j);
		int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
		if (p1 == -1) 
			return p2;
		if (p2 == -1)
			return p1;
		return A[p1] > A[p2] ? p1 : p2;
	}

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
	while (true)
	{
		int N; cin >> N;
		if (N == 0) break;
		int Q; cin >> Q;

		int prev = INT_MIN;
		vector<int> A(N);
		vector<int> m0(200001, 0);
		for (int i = 0; i < N; i++)
		{
			cin >> A[i];
			m0[A[i]+NEG] += 1;
		}

		vector<int> counts(N);
		for (int i = 0; i < N; i++)
			counts[i] = m0[A[i]+NEG];

		SegmentTree sg(counts);
		for (int i = 0; i < Q; i++)
		{
			int b, c;
			cin >> b >> c; b -= 1; c -= 1;

			int case2 = counts[sg.rmq(b, c)];
		}
	}
}



