#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T;
int N, K1, K2;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> K1 >> K2 >> S;
		
		int n = 0, m = 0;
		for (; n < N; n++)
		{
			int count = 0;
			while (S[n] == '1')
				count++, n++;
			if (count == 0)
				continue;
			else if (count == 1)
				m += K1;	
			else if (count % 2 == 0)
				m += (count/2) * K2;
			else if (count % 2 == 1)
				m += (count/2) * K2 + K1;
		}
		cout << m << endl;
	}
}

