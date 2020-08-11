#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int main()
{
	int N;
	cin >> N;
	int count = 0;
	for (int n = 0; n < N; n++)
	{
		int next;
		cin >> next;
		while (next % 2 == 0)
		{
			count += 1;
			next /= 2;
		}
	}
	cout << count << endl;
}

