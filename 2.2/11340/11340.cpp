#include <iostream>
#include <string>
#include <tuple>
#include <map>

int N, K, M;

int main()
{
	scanf("%d\n", &N);
	for (int i = 0; i < N; i++)
	{
		std::map<char, int> table;
		int totals = 0;

		scanf("%d\n", &K);
		for (int j = 0; j < K; j++)
		{
			char a; int b;
			scanf("%c %d\n", &a, &b);
			table.insert(std::make_pair(a, b));
		}

		scanf("%d\n", &M);
		for (int i = 0; i < M; i++)
		{
			std::string str;
			std::getline(std::cin, str);
			for (int c = 0; c < str.size(); c++)
				if (table.find(str[c]) != table.end()) 
					totals += table.at(str[c]);
		}
		printf("%d.%02d$\n", totals / 100, totals % 100);
	}
}
