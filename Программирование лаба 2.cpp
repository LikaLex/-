// ConsoleApplication18.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int socket(double e)
{


	printf("���� ���������� ����������� :  ");
	scanf_s("%lf", &e);

}

	int floor(double n, double f)
	{
	

		printf("���� ���������� ������ :  ");
		scanf_s("%lf", &n);
		printf("���� ���������� ������� :  ");
		scanf_s("%lf", &f);
	}


	int home(double l, double p)
	{
		printf("���� ������ �������� :  ");
		scanf_s("%lf", &l);
		printf("���� ������� ���������� ���� :  ");
		scanf_s("%lf", &p);

	}



	int locker(double d)
	{

		printf(" ���� �������� ���������� �� ����� ����������� �� ������������������ ����� �� �����:  ");
		scanf_s("%lf", &d);

	}


	int design(double pro, double sum, double n, double f)
	{
		printf(" ����� ��������� ��������������:  ");
		pro = (sum + 33 * n + 20 * n * f) * 0.3;
		scanf_s("%lf", &pro);

	}


	int extension(double s, double n, double l, double f, double p, double d, double e)
	{
		printf(" ����� ����� ������:  ");
		s = n * l + f * p + f * d * e;
		scanf_s("%lf", &s);
	}

	int equipment(double sum, double s, double f, double e, double n)
	{
		double dlina, kol, shkaf;
		dlina = s * 1.5;
		kol = f * e * 3;
		shkaf = n * 110;
		printf(" ��������� ������������ �������� ������������:  ");
		sum = dlina + kol + shkaf;
		scanf_s("%lf", &sum);
	}

	int price(double money, double sum, double pro)

	{
		printf(" ����� ����� ������:  ");
		money = sum + pro;
		scanf_s("%lf", &money);
	}

	int information()
	{

	}


	int exit()
	{

	}



	int _tmain()
	{
		double e, n, f, l, p, d, pro, s, sum, money;


		socket(e);
		floor(n);
		home(l, p);
		locker(d);
		design(pro, sum, n, f);
		extension(s, n, l, f, p, d, e);
		equipment( sum,  s,  f, e, n);
		price(money,  sum,  pro);
		information();
		exit();

		_getch();
		return 0;
	}

