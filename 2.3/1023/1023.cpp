#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> tup;

bool Compare(tup a, tup b)
{
	if (get<0>(a) == get<0>(b))
		return get<2>(a) > get<2>(b);
	else
		return get<0>(a) > get<0>(b);
}

int main()
{
	priority_queue<tup, vector<tup>, function<bool(tup, tup)>> pq(Compare);

	string input;
	while (getline(cin, input))
	{
		if (input == "#")
			break;
		int Q_num, period;
		sscanf(input.c_str(), "Register %d %d\n", &Q_num, &period);
		pq.push(make_tuple(period, period, Q_num));
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		tup t = pq.top();
		pq.pop();
		pq.push(make_tuple(get<0>(t) + get<1>(t), get<1>(t), get<2>(t)));
		cout << get<2>(t) << endl;
	}
}
