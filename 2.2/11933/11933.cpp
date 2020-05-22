#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

int main()
{
	uint n;
	while (scanf("%d\n", &n) != EOF)
	{
		if (n == 0)
			break;

		uint a = 0, b = 0;
		bool A = true;
		for (int i = 0; i < 32; i++)
		{
			uint other = (n >> i) & 1;
			if (other == 1 && A)
			{
				a = a | (1 << i);
				A = false;
			}
			else if (other == 1)
			{
				b = b | (1 << i);
				A = true;
			}
		}
		cout << a << " " << b << endl;
	}
}
