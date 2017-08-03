#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	int str = 4, len = 255;
	cout << "Количество строк : " << str << endl;

	char **array = new char*[str];
	for (int i = 0; i < str; i++)
		array[i] = new char[len];


	for (int i = 0; i < str; i++)
		cin.getline(array[i], len);

	cout << "\nПеревернутые строки : \n";
	for (int i = str - 1; i >= 0; i--) {
		int length = 0;
		for (int j = 0; array[i][j] != '\0'; j++)
			length++;
		for (int j = length; j >= 0; j--)
			cout << array[i][j];
		cout << endl;
	}


	for (int i = 0; i < str; i++)
		delete[] array[i];
	delete[] array;

	_getch();
	return 0;
}
