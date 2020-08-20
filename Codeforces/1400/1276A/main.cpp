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

int T;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> S;
		vi indexes;
		for (int i = 0; i < S.size();)
		{
			if (i + 5 <= S.size() && S.substr(i, 5) == "twone")
				indexes.push_back(i+2), i += 5;
			else if (i + 3 <= S.size() && S.substr(i, 3) == "two")
				indexes.push_back(i+1), i += 3;
			else if (i + 3 <= S.size() && S.substr(i, 3) == "one")
				indexes.push_back(i+1), i += 3;
			else 
				i++;
		}
		cout << indexes.size() << endl;
		if (indexes.size() == 0)
			cout << endl;
		for (int i = 0; i < indexes.size(); i++)
			cout << indexes[i]+1 << (i == indexes.size()-1 ? '\n' : ' ');
	}
}

