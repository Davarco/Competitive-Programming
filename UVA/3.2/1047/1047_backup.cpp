#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>

using namespace std;

typedef vector<int> vi;

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
		vector<vi> common(M);
		vi common_size(M);
		for (int m = 0; m < M; m++)
		{
			int T; cin >> T;
			vi c(T); 
			for (int t = 0; t < T; t++) 
			{
				cin >> c[t]; c[t] -= 1;
			}
			common[m] = c;
			cin >> common_size[m];
		}

		int largest = INT_MIN;
		int best = 0;
		for (int i = 0; i < (1 << N); i++)
		{
			if (__builtin_popcount(i) == P)
			{
				int area = 0;
				set<int> poles;
				for (int p = 0; p < N; p++)
					if (i & (1 << p))
					{
						poles.insert(p);
						area += size[p];
					}

				for (int n = 2; n < N; n++)
					for (int m = 0; m < M; m++)
					{
						int num = 0;
						for (int j = 0; j < common[m].size(); j++)
							if (poles.count(common[m][j]) > 0)
								num += 1;
						if (n == num && n % 2 == 0)
							area -= common_size[m];
						if (n == num && n % 2 == 1)
							area += common_size[m];
					}
				
				if (area > largest || (area == largest && i < best))
				{
					largest = area;
					best = i;	
				}
			}
		}
		cout << "Case Number " << C++ << endl;
		printf("Number of Customers: %d\n", largest);
		cout << "Locations recommended: ";
		for (int p = 0; p < N; p++)
			if (best & (1 << p)) 
				if (p == N-1)
					cout << (p+1);
				else
					cout << (p+1) << " "; cout << endl;
	}
}

