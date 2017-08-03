#include "hotel.h"

void WriteRoomCount(rooms &availableRooms){
    cout << "Number of available rooms of standart type: " << availableRooms.standart << endl;
    cout << "Number of available rooms of half lux: " << availableRooms.juniorSuite << endl;
    cout << "Number of available rooms of lux: " << availableRooms.suite << endl;
    cout << "Number of available rooms of king  type: " << availableRooms.royalSuite << endl;

    _getch();
    system("cls");
}

void EarlyDeparture(list<guestInformation> &guestList, rooms &availableRooms, rooms &occupiedRooms){
    WriteGuestList(guestList);
    cout << "Enter passport ID:\n";
    int passportNumber;
    cin >> passportNumber;
    for (list<guestInformation>::iterator it = guestList.begin(); it != guestList.end(); ++it)
        if ((*it).passportNumber == passportNumber){
            WriteAccomadationCost((*it).roomType, (*it).dateOfArrival, (*it).departureDate);
            ChangeRoomsCount((*it).roomType, availableRooms, occupiedRooms);
            cout << endl;
            guestList.erase(it);

            _getch();
            system("cls");
            return;
        }
}

void FindGuest(list<guestInformation> &guestList){
    cout << "Choose seach field:\n";
    cout << "1. Surname\n";
    cout << "2. Name\n";
    cout << "3. Patronymic\n";
    cout << "4. passport ID\n";
    cout << "5. Number of room\n";
    cout << "6. Colonization date\n";
    cout << "7. Eviction date\n";
    int choice;
    cin >> choice;
    cout << "Enter the value of field: ";

    bool flag = true;
    int intTemp;
    char stringTemp[30];
    if (choice == 1 || choice == 2 || choice == 3 || choice == 6 || choice == 7)
        scanf("%s", stringTemp);
    else
        scanf("%d", &intTemp);
    system("cls");
    cout << "Suitable clients:\n";
    for (list<guestInformation>::iterator it = guestList.begin(); it != guestList.end(); ++it){
        switch (choice){
            case 1:
                StringCompare((*it).surname, stringTemp, it, flag);
                break;
            case 2:
                StringCompare((*it).name, stringTemp, it, flag);
                break;
            case 3:
                StringCompare((*it).patronymic, stringTemp, it, flag);
                break;
            case 4:
                IntCompare((*it).passportNumber, intTemp, it, flag);
                break;
            case 5:
                IntCompare((*it).roomNumber, intTemp, it, flag);
                break;
            case 6:
                StringCompare((*it).dateOfArrival, stringTemp, it, flag);
                break;
            case 7:
                StringCompare((*it).departureDate, stringTemp, it, flag);
                break;
        }
    }

    if (flag){
        system("cls");
        cout << "Clients not found!\n";
    }

    _getch();
    system("cls");
}

int GetTime(char *currentDate){
    struct tm *increaseDate;
    time_t timer = time(NULL);

    increaseDate = localtime(&timer);
    increaseDate->tm_mday = StringToInt(currentDate, 0, 1);
    increaseDate->tm_mon = StringToInt(currentDate, 3, 4) - 1;
    increaseDate->tm_year = StringToInt(currentDate, 6, 9) - 1900;
    timer = mktime(increaseDate);

    return timer;
}

int DaysCount(char *dateOfArrival, char *departureDate){
    return (GetTime(departureDate) - GetTime(dateOfArrival)) / (24 * 60 * 60) + 1;
}

void WriteAccomadationCost(int roomType, char *dateOfArrival, char *departureDate){
    cout << "The cost of living one day: " << 10 * roomType << " rubles.\n";
    cout << "All cost of living: " << 10 * roomType * DaysCount(dateOfArrival, departureDate) << " rubles.\n";
}

void ChangeRoomsCount(int roomType, rooms &availableRooms, rooms &occupiedRooms){
    switch (roomType){
        case 1:
            ++availableRooms.standart;
            --occupiedRooms.standart;
            break;
        case 2:
            ++availableRooms.juniorSuite;
            --occupiedRooms.juniorSuite;
            break;
        case 3:
            ++availableRooms.suite;
            --occupiedRooms.suite;
            break;
        case 4:
            ++availableRooms.royalSuite;
            --occupiedRooms.royalSuite;
            break;
    }
}

void DepartureGuests(list<guestInformation> &guestList, char *currentDate, rooms &availableRooms, rooms &occupiedRooms){
    system("cls");
    cout << "List of evicted people today:\n\n";
    bool flag = true;
    for (list<guestInformation>::iterator it = guestList.begin(); it != guestList.end();){
        if (!strcmp((*it).departureDate, currentDate)){
            WriteGuestInformation(*it);
            WriteAccomadationCost((*it).roomType, (*it).dateOfArrival, (*it).departureDate);
            ChangeRoomsCount((*it).roomType, availableRooms, occupiedRooms);
            cout << endl;
            it = guestList.erase(it);
            flag = false;
        }
        else
            ++it;
    }

    if (flag){
        system("cls");
        return;
    }

    _getch();
    system("cls");
}

void StringCompare(char *first, char *second, list<guestInformation>::iterator it, bool &flag){
    if (!strcmp(first, second)){
        WriteGuestInformation(*it);
        flag = false;
        cout << endl;
    }
}

