#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <queue>
#include <stack>

using namespace std;

int N;
vector<int> A;

int main()
{
	int next;
	while (cin >> next) A.push_back(next); 
	N = A.size();

	vector<int> dp(N);
	vector<int> id(N);
	vector<int> prev(N);
	int size = 0;
	int biggest_size = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		int a = 0, b = size;
		while (a < b)
		{
			int m = (a+b)/2;
			if (dp[m] == A[i])
			{
				a = m;
				break;
			}
			else if (dp[m] < A[i])
				a = m+1;
			else 
				b = m;
		}
		dp[a] = A[i];
		id[a] = i;
		prev[i] = a > 0 ? id[a-1] : -1;
		if (a == size) 
			size = a+1;
		if (a >= biggest_size)
		{
			biggest_size = a;	
			end = i;
		}
	}
	cout << size << endl << "-" << endl;
	stack<int> s;
	while (end != -1)
	{
		s.push(A[end]);
		end = prev[end];
	}
	while (s.size() > 0)
	{
		cout << s.top() << endl;
		s.pop();
	}
}

