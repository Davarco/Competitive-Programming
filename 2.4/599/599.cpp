#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
	int N;
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		bitset<26> on;

		string input;
		int num_edges = 0;
		while (getline(cin, input))
		{
			if (input[0] == '*')
				break;
			if (input == "")
				continue;
			char temp0, temp1;
			sscanf(input.c_str(), "(%c, %c)\n", &temp0, &temp1);
			int a = temp0 - 'A', b = temp1 - 'A';
			on[a] = 1;
			on[b] = 1;
			num_edges += 1;
		}
		cin >> input;
		int num_vertices = (input.length()+1)/2;
		int num_acorns = num_vertices - on.count();
		int num_trees = num_vertices - num_edges - num_acorns;
		printf("There are %d tree(s) and %d acorn(s).\n", num_trees, num_acorns);
	}
}
