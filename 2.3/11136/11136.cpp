#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long bigint;

int main()
{
	int N;
	while (scanf("%d\n", &N) != EOF)
	{
		if (N == 0)
			break;

		multiset<bigint> urn;
		bigint total = 0;
		for (int n = 0; n < N; n++)
		{
			int K;
			cin >> K;
			for (int k = 0; k < K; k++)
			{
				bigint bill;
				cin >> bill;
				urn.insert(bill);
			}

			bigint lowest = *urn.begin();
			bigint highest = *urn.rbegin();
			total += highest - lowest;
			urn.erase(urn.begin());
			urn.erase(--urn.end());
		}
		cout << total << endl;
	}
}
