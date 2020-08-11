#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef pair<string, int> si;
typedef vector<si> vsi;

#define INF 100000000

int T, N;

int main()
{
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> N;
		string S;
		cin >> S;

		string best = S; int best_k = 0;
		for (int k = 1; k < N; k++)
		{
			string next = S.substr(k, N-k), temp = next;
			if ((k+1) % 2 == N % 2)
				for (int i = k-1; i >= 0; i--)
					next += S[i];
			else
				for (int i = 0; i < k; i++)
					next += S[i];
			if (next.compare(best) < 0)
				best = next, best_k = k;
		}
		cout << best << endl;
		cout << (best_k+1) << endl;
	}
}

