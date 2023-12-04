#include <iostream>
#include <queue>

using namespace std;

int mult(int* schet, const int N) {
	int s = 1;
	for (int i = 0; i < N; i++) {
		s = s * schet[i];
	}
	return s;
}



int main()
{
	setlocale(LC_ALL, "Rus");

	const int N = 4;
	int M[N][N];
	int schet[N];
	int rast[N];


	queue<int> queue;



	/*int** M = new int* [N];
	for (int i = 0; i < N; i++) {
		M[i] = new int[N];
	}*/

	for (int i = 0; i < N; i++) {
		schet[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		rast[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = 0;
		}
	}

	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = rand() % 6;
		}
	}*/

	M[0][1] = 3;
	M[0][2] = 2;
	M[0][3] = 4;
	M[1][2] = 2;
	M[3][2] = 5;
	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) { M[i][j] = 0; }
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	int s = 0, s1 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s = s + M[i][j];
			s1 = s1 + M[j][i];
		}
		if ((s == 0) && (s1 == 0)) {
			schet[i]++;
		}
		s = 0;
		s1 = 0;
	}

	int versh1, versh2;
	cout << "Введите вершины, расстояние между которыми необходимо узнать" << "\n";
	cin >> versh1 >> versh2;

	while (1) {
		for (int i = 0; i < N; i++) {
			if (M[versh1][i] > 0) {
				schet[versh1] = 1;
				queue.push(versh1);
				break;
			}
			if (schet[versh1] == 1) { break; }
		}
		if (schet[versh1] == 0) {
			cout << "Вершины не существует или она изолирована." << "\n" << "Введите данные еще раз" << "\n";
			cin >> versh1;
		}
		else { break; }

	}


	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (M[i][j] > 0) {
				schet[i] = 1;
				//cout << i + 1 << "\t";
				queue.push(i);
				break;
			}
		}
		if (schet[i] == 1) { break; }
	}
	*/
	while (mult(schet, N) != 1) {
		for (int i = 0; i < N; i++) {
			s = M[queue.front()][i];
			if (M[queue.front()][i] > 0) {
				if (schet[i] != 1) {
					schet[i]++;
					rast[i] = rast[queue.front()] + M[queue.front()][i];
					//cout << i + 1 << "\t";
					queue.push(i);
				}
			}
		}
		queue.pop();
	}
	cout << "\n";

	cout << "Расстояние между вершина равно" << "\t" << rast[versh2] << "\n";

	/*for (int a = 0; a < N; a++) {
		delete[] M[a];
	}*/

}
