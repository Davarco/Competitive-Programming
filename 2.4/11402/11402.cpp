#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int T; cin >> T;
	for (int t = 0; t < T; t++)
	{
		string pirates = "";
		int M; cin >> M;
		for (int m = 0; m < M; m++)
		{
			string s; cin >> s;
			int C; cin >> C;
			for (int c = 0; c < C; c++) pirates += s;
		}

		int Q; cin >> Q;
		for (int q = 0; q < Q; q++)
		{
			char c; int a, b; cin >> c >> a >> b;
		}
	}
}
