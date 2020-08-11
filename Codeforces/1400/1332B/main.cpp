#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N;
vi primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31 };

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi seq(N);
		for (int n = 0; n < N; n++)
			cin >> seq[n];

		vi colors(N);
		vi um(11, -1);
		int idx = 0;
		for (int i = 0; i < seq.size(); i++)
		{
			for (int p = 0; p < 11; p++)
				if (seq[i] % primes[p] == 0)
				{
					if (um[p] == -1)
						um[p] = ++idx;
					colors[i] = um[p];
					break;
				}
		}
		int count = 0;
		for (int i = 0; i < 11; i++)
			if (um[i] != -1)
				count++;
		cout << count << endl;
		for (int i = 0; i < seq.size(); i++)
			cout << colors[i] << (i == colors.size() - 1 ? '\n' : ' ');
	}
}

