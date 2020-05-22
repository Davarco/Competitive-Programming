#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<string> sequences;

void search(queue<char> source, queue<char> target, stack<char> s, string seq)
{
	if (target.size() == 0)
	{
		sequences.push_back(seq.substr(0, seq.size()-1));
		return;
	}
	if (source.size() > 0)
	{
		queue<char> src2 = source;
		stack<char> s2 = s;
		s2.push(src2.front());
		src2.pop();
		search(src2, target, s2, seq + "i ");
	}
	if (s.size() > 0 && s.top() == target.front())
	{
		s.pop();
		target.pop();
		search(source, target, s, seq + "o ");
	}
}

int main()
{
	string first, second;
	while (getline(cin, first) && getline(cin, second))
	{
		sequences.clear();

		queue<char> source;
		for (int i = 0; i < first.length(); i++)
			source.push(first[i]);

		queue<char> target;
		for (int i = 0; i < second.length(); i++)
			target.push(second[i]);

		stack<char> s;
		string seq;
		search(source, target, s, seq);

		cout << "[" << endl;
		for (int i = 0; i < sequences.size(); i++)
			cout << sequences[i] << endl;
		cout << "]" << endl;
	}
}
