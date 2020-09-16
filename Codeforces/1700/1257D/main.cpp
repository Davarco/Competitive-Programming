#include <bits/stdc++.h>
/*
 * Basic Runtimes Table:
 * +-----+-----------------+
 * |  n  | Worst Algorithm |
 * +-----+-----------------+
 * | 11  | O(n!), O(n^6)   |
 * | 18  | O(2^n * n^2)    |
 * | 22  | O(2^n * n)      |
 * | 100 | O(n^4)          |
 * | 400 | O(n^3)          |
 * | 2K  | O(n^2 log n)    |
 * | 10K | O(n^2)          |
 * | 1M  | O(n log n)      |
 * +-----+-----------------+
 *
 * Lower Bound: First >=, Upper Bound: First >
 */
using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define endl '\n'
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T, N, M;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];

		cin >> M;
		vii SP(M);
		for (int m = 0; m < M; m++)
		{
			int p, s;
			cin >> p >> s;
			SP[m] = ii(s, p);
		}
		sort(SP.begin(), SP.end(), greater<ii>());

		map<int, int> temp;
		for (int m = 0; m < M; m++)
		{
			int s = SP[m].first, p = SP[m].second;
			auto it = temp.lower_bound(s);
			if (it == temp.end() || p > it->second)
				temp[s] = p;
		}

		map<int, int> heroes;
		for (auto it = temp.begin(); it != temp.end(); it++)
			heroes[it->second] = it->first;

		int n = 0, cnt = 0, works = true;
		while (n < N)
		{
			cnt++;
			int pre = n, lar = -INF;
			while (true)
			{
				lar = max(lar, A[n]);
				auto it = heroes.lower_bound(lar);
				if (it == heroes.end() || n-pre+1 > it->second)
					break;
				n++;
			}
			if (pre == n)
			{
				works = false;
				break;
			}
		}
		if (works)
			cout << cnt << endl;
		else
			cout << -1 << endl;
	}
}

