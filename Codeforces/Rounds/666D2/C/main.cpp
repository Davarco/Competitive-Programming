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
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define MOD 1000000007
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int N;
vi A;

signed main()
{
	ios_base::sync_with_stdio(false);

	cin >> N;
	A.assign(N, 0);
	for (int n = 0; n < N; n++)
		cin >> A[n];
	
	if (N >= 3)
	{
		cout << "1 1" << endl;
		cout << -A[0] << endl;

		int a = 1, b = N-1;
		vi nums0;
		for (int i = a; i <= b; i++)
		{
			/*
			int c = 0;
			while ((A[i] + c) % N != 0)
				c += N-1;
			*/
			int c = A[i] * (N-1);
			nums0.push_back(c);
		}
		cout << to_string(a+1) << " " << to_string(b+1) << endl;
		PLIST(nums0, nums0.size());

		cout << 1 << " " << N << endl;
		vi nums1;
		nums1.push_back(0);
		for (int i = 1; i <= N-1; i++)
			nums1.push_back(-(A[i] + nums0[i-1]));
		PLIST(nums1, nums1.size());
	}
	else if (N == 1)
	{
		cout << "1 1" << endl;
		cout << -A[0] << endl;
		cout << "1 1" << endl;
		cout << 0 << endl;
		cout << "1 1" << endl;
		cout << 0 << endl;
	}
	else
	{
		cout << "1 1" << endl;
		cout << -A[0] << endl;
		cout << "2 2" << endl;
		cout << -A[1] << endl;
		cout << "1 1" << endl;
		cout << 0 << endl;
	}
}

