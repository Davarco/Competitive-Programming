#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

LL N, D, E;

int main()
{
	cin >> N >> D >> E;
	/*
	vector<LL> USD = { 1, 2, 5 };
	vector<LL> RUS = { 5 };
	vector<LL> CON;
	for (int i = 0; i < USD.size(); i++)
		CON.push_back(USD[i] * D);
	for (int i = 0; i < RUS.size(); i++)
		CON.push_back(RUS[i] * E);
	sort(CON.begin(), CON.end(), greater<LL>());

	vi choices;
	for (int i = 0; i < (1 << 4); i++)
	{
		LL n = N;
		for (int a = 0; a < 4; a++)
			if ((i >> a) & 1 == 1 && n >= CON[a])
				n = n % CON[a];	
		choices.push_back(n);	
	}
	*/
	LL a = D;
	LL b = 5 * E;
	LL ans = LLONG_MAX;
	for (int i = 0; i*D <= N; i++)
		ans = min(ans, N - i*a - (N-i*a)/b*b);
	cout << ans << endl;
}

