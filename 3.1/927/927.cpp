#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	string input;

	int C;
	getline(cin, input); sscanf(input.c_str(), "%d\n", &C);
	for (int c = 0; c < C; c++)
	{
		string A; getline(cin, A);
		int i = 1, d, k;
		getline(cin, input); sscanf(input.c_str(), "%d\n", &d);
		getline(cin, input); sscanf(input.c_str(), "%d\n", &k);

		int p = 0;
		for (; ; i++)
		{
			int prev = p;
			p += i * d;
			if (prev < k && p >= k) break;
		}
		// cout << i << endl;

		long long n = 1;
		long long output = 0;
		long long coefficient;
		stringstream strm(A);
		strm >> coefficient;
		while (strm >> coefficient)
		{
			// cout << "c " << coefficient << endl;
			output += n * coefficient;
			n *= i;
		}
		cout << output << endl;
	}
}
