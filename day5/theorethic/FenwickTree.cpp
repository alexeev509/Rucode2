#include <iostream>
#include <vector>

using namespace std;

struct FenwickTree {

	vector<int> tree;

	void init(vector<int> a) {
		tree.assign(a.size(), 0);
		for (int i = 0; i < a.size(); i++) {
			inc(i, a[i]);
		}
	}


	void inc(int i, int delta)
	{
		for (; i < tree.size(); i = g_(i))
			tree[i] += delta;
	}


	int f_(int r) {
		return (r & (r + 1))-1;
	}

	int g_(int r) {
		return (r | (r + 1));
	}

	int findSum(int r) {
		int ans = 0;
		for (; r >= 0; r=f_(r))
			ans += tree[r];
		return ans;
	}

	int findSum(int l, int r) {
		return findSum(r) - findSum(l - 1);
	}

	int add(int pos, int x) {
		for (int r = pos + 1; r < tree.size(); r = g_(r))
			tree[pos] += x;
	}
};

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	FenwickTree fen;

	vector<int> a(6);
	a[0] = 10;
	a[1] = 5;
	a[2] = 6;
	a[3] = 7;
	a[4] = 8;
	a[5] = 5;

	fen.init(a);

	std::cout << fen.findSum(1, 3);
}
