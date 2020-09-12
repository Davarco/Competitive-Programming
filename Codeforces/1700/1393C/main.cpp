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

int T, N;

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

		int a = 0, b = N;
		while (b - a > 1)
		{
			int m = (a + b) / 2;
			
			unordered_map<int, int> count;
			for (int n = 0; n < N; n++)
				count[A[n]]++;

			set<ii, greater<ii>> s;
			for (auto it = count.begin(); it != count.end(); it++)
				s.insert(ii(it->second, it->first));

			vector<int> v;
			bool works = true;
			for (int n = 0; n < N; n++)
			{
				if (n >= m && count[v[n-m]] > 0)
					s.insert(ii(count[v[n-m]], v[n-m]));
				if (s.size() == 0)
				{
					works = false;
					break;
				}
				v.push_back(s.begin()->second);
				s.erase(s.begin());
				count[v.back()]--;
			}

			if (works)
				a = m;
			else
				b = m;
		}
		cout << a-1 << endl;
	}
}

