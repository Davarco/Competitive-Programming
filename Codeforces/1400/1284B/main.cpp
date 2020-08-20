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

int N, M, S;

signed main()
{
	cin >> N;	
	vi lower, upper;
	int asc = 0, count = 0;
	for (int n = 0; n < N; n++)
	{
		cin >> M;
		int L = INT_MAX, U = INT_MIN, ascending = false;
		for (int m = 0; m < M; m++)
		{
			cin >> S;
			if (S > L) 
				ascending = true;
			L = min(L, S);
			U = max(U, S);	
		}
		if (ascending)
			asc++;
		else
			lower.push_back(L), upper.push_back(U);
	}
	sort(lower.begin(), lower.end());
	sort(upper.begin(), upper.end());
	count += asc * (2 * N - asc);
	for (int a = 0; a < lower.size(); a++)
	{
		int n = upper.end() - upper_bound(upper.begin(), upper.end(), lower[a]);
		count += n;
	}
	cout << count << endl;
}

