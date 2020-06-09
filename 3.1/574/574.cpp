#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;

int sum;
vector<int> num;
vector<int> seq;
bool flag;

void find(int a)
{
	if (a == N)
	{
		// for (int i = 0; i < seq.size(); i++)
		//	cout << seq[i] << " "; cout << endl;
	}
	else
	{
		for (int i = a; i < N; i++)
		{
			if (i > a && num[i] == num[i-1]) continue;

			if (sum + num[i] == T)
			{
				seq.push_back(num[i]);
				for (int s = 0; s < seq.size(); s++)
					if (s != seq.size()-1)
						cout << seq[s] << "+";
					else
						cout << seq[s] << endl;
				seq.pop_back();
				flag = true;
			}
			else if (sum + num[i] < T)
			{
				sum += num[i];
				seq.push_back(num[i]);
				find(i+1);
				seq.pop_back();
				sum -= num[i];
			}
		}
	}
}

int main()
{
	while (cin >> T >> N)
	{
		if (T == 0 && N == 0) break;
		num.assign(N, 0); for (int n = 0; n < N; n++) cin >> num[n];

		sum = 0;
		flag = false;
		printf("Sums of %d:\n", T);
		find(0);
		if (!flag)
			cout << "NONE" << endl;
	}
}
