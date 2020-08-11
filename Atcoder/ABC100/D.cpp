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
	int N, M;
	cin >> N >> M;

	priority_queue<LL> pq[8];
	for (int n = 0; n < N; n++)
	{
		LL a, b, c;
		cin >> a >> b >> c;
		pq[0].push(a + b + c);
		pq[1].push(a + b - c);
		pq[2].push(a - b - c);
		pq[3].push(a - b + c);
		pq[4].push(-a + b + c);
		pq[5].push(-a + b - c);
		pq[6].push(-a - b - c);
		pq[7].push(-a - b + c);
	}
	LL sum[8];
	memset(sum, 0, sizeof(sum));
	for (int m = 0; m < M; m++)
	{
		for (int n = 0; n < 8; n++)
		{
			sum[n] += pq[n].top();
			pq[n].pop();
		}
	}
	LL best = LLONG_MIN;
	for (int n = 0; n < 8; n++)
		best = max(sum[n], best);
	cout << best << endl;
}

