#include <iostream>
#include <vector>
#include <algorithm>
//https://www.geeksforgeeks.org/two-dimensional-binary-indexed-tree-or-fenwick-tree/
//https://neerc.ifmo.ru/wiki/index.php?title=%D0%9C%D0%BD%D0%BE%D0%B3%D0%BE%D0%BC%D0%B5%D1%80%D0%BD%D0%BE%D0%B5_%D0%B4%D0%B5%D1%80%D0%B5%D0%B2%D0%BE_%D0%A4%D0%B5%D0%BD%D0%B2%D0%B8%D0%BA%D0%B0
using namespace std;

struct FenwickTree {

	vector<vector<long long>> tree;

	void init(int n) {
		tree = vector<vector<long long>>(n+1);
		for (int i = 1; i < n + 1; i++) {
			tree[i] = vector<long long>(n + 1);
		}
	}


	int f_(int r) {
		return (r & (r + 1))-1;
	}

	int g_(int r) {
		return (r | (r + 1));
	}

	long long findSum(int x, int y) {
		long long result = 0;
		for (int i = x; i > 0; i = (i & (i + 1)) - 1)
			for (int j = y; j > 0; j = (j & (j + 1)) - 1)
				result += tree[i][j];
		return result;
	}

	int findSum(int x1, int y1, int x2, int y2) {
		return findSum(x2,y2) - findSum(x2,y1-1)-findSum(x1-1,y2) + findSum(x1-1,y1-1);
	}

	void add(int x, int y) {
		for (int i = x; i < tree.size(); i = (i | (i + 1)))
			for (int j = y; j < tree.size(); j = (j | (j + 1)))
				tree[i][j] += 1;
	}
};

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	FenwickTree fen;
	int n, k;
	std::cin >> n >> k;

	fen.init(n);
	for (int i = 0; i < k; i++) {
		string str;
		std::cin >> str;
		if (str == "ADD") {
			int x, y;
			std::cin >> x>>y;
			fen.add(x, y);
		}
		else {
			int x1, y1, x2, y2;
			std::cin >> x1 >> y1 >> x2 >> y2;
			long long summ=fen.findSum(min(x1,x2), min(y1,y2), max(x2,x1),max(y2,y1));
			std::cout << summ <<"\n";
		}
	}
}

/*10 1000
GET 6 1 10 1
ADD 4 7
ADD 3 9
GET 6 8 5 6
ADD 3 10
GET 4 1 1 1
GET 2 5 10 3
GET 1 9 6 10
ADD 9 7
GET 4 4 8 8
ADD 3 3
ADD 3 1
ADD 8 3
GET 6 7 7 10
ADD 1 4
ADD 6 6
GET 3 4 3 8
GET 9 6 4 10
*/
