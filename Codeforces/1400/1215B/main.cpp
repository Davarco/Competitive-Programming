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

int N;

signed main()
{
	cin >> N;
	vi A(N);
	for (int n = 0; n < N; n++)
		cin >> A[n], A[n] = (A[n] < 0 ? -1 : 1);

	int P = 0, negative = 0, even = 0, odd = 0;
	for (int n = 0; n < N; n++)
	{
		if (negative % 2 == 0)
			even++;
		else
			odd++;
		if (A[n] < 0)
			negative++;
		if (negative % 2 == 0)
			P += even;
		else
			P += odd;
	}
	cout << N*(N+1)/2-P << " " << P << endl;
}

