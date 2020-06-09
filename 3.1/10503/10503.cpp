#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef pair<int, int> pii;

int N, M; 
pii first, last;
vector<pii> board, dominos;

vector<char> used;

bool solution(int a)
{
	if (a == 0)
	{
		for (int i = 0; i < M; i++)
			if (first.second == dominos[i].first && !used[i])
			{
				board[a] = dominos[i];
				used[i] = true;
				bool worked = solution(a+1);
				used[i] = false;
				if (worked) return true;
			}
			else if (first.second == dominos[i].second && !used[i])
			{
				board[a] = make_pair(dominos[i].second, dominos[i].first);
				used[i] = true;
				bool worked = solution(a+1);
				used[i] = false;
				if (worked) return true;
			}
	}
	else if (a == N-1)
	{
		for (int i = 0; i < M; i++)
			if (board[a-1].second == dominos[i].first && dominos[i].second == last.first && !used[i])
			{
				board[a] = dominos[i];
				return true;
			}
			else if (board[a-1].second == dominos[i].second && dominos[i].first == last.first && !used[i])
			{
				board[a] = make_pair(dominos[i].second, dominos[i].first);
				return true;
			}
	}
	else
	{
		for (int i = 0; i < M; i++)
			if (board[a-1].second == dominos[i].first && !used[i])
			{
				board[a] = dominos[i];
				used[i] = true;
				bool worked = solution(a+1);
				used[i] = false;
				if (worked) return true;
			}
			else if (board[a-1].second == dominos[i].second && !used[i])
			{
				board[a] = make_pair(dominos[i].second, dominos[i].first);
				used[i] = true;
				bool worked = solution(a+1);
				used[i] = false;
				if (worked) return true;
			}
	}
	return false;
}

int main()
{
	while (cin >> N)
	{
		if (N == 0) break;
		cin >> M;
		int a, b, c, d; cin >> a >> b >> c >> d;
		first = make_pair(a, b); last = make_pair(c, d);
		board.resize(N); dominos.resize(M);
		for (int m = 0; m < M; m++)
		{
			cin >> a >> b;
			dominos[m] = make_pair(a, b);
		}
		
		used.assign(M, false);
		bool found = solution(0);
		if (found) 
			cout << "YES" << endl;
		else 
			cout << "NO" << endl;
	}
}
