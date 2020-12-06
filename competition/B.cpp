#include <iostream>


using namespace std;

//I decided but don't undersand this decision yet;
int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cout << 80;
	}
}
