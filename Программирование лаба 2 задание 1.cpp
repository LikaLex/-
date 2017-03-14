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


int project_calc(double sum, int dw)
{


	if (sum > 0 && dw > 0)
	{
		double five{ 0 };
		five = ((sum + (53 * dw)) * 0.3);
		return five;
	}
	else
		return 0;
}

int cabellength_calc(int dw, int d, int win, double lenght, double widht)
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

double equipment_calc(double s, int win, int dw)
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
		
		double tubes{ 0 };
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
			if (project_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), dw) > 0)
				cout << "The cost of network design = " << project_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), dw) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 6: {
			if (cabellength_calc(dw, d, win, length, width) > 0)
				cout << "The total length of the cable= " << cabellength_calc(dw, d, win, length, width) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 7: {
			if (equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw) > 0)
				cout << "The cost of the necessary network equipment = " << equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 8: {
			if (allproject_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), project_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), dw)) > 0)
				cout << "The total cost of the project = " << allproject_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), project_calc(equipment_calc(cabellength_calc(dw, d, win, length, width), win, dw), dw)) << endl;
			else
				cout << "And the data entered who will?" << endl;
			break;
		}
		case 9: {
			cout << " Mounting firm AMP " << endl << " Our firm is pleased to welcome you. " << endl << " We will carry out the work as soon as possible." << endl << " Contact phones : +375 (33) 555 - 5555, +375 (25) 555 - 5555, +375 (44) 555 - 5555" << endl << " Email : 555_55_55@gmail.com "<< endl;
			cout << " References: " << endl << " The cost of laying cable is 1 meter $ 1.5. " << endl << " Mounting the socket at the connection point - $ 1.  " << endl << " Crimping Connector - $ 1 (for each connection point requires 1 plug and 2 connectors). " << endl << " Installation of the cabinet on each floor - $ 33 (the cost of the cabinet - $ 110). " << endl << " Punching installation channel - $ 20. " << endl << " Network design costs the company 30 % of the total cost of equipment and labor." << endl;
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