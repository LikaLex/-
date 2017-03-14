// ConsoleApplication18.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int socket(double e)
{


	printf("Ввод количества подключений :  ");
	scanf_s("%lf", &e);

}

	int floor(double n, double f)
	{
	

		printf("Ввод количества этажей :  ");
		scanf_s("%lf", &n);
		printf("Ввод количества квартир :  ");
		scanf_s("%lf", &f);
	}


	int home(double l, double p)
	{
		printf("Ввод высоты потолков :  ");
		scanf_s("%lf", &l);
		printf("Ввод толщины перекрытий дома :  ");
		scanf_s("%lf", &p);

	}



	int locker(double d)
	{

		printf(" Ввод среднего расстояния от точки подключения до распределительного шкафа на этаже:  ");
		scanf_s("%lf", &d);

	}


	int design(double pro, double sum, double n, double f)
	{
		printf(" Общая стоимость проектирования:  ");
		pro = (sum + 33 * n + 20 * n * f) * 0.3;
		scanf_s("%lf", &pro);

	}


	int extension(double s, double n, double l, double f, double p, double d, double e)
	{
		printf(" Общая длина кабеля:  ");
		s = n * l + f * p + f * d * e;
		scanf_s("%lf", &s);
	}

	int equipment(double sum, double s, double f, double e, double n)
	{
		double dlina, kol, shkaf;
		dlina = s * 1.5;
		kol = f * e * 3;
		shkaf = n * 110;
		printf(" Стоимость необходимого сетевого оборудования:  ");
		sum = dlina + kol + shkaf;
		scanf_s("%lf", &sum);
	}

	int price(double money, double sum, double pro)

	{
		printf(" Общая длина кабеля:  ");
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

