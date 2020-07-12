#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

void print(vector<int> s)
{
	for (int i = 0; i < s.size(); i++) 
		printf("%d ", s[i]);
	printf("\n");
}

int main()
{
	vector<int> s;
	int n;
	while (scanf("%d\n", &n) != EOF) 
	{
		s.push_back(n);
		int N = s.size();
		if (N % 2 == 0)
		{
			nth_element(s.begin(), s.begin() + N/2 - 1, s.end());
			int m0 = s[N/2-1];
			nth_element(s.begin(), s.begin() + N/2, s.end());
			int m1 = s[N/2];
			printf("%d\n", (m0+m1)/2);
		}
		else
		{
			nth_element(s.begin(), s.begin() + N/2, s.end());
			int m0 = s[N/2];
			printf("%d\n", m0);
		}
	}
}
