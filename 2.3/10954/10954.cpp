#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef long long bigint;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		if (N == 0)
			break;
		priority_queue<bigint, vector<bigint>, greater<bigint>> pq;
		for (int i = 0; i < N; i++)
		{
			bigint number;
			cin >> number;
			pq.push(number);
		}

		bigint sum = 0;
		for (int i = 0; i < N-1; i++)
		{
			bigint first = pq.top();
			pq.pop();
			bigint second = pq.top();
			pq.pop();

			sum += first + second;
			pq.push(first + second);
		}
		cout << sum << endl;
	}
}
