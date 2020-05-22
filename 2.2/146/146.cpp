#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	while (true)
	{
		string str;
		getline(cin, str);	
		if (str == "#")
			break;

		if (next_permutation(str.begin(), str.end()))
			cout << str << endl;
		else
			cout << "No Successor" << endl;
	}
}
