#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	string input;
	int index = 0;
	while (getline(cin, input))
	{
		if (input == "end")
			break;
			
		vector<stack<int>> stacks(26);
		stacks[0].push(input[0] - 'A');
		for (int i = 1; i < input.size(); i++)
		{
			int ship = input[i] - 'A';
			for (int s = 0; s < 26; s++)
			{
				if (stacks[s].size() == 0 || stacks[s].top() >= ship)
				{
					stacks[s].push(ship);
					break;
				}
			}
		}

		int count = 0;
		for (int i = 0; i < 26; i++)
			if (stacks[i].size() > 0) 
				count += 1;

		index += 1;
		printf("Case %d: %d\n", index, count);
	}
}
