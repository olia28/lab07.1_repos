// Lab_7_1.cpp
// < Кліщевська, Ольга >
// Лабораторна робота № 7.1.
// Пошук заданих елементів та впорядкування рядків / стовпчиків матриці.
// Варіант 10
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** q, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** q, const int rowCount, const int colCount);
void Sort(int** q, const int rowCount, const int colCount);
void Change(int** q, const int col1, const int col2, const int rowCount);
void Calc(int** q, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -26;
	int High = 23;
	int rowCount = 8;
	int colCount = 6;
	int** q = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		q[i] = new int[colCount];
	Create(q, rowCount, colCount, Low, High);
	Print(q, rowCount, colCount);
	Sort(q, rowCount, colCount);
	Print(q, rowCount, colCount);
	int S = 0;
	int k = 0;
	Calc(q, rowCount, colCount, S, k);
	cout << "S = " << S << endl;
	cout << "k = " << k << endl;
	Print(q, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] q[i];
	delete[] q;
	return 0;
}
void Create(int** q, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			q[i][j] = Low + rand() % (High - Low +1);
}
void Print(int** q, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << q[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** q, const int rowCount, const int colCount)
{
	for (int j0 = 0; j0 < colCount - 1; j0++)
		for (int j1 = 0; j1 < colCount - j0 - 1; j1++)
			if ((q[0][j1] > q[0][j1 + 1])
				||
				(q[0][j1] == q[0][j1 + 1] &&
					q[1][j1] < q[1][j1 + 1])
				||
				(q[0][j1] == q[0][j1 + 1] &&
					q[1][j1] == q[1][j1 + 1] &&
					q[2][j1] > q[2][j1 + 1]))
				Change(q, j1, j1 + 1, rowCount);
}
void Change(int** q, const int col1, const int col2, const int colCount)
{
	int tmp;
	for (int i = 0; i < colCount; i++)
	{
		tmp = q[i][col1];
		q[i][col1] = q[i][col2];
		q[i][col2] = tmp;
	}
}
void Calc(int** q, const int rowCount, const int colCount, int& S, int& k)
{
	S = 0;
	k = 0;
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			if (!((q[i][j] % 2 == 0) && (q[i][j] > 0)))
			{
				S += q[i][j];
				k++;
				q[i][j] = 0;
			}
}
