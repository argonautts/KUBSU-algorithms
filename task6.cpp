#include <iostream>
using namespace std;

int** createMatrix(int n)
{
	int** Matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		Matrix[i] = new int[n];
	}
	return Matrix;
}

int** requestMatrix(int** Matrix, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> Matrix[i][j];
		}
	}
	return Matrix;
}

int checkMatrix(int** pobMatrix, int n)
{
	int i, result = 1;
	for (i = 0; i < n; i++)
	{
		if (pobMatrix[i][i] != 1 || pobMatrix[n - i - 1][i] != 1)  result = 0;
	}
	return result;
}

void printMatrix(int** Matrix, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cout << Matrix[i][j] << " ";
		}
		cout << endl;
	}
}

int createPobMatrix(int** Matrix, int matrixSize, int n)
{
	int** pobMatrix = createMatrix(n);
	int i, j, k, z, I, J, summ = 0;
	for (i = 0; i <= matrixSize - n; i++)
	{
		for (j = 0; j <= matrixSize - n; j++)
		{
			I = 0; J = 0;
			//Выше мы объявляем глобальную проходку по матрице, ниже - локальную, для задания побочной матрицы, которую мы и будем обследовать.
			for (k = i; k < i + n; k++)
			{
				for (z = j; z < j + n; z++)
				{
					pobMatrix[I][J] = Matrix[k][z];
					J++;
				}
				I++;
				J = 0;
			}
			cout << i << j << endl;
			printMatrix(pobMatrix, n);
			cout << endl;
			summ += checkMatrix(pobMatrix, n);
		}

	}
	return summ;
}

void main()
{
	setlocale(LC_ALL, "RU");
	int n, i;
	cout << "Введите размер матрицы:" << endl;
	cin >> n;
	if (n >= 3) {
		int** Matrix = createMatrix(n);
		cout << "Введите рисунок:" << endl;
		Matrix = requestMatrix(Matrix, n);
		int counter = 0;
		for (i = 3; i <= n; i += 2)
		{
			counter += createPobMatrix(Matrix, n, i);
		}
		cout << "Минимальный размер: 3" << endl;
		cout << "Максимальный размер: " << n << endl;
		cout << "Ответ:" << counter;
	}
	else {
		cout << "Минимальный размер матрицы должен быть 3" << endl;
	}
}
