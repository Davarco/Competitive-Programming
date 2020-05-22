#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> t3i;

bool sorter(t3i a, t3i b)
{
	bool case1 = get<1>(a) > get<1>(b);
	bool case2 = get<1>(a) == get<1>(b) && get<2>(a) < get<2>(b); 
	bool case3 = get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<0>(a) < get<0>(b);
	return case1 || case2 || case3;
}

int main()
{
	int N;
	scanf("%d\n\n", &N);

	string input;
	while (N--)
	{
		vector<t3i> v(100, make_tuple(0, -1, 0));
		int	extra[100][10] = { 0 }; 
		int c, p, t; char L;
		while (getline(cin, input))
		{
			if (input == "")
				break;
			sscanf(input.c_str(), "%d %d %d %c\n", &c, &p, &t, &L);
			if (get<1>(v[c-1]) == -1)
			{
				get<0>(v[c-1]) = c;
				get<1>(v[c-1]) = 0;
			}
			if (L == 'C')
			{
				if (extra[c-1][p] != -1)
				{
					get<0>(v[c-1]) = c;
					get<1>(v[c-1]) += 1;
					get<2>(v[c-1]) += t + extra[c-1][p];
					extra[c-1][p] = -1;
				}
			}
			else if (L == 'I' && extra[c-1][p] != -1)
				extra[c-1][p] += 20;
		}
		sort(v.begin(), v.end(), sorter);
		for (int i = 0; i < v.size(); i++)
			if (get<1>(v[i]) > -1)
				printf("%d %d %d\n", get<0>(v[i]), get<1>(v[i]), get<2>(v[i]));
		if (N != 0)
			printf("\n");
	}
}
