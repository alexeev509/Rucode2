
#include <iostream>
#include <algorithm>

using namespace std;

long double dp[100][100];

int arr[100];

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	std::cout.precision(13);

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int len = 1; len <= n; len++) {
		for (int l = 0; l+len-1 < n; l++) {
			int r = l + len - 1;
			if (l == r) {
				dp[l][r] = arr[l];
			}
			for (int i = l; i < r; i++) {
				long double average = (dp[l][i] + dp[i+1][r]) / 2;
				dp[l][r] = max(dp[l][r], average);
			}
		}
	}

	std::cout << dp[0][n - 1];

}
