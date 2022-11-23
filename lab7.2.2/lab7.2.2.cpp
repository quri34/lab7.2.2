// Рекурсивний
#include <iostream>
#include <iomanip>

using namespace std;

void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < n - 1)
		CreateRow(a, rowNo, n, Low, High, colNo + 1);
}

void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, n, Low, High, 0);
	if (rowNo < k - 1)
		CreateRows(a, k, n, Low, High, rowNo + 1);
}

void PrintRow(int** a, const int rowNo, const int n, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, rowNo, n, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int k, const int n, int rowNo)
{
	PrintRow(a, rowNo, n, 0);
	if (rowNo < k - 1)
		PrintRows(a, k, n, rowNo + 1);
	else
		cout << endl;
}
void Search1(int** a, int k, int j, int& max, int now)
{
	if (j < k)
	{
		if (max = a[j][now]);
			
		Search1(a, k, j + 1, max, now);
	}
}
void Search(int** a, int k, int n, int j, int now, int& S)
{
	if (now < n)
	{
		int max = a[0][now];
		Search1(a, k, j, max, now);
		S += max;
		Search(a, k, n, j, now + 2, S);
	}
}

int main()
{

	srand((unsigned)time(NULL));

	int Low = 1, High = 30;
	int k, n, S = 0;

	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;

	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];

	CreateRows(a, k, n, Low, High, 0);
	PrintRows(a, k, n, 0);
	Search(a, k, n, 1, 1, S);
	cout << "S=" << S;

	return 0;
}