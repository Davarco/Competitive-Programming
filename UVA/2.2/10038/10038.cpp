#include <iostream>
#include <sstream>
#include <iterator>
#include <bitset>
#include <vector>

int main()
{
	std::string str;
	while (std::getline(std::cin, str))
	{
		std::stringstream strm;
		strm << str;
		
		int n, prev;
		strm >> n >> prev;
		std::vector<bool> visited(n);
		for (int i = 1; i < n; i++)
		{
			int next;
			strm >> next;
			if (std::abs(next-prev) < n)
				visited[std::abs(next-prev)] = true;
			prev = next;
		}
		bool flag = false;
		for (int i = 1; i < n; i++) 
			if (!visited[i])
				flag = true;
		if (!flag)
			std::cout << "Jolly" << std::endl;
		else
			std::cout << "Not jolly" << std::endl;
	}
}
