#include "hotel.h"
#include <locale.h>
#include <locale>
#include <clocale>
#include "fileInformation.h"
#include <Windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

void MainMenu(char *currentDate){
    cout << "Today: " << currentDate << "\n\n";
    cout << "Select the menu item:\n";
    cout << "1. Lodge(Add) a guest\n";
    cout << "2. To make an early daparture\n";
    cout << "3. Seach for a guest\n";
    cout << "4. List all guests\n";
    cout << "5. Display the number of available rooms\n";
    cout << "6. Go the next day\n";
    cout << "7. Enter the current date\n";
    cout << "0. Exit\n";
}

int main()
{
	setlocale(LC_CTYPE, "rus");
    setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы
    rooms availableRooms, occupiedRooms;
    list<guestInformation> guestList;
    int guestCount;
    char currentDate[11];

    LoadInformationFromFile(guestList, availableRooms, occupiedRooms, guestCount, currentDate);

    int choice;
    while (true){
        MainMenu(currentDate);
        cin >> choice;
        system("cls");
        switch(choice){
            case 1:
                AddGuest(guestList, availableRooms, occupiedRooms, currentDate);
                break;
            case 2:
                EarlyDeparture(guestList, availableRooms, occupiedRooms);
                break;
            case 3:
                FindGuest(guestList);
                break;
            case 4:
                WriteGuestList(guestList);
                _getch();
                system("cls");
                break;
            case 5:
                WriteRoomCount(availableRooms);
                break;
            case 6:
                IncDate(currentDate);
                DepartureGuests(guestList, currentDate, availableRooms, occupiedRooms);
                break;
            case 7:
                cout << "Enter the current date: ";
                scanf("%s", currentDate);
                DepartureGuests(guestList, currentDate, availableRooms, occupiedRooms);
                break;
            case 0:
                LoadInformationToFile(guestList, availableRooms, occupiedRooms, guestCount, currentDate);
                return 0;
        }
    }

    LoadInformationToFile(guestList, availableRooms, occupiedRooms, guestCount, currentDate);

    return 0;
}
