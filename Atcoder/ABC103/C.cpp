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
	vi seq(N);
	for (int n = 0; n < N; n++)
		cin >> seq[n];

	int sum = 0;
	for (int n = 0; n < N; n++)
		sum += seq[n] - 1;
	cout << sum << endl;
}

