#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int find_element(const vector<int> &vec, int n)
{
	int a = 0, b = vec.size();
	while (a < b)
	{
		int m = (a+b)/2;
		if (vec[m] == n)
			return m;
		else if (vec[m] < n)
			a = m+1;
		else 
			b = m;
	}
	return -1;
}

int find_smallest_element_larger_than(const vector<int> &vec, int n)
{
	int a = 0, b = vec.size();
	if (n > vec[vec.size()-1]) return -1;
	if (n <= vec[0]) return 0;
	while (a < b)
	{
		int m = (a+b)/2;
		if (vec[m] <= n)
			a = m+1;
		else 
			b = m;
	}
	return a;
}

int find_largest_element_smaller_than(const vector<int> &vec, int n)
{
	if (n >= vec[vec.size()-1]) return vec.size()-1;
	if (n < vec[0]) return -1;
	int a = 0, b = vec.size();
	while (a < b)
	{
		int m = (a+b+1)/2;
		if (vec[m] >= n)
			b = m-1;
		else 
			a = m;
	}
	return a;
}

int main()
{
	vector<int> vec({1, 4, 5, 7, 8, 9, 11, 13, 17, 18, 20, 25});
	printf("%d @ index %d\n", 1, find_element(vec, 1));
	printf("%d @ index %d\n", 25, find_element(vec, 25));
	printf("%d @ index %d\n", 20, find_element(vec, 20));
	printf("%d @ index %d\n", 9, find_element(vec, 9));

	printf("%d larger than %d\n", vec[find_smallest_element_larger_than(vec, -1)], -1);
	printf("%d larger than %d\n", vec[find_smallest_element_larger_than(vec, 17)], 17);
	printf("%d larger than %d\n", vec[find_smallest_element_larger_than(vec, 25)], 25);
	printf("%d larger than %d\n", vec[find_smallest_element_larger_than(vec, 30)], 30);

	printf("%d smaller than %d\n", vec[find_largest_element_smaller_than(vec, 25)], 25);
	printf("%d smaller than %d\n", vec[find_largest_element_smaller_than(vec, 26)], 26);
	printf("%d smaller than %d\n", vec[find_largest_element_smaller_than(vec, 19)], 19);
	printf("%d smaller than %d\n", vec[find_largest_element_smaller_than(vec, 2)], 2);
}
