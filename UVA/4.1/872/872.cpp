#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <set>

using namespace std;

int T;
int visited[256];
vector<char> var;
vector<char> con[256];
vector<int> now;
bool success;

void dfs(int i)
{
	now.push_back(i);
	visited[var[i]] = true;

	if (now.size() == var.size())
	{
		for (int n = 0; n < now.size()-1; n++)
			printf("%c ", var[now[n]]); printf("%c\n", var[now[now.size()-1]]);
		success = true;
	}

	for (int n = 0; n < var.size(); n++)
		if (!visited[var[n]])
		{
			bool flag = true;
			for (int m = 0; m < con[var[n]].size(); m++)
				if (!visited[con[var[n]][m]])
					{ /* printf("%c\n", con[var[n]][m]); */ flag = false; break; }
			if (flag)
			{
			//	printf("try %c\n", var[n]);
				dfs(n);
			}
			else
			{
			//	printf("notry %c\n", var[n]);
			}
		}

	visited[var[i]] = false;
	now.pop_back();
}

int main()
{
	stringstream ss; string in; char a, b, c;
	getline(cin, in); ss.clear(); ss.str(in);
	ss >> T;
	for (int t = 0; t < T; t++)
	{
		for (int i = 0; i < 256; i++) visited[i] = false; success = false;
		var.clear(); for (int i = 0; i < 256; i++) con[i].clear();
		getline(cin, in); getline(cin, in); ss.clear(); ss.str(in);
		while (ss >> c) var.push_back(c);
		getline(cin, in); ss.clear(); ss.str(in);
		while (ss >> a >> b >> c) con[c].push_back(a);

		for (int i = 0; i < var.size(); i++)
			if (con[var[i]].size() == 0)
				dfs(i);
		if (!success) 
			cout << "NO" << endl;
		if (t != T-1)
			cout << endl;
	}
}
