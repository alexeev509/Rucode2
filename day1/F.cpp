//It isn't my decision((

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>


typedef long long ll;

using namespace std;

const int MAXN = 200;

int a[MAXN], d2[MAXN], p[MAXN];
bool dl[MAXN][MAXN];
vector<vector<int>> p2;

void rec(int l, int r) {
	//В p2 записано количество элементов - которые нужно удалить на отрезке
	if (p2[l][r] == -1) {
		return;
	}

	int i = p2[l][r];
	rec(l, i);
	rec(i, r);

	printf("%d\n", i + 1);
}

int main()
{


	int n;
	scanf("%d", &n);


	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n - 1; i++) {
		dl[i][i + 1] = true;
	}

	p2.resize(n, vector<int>(n, -1));

	for (int k = 2; k < n; k++) {
		for (int l = 0; l < n - k; l++) {
			int r = l + k;

			for (int i = l + 1; i < r; i++) {
				if (((a[l]<a[i] && a[i]>a[r]) || (a[l] > a[i] && a[i] < a[r])) && dl[l][i] && dl[i][r]) {
					dl[l][r] = true;
					p2[l][r] = i;
				}
			}
		}
	}

	d2[0] = 1;

	for (int j = 1; j < n; j++) {
		d2[j] = INT_MIN;
		for (int i = 0; i < j; i++) {
			if (dl[i][j] && a[0] <= a[i] && a[i] <= a[j]) {
				//d2 - сколько элементов оставить - 
				//стараемся макимизировать количество этих элементов
				if (d2[j] < d2[i] + 1) {
					d2[j] = d2[i] + 1;
					p[j] = i;
				}
			}
		}
	}

	if (d2[n - 1] < 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n", n - d2[n - 1]);
		vector <pair<int, int>> del;
		int i = n - 1;
		while (i != 0) {
			del.push_back(make_pair(p[i], i));
			i = p[i];
		}

		for (int i = del.size() - 1; i >= 0; i--) {
			int l = del[i].first, r = del[i].second;
			rec(l, r);
		}
	}

}

