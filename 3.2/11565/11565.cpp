#include <iostream>

using namespace std;

typedef int ll;

int main()
{
	ll N; cin >> N;
	for (ll n = 0; n < N; n++)
	{
		ll A, B, C; cin >> A >> B >> C;
		bool flag = false;
		for (ll x = -B; x <= B; x++)
		{
			if (x == 0 || B % x == 0)
			{
				for (ll y = x+1; y < A-x && y != x; y++)
				{
					ll z = A - x - y;
					if (x * y * z == B && x*x + y*y + z*z == C && z != x && z != y)
					{
						cout << x << " " << y << " " << z << endl;
						flag = true;
						goto SKIP; // Just wanted to see it in action :D
					}
				}
			}
		}
SKIP:
		if (!flag)
			cout << "No solution." << endl;
	}
}
