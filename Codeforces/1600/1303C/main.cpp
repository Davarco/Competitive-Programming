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
#define PLIST(a, b) \
	for (int sad = 0; sad < (int)(b); sad++) cout << a[sad] << (sad == (int)(b)-1 ? '\n' : ' ');

int T;
string S;

signed main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> S;

		deque<char> board;
		board.push_back(S[0]);

		int found = true;
		for (int i = 0; i < S.size()-1; i++)
		{
			char a = S[i], b = S[i+1];
			int p = -1, n = -1;
			for (int i = 0; i < board.size(); i++)
				if (a == board[i])
					p = i;
				else if (b == board[i])
					n = i;
			if (n == -1)
			{
				if (p == 0)
					board.push_front(b);
				else if (p == board.size()-1)
					board.push_back(b);
				else
				{
					found = false;
					break;
				}
			}
			else if (abs(p-n) != 1)
			{
				found = false;
				break;
			}
		}
		if (found)
		{
			cout << "YES" << endl;
			vi used(26);
			for (int i = 0; i < board.size(); i++)
				cout << board[i], used[board[i]-'a'] = true;
			for (int i = 0; i < 26; i++)
				if (!used[i])
					cout << char(i+'a');
			cout << endl;
		}
		else
			cout << "NO" << endl;
	}
}

