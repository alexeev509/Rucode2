#include <iostream>
#include <cmath>

using namespace std;


double getLenToPoint(int x1, int y1, int x2, int y2) {
	double dx = x2 - x1;
	double dy = y2 - y1;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	int x,y,r;
	std::cin >> x >> y >>r;

	int count_of_colors = 1;

	double rToCentre=getLenToPoint(x, y, 0, 0);

	double rToX= getLenToPoint(x, y, x, 0);
	double rToy = getLenToPoint(x, y, 0, y);
	//x!=0 && y!=0
	if (rToCentre < r) {
		count_of_colors++;
	}

	if (rToX < r) {
		count_of_colors++;
	}

	if (rToy < r) {
		count_of_colors++;
	}
	//Add black color
	if (rToX <= r || rToy <= r || rToCentre <= r) {
		count_of_colors++;
	}

	std::cout << count_of_colors;

}
