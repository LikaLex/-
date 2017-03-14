// ConsoleApplication17.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;


static double factorial(int i)
{
	if (i == 0)
		return 1;
	else if (i > 0)
		return i * factorial(i - 1);
	else
		return 0;

}


int _tmain()
{
	int n;
	double composition = 1, sum = 0;
	printf("Input natural n : ");
	if (scanf_s("%d", &n) == 1)
	{
		if (n > 0 && n < 12)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= i; j++)
					composition *= factorial(i + j) / factorial(i);

				sum += composition;
					
			}


			printf("Your sum is equal to ");
			printf("%lf\n", sum);

		}
		else
			printf("Eroorchik!\n");
	}
	else
		printf("Error\n");
	_getch();
	return 0;
	

}