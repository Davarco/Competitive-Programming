#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int N;

bitset<16> visited;
vector<int> circle(16);

bool is_prime(int x)
{
	for (int i = 2; i*i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

void find(int a)
{
	if (a == N)
	{
		if (is_prime(circle[0] + circle[N-1]))
			for (int i = 0; i < N; i++) 
				if (i != N-1) cout << circle[i] << " ";
				else cout << circle[i] << endl;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (!visited[i] && is_prime(circle[a-1] + i+1))
			{
				visited[i] = true;
				circle[a] = i+1;
				find(a+1);
				visited[i] = false;
			}
		}
	}
}

int main()
{
	int C = 0;
	bool flag = true;
	while (cin >> N)
	{
		if (flag)
			flag = false;
		else
			cout << endl;
		printf("Case %d:\n", ++C);
		visited[0] = true;
		circle[0] = 1;
		find(1);
	}
}
