#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	bool flag = false;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
			break;

		while (true)
		{
			int temp;
			queue<int> A;
			stack<int> B;
			queue<int> order;
			cin >> temp;
			if (temp == 0)
				break;

			order.push(temp);	
			for (int i = 1; i < N; i++)
			{
				cin >> temp;
				order.push(temp);
			}
			for (int i = 0; i < N; i++)
				A.push(i+1);

			stack<int> station;
			while (true)
			{
				if (order.size() == 0)
					break;
				else if (station.size() > 0 && station.top() == order.front())
				{
					B.push(station.top());
					station.pop();
					order.pop();
				}
				else if (A.size() > 0)
				{
					station.push(A.front());
					A.pop();
				}
				else 
				{
					cout << "No" << endl;
					break;
				}
			}
			if (B.size() == N)
				cout << "Yes" << endl;
		}
		cout << endl;
	}
}
