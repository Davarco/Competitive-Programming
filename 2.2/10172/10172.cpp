#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void fill(queue<int> &B, int q)
{
	int temp; 
	cin >> temp;
	if (q == 1)
	{
		B.push(temp);
	}
	else
	{
		fill(B, q-1);
		B.push(temp);
	}
}

int main()
{
	int SET;
	scanf("%d\n", &SET);

	for (int s = 0; s < SET; s++)
	{
		int N, S, Q;
		scanf("%d %d %d\n", &N, &S, &Q);

		int count = 0;

		vector<queue<int>> B(N);
		for (int i = 0; i < N; i++)
		{
			int q;
			cin >> q;
			for (int j = 0; j < q; j++)
			{
				int temp;
				cin >> temp;
				B[i].push(temp);
			}
			count += q;
		}

		int i = 0;
		int t = 0;
		stack<int> carrier;
		if (count == 0)
		{
			cout << 0 << endl;
		}
		else 
		{
			while (count > 0)
			{
				while (carrier.size() != 0 && (carrier.top() == i+1 || B[i].size() < Q))
				{
					if (carrier.top() != i+1)
						B[i].push(carrier.top());
					else
						count -= 1;
					carrier.pop();
					t += 1;
				}

				while (B[i].size() > 0 && carrier.size() < S) 
				{
					carrier.push(B[i].front());
					B[i].pop();
					t += 1;
				}

				i = (i+1) % N;
				t += 2;
			}
			cout << t-2 << endl;
		}
	}
}
