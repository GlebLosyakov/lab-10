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
	int rastmax[N];


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
		rastmax[i] = 0;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			M[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			M[i][j] = rand() % 6;
		}
	}

	/*M[0][1] = 0;
	M[0][2] = 4;
	M[1][3] = 3;
	M[1][3] = 1;
	M[2][4] = 1;*/

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			M[i][j] = M[j][i];
		}
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\n";
	}
	cout << "\n";

	int s = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			s = s + M[i][j];
		}
		if (s == 0) {
			schet[i]++;
		}
		s = 0;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (M[i][j] > 0) {
				schet[i] = 1;
				//cout << i + 1 << "\t";
				queue.push(i);
				break;
			}
		}
		if (queue.size() > 0) { break; }
	}


	while (queue.size() > 0) {
		for (int i = 1; i < N; i++) {
			//s = M[queue.front()][i];
			if (M[queue.front()][i] > 0) {
				rastmax[i] = rastmax[queue.front()] + M[queue.front()][i];
				if (schet[i] != 1) { rast[i] = rast[queue.front()] + M[queue.front()][i]; }
				if (schet[i] != 1){queue.push(i);}
				schet[i] = 1;
			}
		}
		queue.pop();
	}


	int max = -1, min = 10000;

	for (int i = 1; i < N; i++) {
		if (rast[i] < min) { min = rast[i]; }
		if (rastmax[i] > max) { max = rastmax[i]; }
	}

	/*for (int i = 0; i < N; i++) {
		cout << rast[i] << "\t";
	}
	cout << "\n";
	for (int i = 0; i < N; i++) {
		cout << rastmax[i] << "\t";
	}
	cout << "\n";*/

	cout << "Радиус равен" << "\t" << min << "\n";
	cout << "Диаметр равен" << "\t" << max << "\n";

	cout << "Центральные вершины:" << "\t";
	for (int i = 1; i < N; i++) {
		if (rast[i] == min) { cout << i << "\t"; }
	}
	cout << "\n" << "Переферийные вершины:" << "\t";
	for (int i = 0; i < N; i++) {
		if (rastmax[i] == max) { cout << i << "\t"; }
	}
	/*int max = -1;
	for (int i = 0; i < N; i++) {
		if (rast[i] > max) { max = rast[i]; }
	}
	cout << max << "\n";*/




	/*for (int a = 0; a < N; a++) {
		delete[] M[a];
	}*/

}
