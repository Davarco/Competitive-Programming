#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 1000000000

int T, N, X;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> X;
		vi seq(N);
		for (int n = 0; n < N; n++)
			cin >> seq[n];
		sort(seq.begin(), seq.end(), greater<int>());
		int count = 0, worst = INT_MAX, teams = 0;
		for (int i = 0; i < seq.size(); i++)
		{
			count++;
			worst = min(worst, seq[i]);
			if (worst*count >= X)
			{
				teams++;
				count = 0;
				worst = INT_MAX;
			}
		}
		cout << teams << endl;
	}
}

