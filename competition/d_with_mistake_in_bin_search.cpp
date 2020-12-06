#include <iostream>
#include <algorithm>
#include <cmath>
//Основная идея на компонентах связности графа 
//https://www.youtube.com/watch?v=1smHI5BXOoM
//https://notes.algoprog.ru/binsearch/07_binsearch_main.html 
using namespace std;



long double f(long double k, long double m) {
	return k * k - k - 2 * m;
}
long double binSearch(long double l, long double r, long double m) {
	long double  k = 0, s = 0, eps = 1e-10;
	while (r-l>eps) {
		k = (l + r) / 2;
		if (f(k,m) > 0) {
			r = k;
		}
		else {
			l = k;
		}
	}
	return k;
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
		max_ = N - round(binSearch(1, N, M)) + 1;
		std::cout << min_ << " " << max_;
	}
}
