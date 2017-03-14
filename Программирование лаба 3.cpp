#include "stdafx.h"
#include <conio.h>
#include <iostream>
void fill(int **, int); //Прототипы
void out(int **, int);
void key(int **, int, int **, int);


using namespace std;
int main()
{
	cout << "Attention! You have to enter the dimension of the matrices." << endl << "The dimension of the first matrix must be greater (!!!) than the dimension of the second matrix." << endl;
	int n, m;
	cout << "Size of matrix K: ";
	cin >> m;
	cout << "Size of matrix L: ";
	cin >> n;
	
		if (m <= 0 || n <= 0)
			cout << "It's fantastic! You introduced a negative! How witty! ";
		else if (m <= n) cout << "Nise. Can not you read...";


		else	
		{
			cout << "Whether it is possible to superimpose the matrix L on the matrix K" << endl << "so that to each unit of the matrix L there corresponds a zero in the matrix K." << endl;
			int **A = new int*[m]; // Объявляем массивы
			for (int i = 0; i < m; i++) {
				A[i] = new int[m];    //Объявляем подмассивы
			}

			int **B = new int*[n]; // Объявляем массивы
			for (int i = 0; i < n; i++) {
				B[i] = new int[n];    //Объявляем подмассивы
			}

			fill(A, m); //Заполнение
			fill(B, n);



			cout << "Matrix K: " << endl;
			out(A, m);   //Вывод исходного
			cout << endl;

			cout << "Matrix L: " << endl;
			out(B, n);
			cout << endl;

			key(A, m, B, n);
		}
	

	_getch();
	return 0;
}

void fill(int **array, int size)      //Передаем указатель на первый элемент
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {

			array[i][j] = rand() % 2;

		}
}
void out(int **array, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << array[i][j] << " ";
		}
		cout << endl;
	}
}

void key(int **array1, int size1, int **array2, int size2)
{
	int k = 0;
	int min = 0;
	int max = 1;

	{
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size1; j++) {
				for (int i = 0; i < size2; i++) {
					for (int j = 0; j < size2; j++) {
						if (array1[i][j] == max  && array2[i][j] == min) {
							array1[i][j] = min;
							array2[i][j] = max;
							k++;
						}
						else if (array1[i][j] == min && array2[i][j] == max) {
							array1[i][j] = max;
							array2[i][j] = min;
							k++;
						}
						else  k--;
					}

				}
			}
		}

	}
	if (k == (size2 * size2))
		cout << "It's possible";
	else cout << " Ohh.. It's impossible";
}

