#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

#define INF 100000000

double snuke(LL a)
{
	LL adig = 0, atem = a;
	while (atem > 0)
	{
		adig += atem % 10;
		atem /= 10;
	}
	return (double)(a)/(double)(adig);
}

int main()
{
	int K;
	cin >> K;

	vector<LL> numbers;
	LL base = 1;
	set<LL> used;
	for (int a = 0; a < 15; a++)
	{
		for (int b = 1; b <= 150; b++)
		{
			LL c = base*(b+1) - 1;
			if (used.find(c) != used.end())
				continue;
			numbers.push_back(c);
			used.insert(c);
		}
		base *= 10;
	}
	unique(numbers.begin(), numbers.end());
	sort(numbers.begin(), numbers.end());	
	reverse(numbers.begin(), numbers.end());
	
	double best = DBL_MAX;
	vector<LL> res;
	for (int i = 0; i < numbers.size(); i++)
	{
		double now = snuke(numbers[i]);
		if (now - 0.0000000000001 <= best)
		{
			best = now;
			res.push_back(numbers[i]);
		}
	}
	reverse(res.begin(), res.end());
	for (int k = 0; k < K; k++)
		cout << res[k] << endl;
}

