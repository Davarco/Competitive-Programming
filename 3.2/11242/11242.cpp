#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int F, R; 
	while (cin >> F >> R)
	{
		if (F == 0) break;

		vector<float> front(F);
		for (int f = 0; f < F; f++) cin >> front[f];
		vector<float> rear(R);
		for (int r = 0; r < R; r++) cin >> rear[r];

		vector<float> ratios(F*R);
		for (int f = 0; f < F; f++)
			for (int r = 0; r < R; r++)
				ratios[f*R+r] = rear[r] / front[f];
		sort(ratios.begin(), ratios.end());
		float best = -1;
		for (int i = 0; i < ratios.size()-1; i++)
		{
			float f = ratios[i+1]/ratios[i];
			if (f > best) best = f;
		}
		printf("%.02f\n", best);
	}
}
