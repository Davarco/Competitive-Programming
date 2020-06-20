#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;

int main()
{
	while (cin >> N)
	{
		if (N == 0) break;

		vector<int> seq;
		int count = 0;
		for (int n = 0; n < N; n++)
		{
			int next; cin >> next; 
			if (next > 0)
			{
				count += 1;
				seq.push_back(next);
			}
		}
		if (count == 0)
			cout << "0" << endl;
		else
			for (int i = 0; i < count; i++)
				if (i == count-1)
					cout << seq[i] << endl;
				else
					cout << seq[i] << " ";
	}
}

