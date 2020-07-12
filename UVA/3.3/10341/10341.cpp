#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

double P, Q, R, S, T, U;

int main()
{
	while (cin >> P >> Q >> R >> S >> T >> U)
	{
		double a = 0, b = 1, ans = -1;
		bool flag = true;
		int count = 0;
		while (++count < 100)
		{
			double x = (a+b)/2;
			double eq = P*exp(-x) + Q*sin(x) + R*cos(x) + S*tan(x) + T*x*x+U;
			if (abs(eq) <= 0.00000001)
			{
				ans = x;
				flag = false;
				break;
			}
			if (eq < 0)
				b = x;
			else
				a = x;
		}
		if (ans == -1)
			cout << "No solution" << endl;
		else
			printf("%0.0004lf\n", ans);
	}
}
