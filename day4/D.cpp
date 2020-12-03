#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	std::cout.sync_with_stdio(false);
	std::cin.sync_with_stdio(false);
	int n;

	std::cin >> n;

	int A[100][100];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
			//cout << A[i][j] <<" ";
		}
		//cout << "\n";
	}
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << A[i][j] << " ";
		}
		cout << "\n";
	}


}

//0 8 5
//3 0 беск
//беск 2 0

//k=0

//A[0][0]=min(0,0 +0)
//A[0][1]=min(8,0+8)=0
//A[0][2]=min(5,0+5)=5
//A[1][0]=min(3...

//A[1][2]=min(беск, 3+5)=8
//A[2][0]=min(беск, 
