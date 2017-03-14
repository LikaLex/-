#include "stdafx.h"
#include <iostream>

using namespace std;

void keep_window_open()
{
	cin.clear();
	cin.ignore(0xFFFFFFFF, '\n');
	cin.get();
}


void connection_input(int &win)
{
	do
	{
		cout << "Enter the number of connections: ";
		cin >> win;
		if (cin.fail())
			break;
	} while (win <= 0);
	return;
}

void floor_input(int &dw)
{
	do
	{
		cout << "Enter the number of floors: ";
		cin >> dw;
		if (cin.fail())
			break;
	} while (dw <= 0);
	return;
}

void size_input(double &length, double &width)
{
	do
	{
		cout << "Enter the height of the ceilings: ";
		cin >> length;
		if (cin.fail())
			break;
	} while (length <= 0.0);
	do
	{
		cout << "Enter the thickness of the house ceilings: ";
		cin >> width;
		if (cin.fail())
			break;
	} while (width <= 0.0);
	return;
}

void distance_input(int &d)
{
	do
	{
		cout << "Enter the average distance from the connection point to the wiring closet on the floor: ";
		cin >> d;
		if (cin.fail())
			break;
	} while (d <= 0);
	return;
}


int project_calc( double sum, int dw)
{


	if (sum > 0 && dw > 0)
	{
		double five{ 0 };
		five = (sum + (53 * dw));
		return five;
	}
	else
		return 0;
}

int cabellength_calc( int dw, int d, int win, double lenght, double widht)
{


	if (dw > 0 && d > 0 && win > 0 && lenght> 0 && widht > 0)
	{
		double s{ 0 };
		s = (dw * lenght + widht + d * win);
		return s;
	}
	else
		return 0;
}

double equipment_calc( double s, int win, int dw)
{

	
	if (win > 0 && s > 0 && dw > 0)
	{
		double sum{ 0 };
		sum = (s * 1.5) + (win * 3) + (dw * 110);
		return sum;

	}
	else
		return 0;
}



int allproject_calc(double sum, double five)
{


	if (sum > 0 && five > 0)
	{
		double tubes{0}
		int tubes{ 0 };
		tubes = (five + sum);
		return tubes;
	}
	else
		return 0;
}

int main()
{
	double length{ 0.0 };
	double width{ 0.0 };
	int win{ 0 };
	int dw{ 0 };
	int n{ 0 };
	int d{ 0 };


	cout << "Selection menu:\n";
	cout << "1. Input  the number of connections.\n";
	cout << "2. Input the number of floors.\n";
	cout << "3. Entering height ceilings and thick slabs of house.\n";
	cout << "4. Enter the average distance from the connection point to the wiring closet on each floor.\n";
	cout << "5. Calculating the cost of network design.\n";
	cout << "6. The calculation of the total cable length..\n";
	cout << "7. The calculation of the cost of the necessary network equipment.\n";
	cout << "8. Calculation of the total project cost.\n";
	cout << "9. Brief description of the company and contacts.\n";
	cout << "10. Exit the program.\n";

	short choice;
	cout << "Input: ";
	while (cin >> choice && choice != 10)
	{
		switch (choice)
		{
		case 1: connection_input(win); break;
		case 2: floor_input(dw); break;
		case 3: size_input(length, width); break;
		case 4: distance_input(d); break;
		case 5: {
			if (project_calc(five, sum, dw) > 0)
				cout << "The cost of network design = " << project_calc(five, sum, dw) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 6: {
			if (cabellength_calc(s, dw, d, win, length, width) > 0)
				cout << "The total length of the cable= " << cabellength_calc(s, dw, d, win, length, width) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 7: {
			if (equipment_calc(sum, s, win, dw) > 0)
				cout << "The cost of the necessary network equipment = " << equipment_calc(sum, s, win, dw) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 8: {
			if (allproject_calc(sum, five) > 0)
				cout << "The total cost of the project = " << allproject_calc(sum, five) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}



		default: cout << "Incorrect input" << endl; break;
		}
		cout << "Input: ";
	}

	cout << "Terminating...";

	keep_window_open();

	return 0;
}