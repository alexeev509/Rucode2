#include <iostream>
//http://shujkova.ru/sites/default/files/lec5.pdf
using namespace std;

long long dp[100][100];
long long ep[100][100];
string sequence;
int n;
void rec(int l, int r) {
	if (dp[l][r] == r - l + 1)
		return;

	if (dp[l][r] == 0) {
		cout << sequence.substr(l, r - l + 1);
		return;
	}

	if (ep[l][r] == -1) {//Если подстрока имеет в начале и конце
//соответствующего типа правильные скобки,
		cout << sequence[l]; //то печатаем левую скобку
		rec(l + 1, r - 1);//вызов рекурсию вложенной подстроки
		cout << sequence[r];// печатаем правую скобку
		return;
	}
	rec(l, ep[l][r]); //вызов рекурсии от левой подстроки
	rec(ep[l][r] + 1, r);//вызов рекурсии от правой подстроки
}
int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::cin >> sequence;
	n = sequence.size();

	for (int r = 0; r < n; ++r)
		for (int l = r; l >= 0; --l) {
			if (l == r)
				dp[l][r] = 1; // База динамики
			else {
				int best = 1000000; int mk = -1;
				if (sequence[l] == '(' && sequence[r] == ')' || sequence[l] == '[' &&
					sequence[r] == ']' || sequence[l] == '{' && sequence[r] == '}')
					//Случай соответствующих скобок
					best = dp[l + 1][r - 1];
				//Общий случай правила перехода динамики
				for (int k = l; k < r; ++k)
					if (dp[l][k] + dp[k + 1][r] < best) {
						best = dp[l][k] + dp[k + 1][r];
						mk = k; //поиск оптимального разбиения строки
					}
				dp[l][r] = best; ep[l][r] = mk;
			}
		}

	rec(0, n - 1); // Вызов рекурсии в основном тексте программы


}
