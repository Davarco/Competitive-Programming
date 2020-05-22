#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	string input; 

	int N;
	getline(cin, input);
	sscanf(input.c_str(), "%d\n", &N);
	getline(cin, input);

	for (int n = 0; n < N; n++)
	{
		map<string, float> counts;
		float total = 0;
		while (getline(cin, input))
		{
			if (input == "")
				break;
			total += 1;
			counts[input] += 1;
		}
		for (auto it = counts.begin(); it != counts.end(); it++)
			printf("%s %.4f\n", it->first.c_str(), 100*it->second/total);
		if (n != N-1)
			cout << endl;
	}
}
