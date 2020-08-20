#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define int LL
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000
#define PLIST(a, b) \
	for (int i = 0; i < b; i++) cout << a[i] << (i == b-1 ? '\n' : ' ');
#define PLIST2(a, b) \
	for (int i = 0; i < b; i++) cout << a << (i == b-1 ? '\n' : ' ');

int T, N;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		vi A(N);
		for (int n = 0; n < N; n++)
			cin >> A[n];
		
		int negative = A[0] < 0, sum = 0, i = 0, best = negative*INT_MIN;
		while (i < N)
		{
			if (negative && A[i] < 0)
				best = max(best, A[i]);
			else if (negative) 
				negative = false, sum += best, best = A[i];
			else if (!negative && A[i] > 0)
				best = max(best, A[i]);
			else if (!negative)
				negative = true, sum += best, best = A[i];
			i++;
		}
		cout << sum + best << endl;
	}
}

