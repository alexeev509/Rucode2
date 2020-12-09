#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

vector<vector<int>> g;
vector<int> path, answer;
vector<bool> used;

int q = 0;


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
	for (int i = 2; i <= n; ++i) {
		int v;
		cin >> v;
		g[i].push_back(v);
		g[v].push_back(i);
	}

	dfs(1);

	used = vector<bool>(n + 1, false);
	dfs(answer.back());

	if (answer.size() % 2 == 1) {
		std::cout << answer[answer.size() / 2];
	}
	else {
  //Почему -1 а не плюс один не может быть ?
		int v1 = answer[answer.size() / 2 - 1];
		int v2 = answer[answer.size() / 2];
		std::cout << min(v1,v2)<< " " << max(v1,v2);
	}
}
