#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int n = 0; n < N; n++)
	{
		int B, SG, SB;
		cin >> B >> SG >> SB;

		multiset<int, greater<int>> green, blue;
		for (int i = 0; i < SG; i++)
		{
			int g;
			cin >> g;
			green.insert(g);
		}	
		for (int i = 0; i < SB; i++)
		{
			int b;
			cin >> b;
			blue.insert(b);
		}

		while (green.size() > 0 && blue.size() > 0)
		{
			vector<int> green_veterans, blue_veterans;
			for (int i = 0; i < B && green.size() > 0 && blue.size() > 0; i++)
			{
				int g = *green.begin(), b = *blue.begin();
				if (g - min(g, b) != 0)
					green_veterans.push_back(g - min(g, b));
				if (b - min(g, b) != 0)
					blue_veterans.push_back(b - min(g, b));
				green.erase(green.begin());
				blue.erase(blue.begin());
			}
			for (int i = 0; i < green_veterans.size(); i++)
				green.insert(green_veterans[i]);
			for (int i = 0; i < blue_veterans.size(); i++)
				blue.insert(blue_veterans[i]);
		}
		if (green.size() == 0 && blue.size() == 0)
			cout << "green and blue died" << endl;
		else if (green.size() != 0)
		{
			cout << "green wins" << endl;
			for (auto it = green.begin(); it != green.end(); it++)
				cout << *it << endl;
		}
		else
		{
			cout << "blue wins" << endl;
			for (auto it = blue.begin(); it != blue.end(); it++)
				cout << *it << endl;
		}
		if (n != N-1)
			cout << endl;
	}
}
