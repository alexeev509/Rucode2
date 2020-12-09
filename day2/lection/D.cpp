#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;
vector<int> path, answer;
vector<bool> used;

int n;

void dfs(int v) {
	used[v] = true;
	path.push_back(v);
	for (int t : g[v]) {
		if (!used[t]) {
			dfs(t);
		}
	}
	if (path.size() > answer.size()) {
		answer = path;
	}

	path.pop_back();
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);

	std::cin >> n;
	g = vector<vector<int>>(n + 1);
	used = vector<bool>(n + 1, false);
	for (int i = 0; i < n-1; i++) {
		int v, u;
		std::cin >> v >> u;
		g[v].push_back(u);
		g[u].push_back(v);
	}

	dfs(1);

	used = vector<bool>(n + 1, false);
	dfs(answer.back());

	std::cout << answer.size();
}
