#include <iostream>
#include <vector>

using namespace std;


const int SIZE = 10000;
vector <int> mass [SIZE];
bool used[100];
vector<int> answer;

void bfs(int v) {
	used[v] = true;
	//std::cout << start + 1 << " ";
	answer.push_back(v);
	for (auto q : mass[v]) {
		if (!used[q]) {
			bfs(q);
			//std::cout << q << " ";
			answer.push_back(v);
		}
	}
}

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	int N, M, v;

	std::cin >> N >> M>> v;

	for (int i = 0; i < M; i++) {
		int start, end;
		std::cin >> start >> end;
		mass[start].push_back(end);
		mass[end].push_back(start);
	}

	bfs(v);

	std::cout << answer.size()<<"\n";
	for (int i = 0; i < answer.size(); ++i) {
		std::cout << answer[i] << " ";
	}
}
