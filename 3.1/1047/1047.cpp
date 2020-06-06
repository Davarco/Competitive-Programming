#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <bitset>
#include <set>
#include <map>

using namespace std;

typedef vector<int> vi;

unsigned int reverse(int a)
{
	unsigned int b = 0;
	for (int i = 0; i < 32; i++)
		b |= ((a >> i) & 1) << (31-i);
	return b;
}

int main()
{
	int N, P;
	int C = 0;
	while (cin >> N >> P)
	{
		if (N == 0 && P == 0) break;

		vi size(N);
		for (int i = 0; i < N; i++) cin >> size[i];
		int M; cin >> M;
		map<int, int> common;
		for (int m = 0; m < M; m++)
		{
			int T; cin >> T;
			int poles = 0;
			for (int t = 0; t < T; t++) { int pole; cin >> pole; pole--; poles |= (1 << pole); }
			int size; cin >> size;
			if (common.count(poles) == 0)
				common[poles] = 0;
			common[poles] += size;
		}

		int largest = INT_MIN;
		int best = 0;
		for (int i = 0; i < (1 << N); i++)
			if (__builtin_popcount(i) == P)
			{
				int area = 0;
				for (int p = 0; p < N; p++)
					if (i & (1 << p))
						area += size[p];

				for (auto it = common.begin(); it != common.end(); it++)
				{
					int pole = it->first, size = it->second;
					int similar = __builtin_popcount(i & pole);
					if (similar >= 2)
						area -= (similar-1) * size;
				}

				if (area > largest || (area == largest && reverse(i) > reverse(best)))
				{
					largest = area;
					best = i;
				}
			}

		cout << "Case Number  " << ++C << endl;
		printf("Number of Customers: %d\n", largest);
		cout << "Locations recommended: ";
		for (int p = 0, i = 0; p < N; p++)
			if (best & (1 << p)) 
				if (i == P-1)
				{
					cout << (p+1);
					i += 1;
				}
				else
				{
					cout << (p+1) << " "; i += 1;
				}
		cout << endl << endl;
	}
}

