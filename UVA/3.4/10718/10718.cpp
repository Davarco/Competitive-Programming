#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

unsigned int N, L, U;

bool lowest(unsigned int mask, int i)
{
	return mask <= U;	
}

bool highest(unsigned int mask, int i)
{
	unsigned int temp = 0;
	for (int j = i-1; j >= 0; j--)
		temp = temp | (1 << j);
	return (mask | temp) < L;
}

int main()
{
	while (cin >> N >> L >> U)
	{
		unsigned int best = 0;
		unsigned int mask = 0;
		for (int i = 31; i >= 0; i--)
		{
			unsigned int new_mask = mask | (1 << i);
			if (((N >> i) & 1) == 0 && lowest(new_mask, i))
				mask = new_mask;
			if (((N >> i) & 1) == 1 && highest(mask, i))
				mask = new_mask;
		}
		cout << mask << endl;
	}
}
