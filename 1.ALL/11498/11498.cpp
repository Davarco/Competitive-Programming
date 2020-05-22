#include <iostream>


int K, N, M;

int main()
{
	std::cin >> K >> N >> M;
	while (K != 0) 
	{
		for (int i = 0; i < K; i++) 
		{
			int a, b;
			std::cin >> a >> b;
			if (a < N && b > M) 
				std::cout << "NO" << std::endl;
			else if (a > N && b > M)
				std::cout << "NE" << std::endl;
			else if (a > N && b < M)
				std::cout << "SE" << std::endl;
			else if (a < N && b < M) 
				std::cout << "SO" << std::endl;
			else
				std::cout << "divisa" << std::endl;
		}
		std::cin >> K >> N >> M;
	}
}
