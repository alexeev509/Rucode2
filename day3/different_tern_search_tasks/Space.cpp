//https://codeforces.com/problemset/problem/106/E
//https://kesh.kz/blog/%D0%B2%D0%BB%D0%BE%D0%B6%D0%B5%D0%BD%D0%BD%D1%8B%D0%B9-%D1%82%D0%B5%D1%80%D0%BD%D0%B0%D1%80%D0%BD%D1%8B%D0%B9-%D0%BF%D0%BE%D0%B8%D1%81%D0%BA-%D1%81-%D0%B7%D0%BE%D0%BB%D0%BE%D1%82%D1%8B%D0%BC-%D1%81/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cfloat>

using namespace std;

struct Point {
	long long x;
	long long y;
	long long z;

};

struct PointD {
	double long x;
	double long y;
	double long z;

};

const double EPS = 1e-7;
const double FI = 1 / ((sqrt(5) + 1) / 2);//золотое сечение
const int MAX = (int) 1e4;//максимальная граница поиска
const int MIN = -MAX;

double best_distance = DBL_MAX;//лучшее расстояние (минимальное)
PointD bestPoint;//лучшая точка
Point points[100];// координаты планет
int n;




long double distance(Point a, Point b) {
	long long dx = b.x - a.x;
	long long dy = b.y - a.y;
	long long dz = b.z - a.z;
	return sqrt(dx * dx + dy * dy + dz * dz);
}

long double distance(Point a, Point b, Point c, Point o) {
	return distance(a, o) + distance(b, o) + distance(c, o);
}

long double f(long double x, long double y, long double z) {
	double long max_dist = 0;
	for (int i = 0; i < n; i++) {
		Point p = points[i];
		double long s =
			(p.x - x) * (p.x - x) +
			(p.y - y) * (p.y - y) +
			(p.z - z) * (p.z - z);
		max_dist = max(max_dist, s);
	}

	if (max_dist < best_distance) {
		best_distance = max_dist;
		bestPoint.x = x;
		bestPoint.y = y;
		bestPoint.z = z;
	}
	return max_dist;
}

long double f(long double x, long double y) {
	long double l = MIN;
	long double r = MAX;
	while (r - l > EPS) {
		double long delta = (r - l) * FI;
		double long m1 = r - delta,
			m2 = l + delta;
		if (f(x, y, m1) > f(x, y, m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	return f(x, y, (l + r) / 2);
}

long double f(long double x) {
	double l = MIN;
	double r = MAX;
	while (r - l > EPS) {
		double long delta = (r - l) * FI;
		double long m1 = r - delta,
			m2 = l + delta;
		if (f(x, m1) > f(x, m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	return f(x, (l + r) / 2);
}


int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	//std::cout.precision(1);

	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
			std::cin >> points[i].x >> points[i].y >> points[i].z;
	}

	double l = MIN;
	double r = MAX;

	while (r - l > EPS) {
		double long delta = (r - l) * FI;
		double long m1 = r - delta;
		double long m2 = l + delta;
		if (f(m1) > f(m2)) {
			l = m1;
		}
		else {
			r = m2;
		}
	}
	//printf("%.6f", bestPoint.x);
	//printf(" %.6f", bestPoint.y);
	//printf(" %.6f", bestPoint.z);
	std::cout << bestPoint.x << " " << bestPoint.y << " " << bestPoint.z;
}



