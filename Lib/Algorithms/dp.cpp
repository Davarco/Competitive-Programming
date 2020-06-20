#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

typedef vector<vector<int>> vvi;

// O(N), Kadane's Algorithm
void max_1d_range_sum()
{
	vector<int> A({ -2, -3, 4, -1, -2, 1, 5, -3 });
	int N = A.size();

	int sum = 0, ans = 0;
	for (int i = 0; i < N; i++)
	{
		sum += A[i];
		ans = max(ans, sum);
		if (sum < 0) sum = 0;
	}
	cout << ans << endl;
}

// O(N^4) 
void max_2d_range_sum()
{
	vvi A({{ 0, -2, -7, 0 }, { 9, 2, -6, 2 }, { -4, 1, -4, 1 }, { -1, 8, 0, -2 }});
	int N = 4;

	for (int r = 0; r < N; r++) for (int c = 0; c < N; c++)
	{
		if (r > 0) A[r][c] += A[r-1][c];
		if (c > 0) A[r][c] += A[r][c-1];
		if (r > 0 && c > 0) A[r][c] -= A[r-1][c-1];
	}

	int ans = INT_MIN;
	for (int r0 = 0; r0 < N; r0++) for (int c0 = 0; c0 < N; c0++)
		for (int r1 = r0; r1 < N; r1++) for (int c1 = c0; c1 < N; c1++)
		{
			int subrect = A[r1][c1];
			if (r0 > 0) subrect -= A[r0-1][c1];
			if (c0 > 0) subrect -= A[r1][c0-1];
			if (r0 > 0 && c0 > 0) subrect += A[r0-1][c0-1];
			ans = max(ans, subrect);
		}
	cout << ans << endl;
}

// O(N^2), but a O(N log N) solution exists
void longest_increasing_subsequence()
{
	vector<int> A({ -7, -9, 10, 9, 2, 3, 8, 8, 1 });
	int N = A.size();

	vector<int> LIS(N);

	LIS[0] = 1;
	for (int i = 1; i < N; i++)
	{
		LIS[i] = 1;
		for (int j = 0; j < i; j++)
			if (A[j] < A[i] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1;
	}
	
	int best = *max_element(LIS.begin(), LIS.end());
	cout << best << endl;
}

// O(NS), also known as the subset sum problem
int knapsack[100][100];
vector<int> knapsack_V({ 100, 70, 50, 10 });
vector<int> knapsack_W({ 10, 4, 6, 12 });

int knapsack_01_search(int id, int rem_weight)
{
	if (rem_weight == 0 || id == knapsack_V.size())
		return 0;

	if (knapsack[id][rem_weight] == -1)
	{
		if (knapsack_W[id] > rem_weight)
			knapsack[id][rem_weight] = knapsack_01_search(id+1, rem_weight);
		else
		{
			int a = knapsack_V[id] + knapsack_01_search(id+1, rem_weight-knapsack_W[id]);
			int b = knapsack_01_search(id+1, rem_weight);
			knapsack[id][rem_weight] = max(a, b);
		}
	}
	return knapsack[id][rem_weight];
}

void knapsack_01()
{
	int N = 4, S = 12;	
	memset(knapsack, -1, sizeof(knapsack));

	int best = knapsack_01_search(0, S);
	cout << best << endl;
}

// O(NV)
void coin_change()
{
	int N = 2, V = 10;
	vector<int> denom({ 1, 5 });

	vector<int> change(V+1, INT_MAX);
	
	change[0] = 0;
	for (int v = 1; v <= V; v++)
		for (int n = 0; n < N; n++)
			if (v-denom[n] >= 0 && change[v-denom[n]] != INT_MAX)
				change[v] = min(change[v], change[v-denom[n]]+1);

	int ans = change[V];
	cout << ans << endl;
}

int main()
{
	max_1d_range_sum();
	max_2d_range_sum();
	longest_increasing_subsequence();
	knapsack_01();
	coin_change();
}

