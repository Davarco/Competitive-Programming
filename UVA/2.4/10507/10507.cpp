#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		int M;
		scanf("%d\n", &M);
		
		char t0, t1, t2;
		scanf("%c%c%c\n", &t0, &t1, &t2);
		int a = t0 - 'A', b = t1 - 'A', c = t2 - 'A';
		
		vi m(26, -1);
		m[a] = 0;
		m[b] = 1;
		m[c] = 2;
		int index = 3;
		// cout << t0 << " " << 0 << endl;
		// cout << t1 << " " << 1 << endl;
		// cout << t2 << " " << 2 << endl;

		vector<vi> edges(N);

		for (int i = 0; i < M; i++)
		{
			scanf("%c%c\n", &t0, &t1);
			a = t0 - 'A';
			b = t1 - 'A';
			if (m[a] == -1)
			{
				m[a] = index;
				// cout << t0 << " " << index << endl;
				index += 1;
			}
			if (m[b] == -1)
			{
				m[b] = index;
				// cout << t1 << " " << index << endl;
				index += 1;
			}

			edges[m[a]].push_back(m[b]);
			edges[m[b]].push_back(m[a]);
		}

		vector<bool> on(N, false);
		int on_number = 3;
		int prev_on_number = -1;
		on[0] = true;
		on[1] = true;
		on[2] = true;
		int count = 0;
		while (on_number != N && on_number != prev_on_number)
		{
			prev_on_number = on_number;
			vector<int> new_on;
			for (int i = 0; i < edges.size(); i++)
			{
				if (on[i])
					continue;
				int adjacent = 0;
				for (int j = 0; j < edges[i].size(); j++)
					if (on[edges[i][j]])
						adjacent += 1;
				if (adjacent >= 3)
				{
					new_on.push_back(i);
					on_number += 1;
				}
			}
			for (int j = 0; j < new_on.size(); j++)
				on[new_on[j]] = true;
			count += 1;
		}
		if (on_number == prev_on_number) 
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		else
			printf("WAKE UP IN, %d, YEARS\n", count);

		scanf("\n");
	}
}


