#include <iostream>
#include <algorithm>
#include <cmath>
//Основная идея на компонентах связности графа 
//https://www.youtube.com/watch?v=1smHI5BXOoM
//https://notes.algoprog.ru/binsearch/07_binsearch_main.html 
using namespace std;


long double discriminant(int m) {
	long double discriminant = 1 + 4 * 2 * m;
	long double x1 = (1 + sqrt(discriminant)) / 2;
	return x1;
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	int N, M, min_, max_;
	std::cin >> N >> M;

	int max_count_of_edges = N * (N - 1) / 2;
	if (M > max_count_of_edges) {
		std::cout << -1;
	}
	else {
		min_ = max(N - M, 1);
		max_ = N - discriminant(M) + 1;
		std::cout << min_ << " " << max_;
	}
}