void IntCompare(int first, int second, list<guestInformation>::iterator it, bool &flag){
    if (first == second){
        WriteGuestInformation(*it);
        flag = false;
        cout << endl;
    }
}

void WriteGuestInformation(guestInformation temp){
    cout << "Surname: " << temp.surname << endl;
    cout << "Name: " << temp.name << endl;
    cout << "Patronymic: " << temp.patronymic << endl;
    cout << "passport ID: " << temp.passportNumber << endl;

    cout << "Type of room: ";
    switch (temp.roomType){
        case 1: cout << "Standart type\n"; break;
        case 2: cout << "Half lux\n"; break;
        case 3: cout << "Lux\n"; break;
        case 4: cout << "King type\n"; break;
    }

    cout << "Number of room: " << temp.roomNumber << endl;
    cout << "Colonization date : " << temp.dateOfArrival << endl;
    cout << "Eviction date : " << temp.departureDate << endl;
}

void WriteGuestList(list<guestInformation> &guestList){
    guestInformation temp;
    int i = 0;
    for (list<guestInformation>::iterator it = guestList.begin(); it != guestList.end(); ++it){
        cout << "№" << ++i << endl;
        WriteGuestInformation(*it);
        cout << endl;
    }
}

int GetRoomType(rooms &availableRooms){
    cout << "Choose type:\n";
    cout << "1. Standart type(Free rooms: " << availableRooms.standart << ")\n";
    cout << "2. Half lux(Free rooms: " << availableRooms.juniorSuite << ")\n";
    cout << "3. Lux (Free rooms: " << availableRooms.suite << ")\n";
    cout << "4. King type(Free rooms: " << availableRooms.royalSuite << ")\n";

    int choice;
    cin >> choice;
    return choice;
}

int GetFreeRoomNumber(int roomType, list<guestInformation> &guestList, rooms &availableRooms, rooms &occupiedRooms){
    int count;
    switch (roomType){
        case 1:
            count = availableRooms.standart + occupiedRooms.standart;
            --availableRooms.standart;
            ++occupiedRooms.standart;
            break;
        case 2:
            count = availableRooms.juniorSuite + occupiedRooms.juniorSuite;
            --availableRooms.juniorSuite;
            ++occupiedRooms.juniorSuite;
            break;
        case 3:
            count = availableRooms.suite + occupiedRooms.suite;
            --availableRooms.suite;
            ++occupiedRooms.suite;
            break;
        case 4:
            count = availableRooms.royalSuite + occupiedRooms.royalSuite;
            --availableRooms.royalSuite;
            ++occupiedRooms.royalSuite;
            break;
    }

    int *usedRooms = new int[++count];
    for (int i = 1; i <= count; ++i){
        usedRooms[i] = 0;
    }
    for (list<guestInformation>::iterator it = guestList.begin(); it != guestList.end(); ++it){
        if ((*it).roomType == roomType) usedRooms[(*it).roomNumber] = 1;
    }
    int answer = 0;
    for (int i = 1; i <= count; ++i)
        if (!usedRooms[i]){
            answer = i;
            break;
        }

	delete usedRooms;
    return answer;
}

void AddGuest(list<guestInformation> &guestList, rooms &availableRooms, rooms &occupiedRooms, char *currentDate){
    guestInformation temp;

    if (!availableRooms.standart && !availableRooms.juniorSuite && !availableRooms.suite && !availableRooms.royalSuite){
        cout << "No free rooms!\n";
        return;
    }

    cout << "Enter surname:\n";
    cin >> temp.surname;
    system("cls");
    cout << "Enter name:\n";
    cin >> temp.name;
    system("cls");
    cout << "Enter patronymic:\n";
    cin >> temp.patronymic;
    system("cls");
    cout << "Enter passport ID:\n";
    cin >> temp.passportNumber;
    system("cls");

    temp.roomType = GetRoomType(availableRooms);
    temp.roomNumber = GetFreeRoomNumber(temp.roomType, guestList, availableRooms, occupiedRooms);
    strcpy(temp.dateOfArrival, currentDate);
    system("cls");

    cout << "Enter the departure date (Example 12.12.2016):\n";
    cin >> temp.departureDate;
    system("cls");

    guestList.push_back(temp);
}

int StringToInt(char *currentDate, int initialPosition, int finalPosition){
    int answer = 0;
    for (int i = finalPosition, tenDegree = 1; i >= initialPosition; --i, tenDegree *= 10){
        answer += tenDegree * (currentDate[i] - '0');
    }
    return answer;
}

void IncDate(char *currentDate){
    struct tm *increaseDate;
    time_t timer = time(NULL);

    increaseDate = localtime(&timer);
    increaseDate->tm_mday = StringToInt(currentDate, 0, 1);
    increaseDate->tm_mon = StringToInt(currentDate, 3, 4) - 1;
    increaseDate->tm_year = StringToInt(currentDate, 6, 9) - 1900;
    timer = mktime(increaseDate);
    timer += 24 * 60 * 60;
    increaseDate = localtime(&timer);

    char temp[11] = {NULL};
    strftime(temp, 11, "%d.%m.%Y", increaseDate);

    strcpy(currentDate, temp);
}
