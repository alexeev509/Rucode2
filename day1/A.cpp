

#include <iostream>

using namespace std;

unsigned long long sequence[2000];

unsigned long long dp[2000][2000];

const unsigned long long M = 1e9;

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);


	int N;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> sequence[i];
	}

	for (int len = 1; len <= N; len++) {
		for (int l = 0; l + len - 1 < N; l++) {
			int r = l + len - 1;
			if (l == r) {
				dp[l][r] = 1;
			}
			//else if (r == l + 1) {
				//dp[l][r] = 1;
			//}
			else {
        //если  - dp[l + 1][r - 1] >dp[l + 1][r] + dp[l][r - 1], то будет отрицательное - поэтому прибавляем M
				dp[l][r] = (dp[l + 1][r] + (dp[l][r - 1] - dp[l + 1][r - 1])+M)%M;
				
				if (sequence[l] == sequence[r]) {
					dp[l][r] += (1 + dp[l + 1][r - 1])%M;
					dp[l][r] %= M;
				}
			}
		}
	}

	std::cout << dp[0][N - 1];

}


