#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

int T, N;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N >> S;

		string A = "";
		int a = 0;
		for (; a < N; a++)
			if (S[a] == '0')
				A += '0';
			else
				break;

		string B = "";
		int b = N-1;
		for (; b >= 0; b--)
			if (S[b] == '1')
				B += '1';
			else
				break;

		string C = "";
		char past = '0';
		for (; a <= b; a++)
			if (S[a] == '1' && past == '0')
			{
				C += '0';
				break;
			}
		cout << A + C + B << endl;
	}
}

