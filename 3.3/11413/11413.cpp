#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

typedef long long LL;

LL N, M;
vector<LL> vessels;

int main()
{
	while (cin >> N >> M)
	{
		vessels.assign(N, 0); 
		LL a = LLONG_MIN, b = 0;
		for (LL n = 0; n < N; n++)
		{
			cin >> vessels[n]; 
			a = vessels[n] > a ? vessels[n] : a;
			b += vessels[n];
		}
		b += 1;

		if (a == b)
		{
			cout << a << endl;
			continue;
		}
		LL best = LLONG_MAX;
		while (a < b)
		{
			LL m = (a+b)/2;

			LL count = 1, current = 0;
			for (LL i = 0; i < N; i++)
			{
				if (current + vessels[i] > m)
				{
					count += 1; 
					current = vessels[i];
				}
				else 
					current += vessels[i];
			}
			// cout << a << " " << b << " " << m << " " << count << endl;
			
			if (count > M)
			{
				a = m+1;
			}
			else
			{
				best = m < best ? m : best;		
				b = m;
			}
		}

		cout << best << endl;
	}
}
