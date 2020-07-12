#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool is_stack = true, is_queue = true, is_pq = true;

		for (int i = 0; i < N; i++)
		{
			int a, b;
			cin >> a >> b;
			if (a == 1)
			{
				if (is_stack)
					s.push(b);
				if (is_queue)
					q.push(b);
				if (is_pq)
					pq.push(b);
			}
			else if (a == 2)
			{
				if (is_stack)
				{
					if (s.size() == 0 || s.top() != b)
						is_stack = false;
					else
						s.pop();
				}
				if (is_queue)
				{
					if (q.size() == 0 || q.front() != b)
						is_queue = false;
					else
						q.pop();
				}
				if (is_pq)
				{
					if (pq.size() == 0 || pq.top() != b)
						is_pq = false;
					else
						pq.pop();
				}
			}
		}

		if (is_stack && !is_queue && !is_pq)
			cout << "stack" << endl; 
		else if (!is_stack && is_queue && !is_pq)
			cout << "queue" << endl;
		else if (!is_stack && !is_queue && is_pq)
			cout << "priority queue" << endl;
		else if (!is_stack && !is_queue && !is_pq)
			cout << "impossible" << endl;
		else 
			cout << "not sure" << endl;
	}
}
