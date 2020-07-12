#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class FenwickTree
{
private:
	vector<int> ft;

public:
	FenwickTree(int n)
	{
		ft.assign(n+1, 1);
	}

	int rsq(int b)
	{
		int sum = 1;
		cout << b;
		for (; b; b -= (b & -b)) 
			sum *= ft[b];
		cout << " " << sum << endl;
		return sum;
	}
	
	int rsq(int a, int b)
	{
		cout << "range " << a << " " << b << endl;
		return rsq(b) * (a == 1 ? 1 : rsq(a-1));
	}

	void update(int k, int v)
	{
		cout << "update val " << v << endl;
		bool flag = true;
		for (; k < ft.size(); k += (k & -k))
		{
			ft[k] *= v;
			cout << "update " << k << " " << v << " " << ft[k] << endl;
		}
	}
};

int main()
{
	int N, K;
	while (scanf("%d %d\n", &N, &K) != EOF)
	{
		string s;
		vector<int> seq(N);
		for (int i = 0; i < N; i++)
		{
			cin >> seq[i];
			if (seq[i] < 0) seq[i] = -1;
			else if (seq[i] > 0) seq[i] = 1;
		}

		FenwickTree ft(N);
		for (int i = 0; i < N; i++) ft.update(i+1, seq[i]);
		for (int k = 0; k < K; k++)
		{
			char c; int a, b;
			cin >> c >> a >> b;
			if (c == 'C')
			{
				if (b != 0) b = b/abs(b);
				ft.update(a, b);
			}
			else if (c == 'P')
			{
				int ans = ft.rsq(a, b);
				if (ans == 0) s += "0";
				if (ans == 1) s += "+";
				if (ans == -1) s += "-";
			}
		}
		cout << s << endl;
	}
}
