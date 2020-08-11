#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int N;

int main()
{
	cin >> N;
	vi seq(N);
	for (int n = 0; n < N; n++)
		cin >> seq[n];

	int best = 0;
	for (int a = 0; a < N; a++)
	{
		int sum = 0, count = 0;
		for (int b = a; b < N; b++)
		{
			sum += seq[b];
			count++;
			if (sum > count*100)
				best = max(best, count);
		}
	}
	cout << best << endl;
}

