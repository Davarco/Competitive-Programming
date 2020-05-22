#include <iostream>


int N;

int main() 
{
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		std::cin >> a >> b;
		if (a < b) 
			std::cout << "<" << std::endl;
		else if (a > b) 
			std::cout << ">" << std::endl;
		else 
			std::cout << "=" << std::endl;
	}
}
