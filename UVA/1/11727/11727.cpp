#include <iostream>
#include <algorithm>

int T;

int main()
{
	std::cin >> T;
	for (int i = 0; i < T; i++) 
	{
		int a, b, c;
		std::cin >> a >> b >> c;

		int minimum = std::min({a, b, c});
		int maximum = std::max({a, b, c});
		if (a != minimum && a != maximum)
			printf("Case %i: %i\n", i+1, a);
		else if (b != minimum && b != maximum)
			printf("Case %i: %i\n", i+1, b);
		else
			printf("Case %i: %i\n", i+1, c);
	}
}
