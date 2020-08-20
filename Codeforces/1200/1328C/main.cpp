#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
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
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S;
		string a = "", b = "";
		bool used = false;
		for (int s = 0; s < N; s++)
		{
			if (used)
				a += '0', b += S[s];
			else
				if (S[s] == '1')
					a += '1', b += '0', used = true;
				else if (S[s] == '2')
					a += '1', b += '1';
				else if (S[s] == '0')
					a += '0', b += '0';
		}
		cout << a << endl;
		cout << b << endl;
	}
}

