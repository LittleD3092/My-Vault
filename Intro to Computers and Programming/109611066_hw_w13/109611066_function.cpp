#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "109611066_struct.h"

int checkID(char *id)
{
#ifdef VERBOSE
    printf("id: %s\n", id);
#endif
    if(strlen(id) != 10)
        return -1;

    int idDigits[11];
    const int weight[10] = {1, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    const int dictionary[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18,
                                19, 20, 21, 22, 35, 23, 24, 25, 26, 27,
                                28, 29, 32, 30, 31, 33};
    idDigits[0] = dictionary[id[0] - 'A'] / 10;
    idDigits[1] = dictionary[id[0] - 'A'] % 10;
    for(int i = 1; i < 10; i++)
        idDigits[i + 1] = id[i] - '0';
#ifdef VERBOSE
    printf("idDigits: ");
    for(int i = 0; i < 11; i++)
        printf("%d ", idDigits[i]);
    printf("\n");
#endif
    int sum = 0;
    for(int i = 0; i < 10; i++)
        sum += idDigits[i] * weight[i];
    if(sum % 10 + idDigits[10] != 10)
        return -1;

    return 0;
}

void cleanInput()
{
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

int digits(int n)
{
    int count = 0;
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

void String__construct(String* string)
{
    string->str = (char*)malloc(sizeof(char));
    string->str[0] = '\0';
    string->length = 0;
    string->capacity = 1;
}

void String__destruct(String* string)
{
    free(string->str);
}

void String__input(String* string)
{
    string->length = 0;
    char c;
    while((c = getchar()) != '\n')
    {
        if(string->length + 1 >= string->capacity)
            String__resize(string, string->capacity * 2);
        string->str[string->length++] = c;
    }
    string->str[string->length] = '\0';
}

void String__resize(String* string, int newCapacity)
{
    if(newCapacity < string->length + 1)
        return;
    char* newStr = (char*)malloc(sizeof(char) * newCapacity);
    for(int i = 0; i < string->length; i++)
        newStr[i] = string->str[i];
    free(string->str);
    string->str = newStr;
    string->capacity = newCapacity;
}

void String__copy(String* string, const char* str)
{
    int length = strlen(str);
    if(length + 1 > string->capacity)
        String__resize(string, length + 1);
    for(int i = 0; i < length; i++)
        string->str[i] = str[i];
    string->str[length] = '\0';
    string->length = length;
}

void String__clean(String* string)
{
    string->length = 0;
    string->str[0] = '\0';
}

void User__construct(User* user)
{
    String__construct(&(user->id));
    String__construct(&(user->password));
    String__construct(&(user->name));
}

void User__destruct(User* user)
{
    String__destruct(&(user->id));
    String__destruct(&(user->password));
    String__destruct(&(user->name));
}

void Users__construct(Users* users)
{
    users->users = (User*)malloc(sizeof(User));
    users->length = 0;
    users->capacity = 1;
}

void Users__destruct(Users* users)
{
    for(int i = 0; i < users->length; i++)
        User__destruct(&(users->users[i]));
    free(users->users);
}

int Users__addUser(Users* users, const char* id, const char* password, const char* name)
{
    if(Users__at(users, id) != 0)
        return -1;
    if(users->length + 1 >= users->capacity)
        Users__resize(users, users->capacity * 2);
    User__construct(&(users->users[users->length]));
    String__copy(&(users->users[users->length].id), id);
    String__copy(&(users->users[users->length].password), password);
    String__copy(&(users->users[users->length].name), name);
    users->length++;
    return 0;
}

User* Users__at(Users* users, const char* id)
{
    for(int i = 0; i < users->length; i++)
        if(strcmp(users->users[i].id.str, id) == 0)
            return &(users->users[i]);
    return 0;
}

void Users__resize(Users* users, int newCapacity)
{
    if(newCapacity < users->length)
        return;
    User* newUsers = (User*)malloc(sizeof(User) * newCapacity);
    for(int i = 0; i < users->length; i++)
        newUsers[i] = users->users[i];
    free(users->users);
    users->users = newUsers;
    users->capacity = newCapacity;
}

void Date__construct(Date* date)
{
    date->year = 0;
    date->month = 0;
    date->day = 0;
    date->hour = 0;
}

void Date__destruct(Date* date)
{
}

void Date__copy(Date* date, int year, int month, int day, int hour)
{
    date->year = year;
    date->month = month;
    date->day = day;
    date->hour = hour;
}

void Date__fetchNow(Date* date)
{
    time_t now = time(0);
    struct tm* t = localtime(&now);
    Date__copy(date, t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, t->tm_hour);
}

void Date__addDay(Date* date, int day)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30,
                           31, 31, 30, 31, 30, 31};
    if(date->year % 4 == 0 && date->year % 100 != 0 || date->year % 400 == 0)
        daysInMonth[1] = 29;
    date->day += day;
    while(date->day > daysInMonth[date->month - 1])
    {
        date->day -= daysInMonth[date->month - 1];
        date->month++;
        if(date->month > 12)
        {
            date->month -= 12;
            date->year++;
        }
    }
}

void Date__print(Date* date)
{
    printf("%04d/%02d/%02d:%02d", date->year, date->month, date->day, date->hour);
}

void Date__printWithoutHour(Date* date)
{
    printf("%04d/%02d/%02d", date->year, date->month, date->day);
}

void Branch__construct(Branch* branch)
{
    String__construct(&(branch->name));
}

void Branch__destruct(Branch* branch)
{
    String__destruct(&(branch->name));
}

void Branch__copy(Branch* branch, const char* name)
{
    String__copy(&(branch->name), name);
}

void Branches__construct(Branches* branches)
{
    branches->branches = (Branch*)malloc(sizeof(Branch));
    branches->length = 0;
    branches->capacity = 1;
}

void Branches__destruct(Branches* branches)
{
    for(int i = 0; i < branches->length; i++)
        Branch__destruct(&(branches->branches[i]));
    free(branches->branches);
}

void Branches__resize(Branches* branches, int newCapacity)
{
    if(newCapacity < branches->length)
        return;
    Branch* newBranches = (Branch*)malloc(sizeof(Branch) * newCapacity);
    for(int i = 0; i < branches->length; i++)
        newBranches[i] = branches->branches[i];
    free(branches->branches);
    branches->branches = newBranches;
    branches->capacity = newCapacity;
}

void Branches__addBranch(Branches* branches, const char* name)
{
    if(branches->length >= branches->capacity)
        Branches__resize(branches, branches->capacity * 2);
    Branch__construct(&(branches->branches[branches->length]));
    Branch__copy(&(branches->branches[branches->length]), name);
    branches->length++;
}

void Branches__print(Branches* branches)
{
    int indexSpace = digits(branches->length);
    for(int i = 0; i < branches->length; i++)
    {
        for(int j = 0; j < indexSpace - digits(i + 1); j++)
            printf(" ");
        printf("%d. %s\n", i + 1, branches->branches[i].name.str);
    }
}

void Entry__construct(Entry* entry)
{
    String__construct(&(entry->id));
    entry->branch = 0;
    Date__construct(&(entry->date));
    entry->numCustomers = 0;
}

void Entry__destruct(Entry* entry)
{
    String__destruct(&(entry->id));
    Date__destruct(&(entry->date));
}

void Entry__copy(Entry* entry, const char* id, int branch, Date date, int numCustomers)
{
    String__copy(&(entry->id), id);
    entry->branch = branch;
    Date__copy(&(entry->date), date.year, date.month, date.day, date.hour);
    entry->numCustomers = numCustomers;
}

void Entry__print(Entry* entry, Branches* branches)
{
    int space[4] = {20, 15, 8, 20};
    printf("%*s%*s%*s%*s\n", space[0], "Branch", space[1], "Date", space[2], "Hour", space[3], "No of Customers");
    printf("%*s%*s%04d-%02d-%02d%*d%*d\n", space[0], branches->branches[entry->branch - 1].name.str, space[1] - 10, " ", entry->date.year, entry->date.month, entry->date.day, space[2], entry->date.hour, space[3], entry->numCustomers);
}

void Entries__construct(Entries* entries)
{
    entries->entries = (Entry*)malloc(sizeof(Entry));
    entries->length = 0;
    entries->capacity = 1;
}

void Entries__destruct(Entries* entries)
{
    for(int i = 0; i < entries->length; i++)
        Entry__destruct(&(entries->entries[i]));
    free(entries->entries);
}

void Entries__resize(Entries* entries, int newCapacity)
{
    if(newCapacity < entries->length)
        return;
    Entry* newEntries = (Entry*)malloc(sizeof(Entry) * newCapacity);
    for(int i = 0; i < entries->length; i++)
        newEntries[i] = entries->entries[i];
    free(entries->entries);
    entries->entries = newEntries;
    entries->capacity = newCapacity;
}

void Entries__addEntry(Entries* entries, const char* id, int branch, Date date, int numCustomers)
{
    if(entries->length >= entries->capacity)
        Entries__resize(entries, entries->capacity * 2);
    Entry__construct(&(entries->entries[entries->length]));
    Entry__copy(&(entries->entries[entries->length]), id, branch, date, numCustomers);
    entries->length++;
}

void Entries__queryID(Entries* entries, Branches* branches, const char* id)
{
    int space[4] = {20, 15, 8, 20};
    int count = 0;
    int indexSpace = 3;
    for(int i = 0; i < 4; i++)
        space[i] += 3;
    printf("%*s%*s%*s%*s%*s\n", indexSpace, " ", space[0], "Branch", space[1], "Date", space[2], "Hour", space[3], "No of Customers");
    int index = 1;
    for(int i = 0; i < entries->length; i++)
    {
        if(strcmp(entries->entries[i].id.str, id) == 0)
        {
            printf("%2d.%*s%*s%04d-%02d-%02d%*d%*d\n", index, space[0], branches->branches[entries->entries[i].branch - 1].name.str, space[1] - 10, " ", entries->entries[i].date.year, entries->entries[i].date.month, entries->entries[i].date.day, space[2], entries->entries[i].date.hour, space[3], entries->entries[i].numCustomers);
            index++;
        }
    }
}

void System__construct(System* system)
{
    Users__construct(&(system->users));
    Entries__construct(&(system->entries));

    Date__construct(&(system->nowDate));

    system->rootChoice = 0;
    system->actionChoice = 0;
    
    String__construct(&(system->currentID));
    String__construct(&(system->currentPassword));
    String__construct(&(system->currentName));
    
    system->currentBranch = 0;
    Date__construct(&(system->currentDate));
    system->currentNumCustomers = 0;
}

void System__destruct(System* system)
{
    Users__destruct(&(system->users));
    String__destruct(&(system->currentID));
    String__destruct(&(system->currentPassword));
    String__destruct(&(system->currentName));
}

void System__printWelcome()
{
    printf("Welcome to the Din Tai Fung Reservation System!\n");
}

void System__promptRootChoice(System* system)
{
    printf("\n1. Login\n");
    printf("2. Registration\n");
    printf("3. End\n");
    printf("\nEnter your choice (1~3): ");
    scanf("%d", &(system->rootChoice));
    cleanInput();
}

int System__promptID(System* system)
{
    printf("\nPlease enter your ID number: ");
    String__input(&(system->currentID));
    if(checkID(system->currentID.str) != 0)
    {
        printf("Invalid ID number. Please try again.\n");
        return -1;
    }
    return 0;
}

void System__promptPassword(System* system)
{
    printf("Enter your password: ");
    String__input(&(system->currentPassword));
}

void System__promptName(System* system)
{
    printf("Enter your name: ");
    String__input(&(system->currentName));
}

void System__register(System* system)
{
    int err = Users__addUser(&(system->users), system->currentID.str, system->currentPassword.str, system->currentName.str);
    String__clean(&(system->currentID));
    String__clean(&(system->currentPassword));
    String__clean(&(system->currentName));
    if(err == -1)
        printf("ID number already exists. Please try again.\n");
    else
        printf("Registration successful!\n");
}

int System__login(System* system)
{
    User* user = Users__at(&(system->users), system->currentID.str);
    if(user == 0)
    {
        printf("ID number does not exist. Please try again.\n");
        String__clean(&(system->currentID));
        String__clean(&(system->currentPassword));
        String__clean(&(system->currentName));
        return -1;
    }
    if(strcmp(user->password.str, system->currentPassword.str) != 0)
    {
        printf("Wrong password. Please try again.\n");
        String__clean(&(system->currentID));
        String__clean(&(system->currentPassword));
        String__clean(&(system->currentName));
        return -1;
    }
    String__copy(&(system->currentName), user->name.str);
    printf("Login!\n");
    return 0;
}

void System__promptAction(System* system)
{
    printf("\n1. Make Reservation\n");
    printf("2. Reservation Enquiry/Canceling\n");
    printf("3. Log Out\n");
    printf("\nEnter your choice (1~3): ");
    scanf("%d", &(system->actionChoice));
}

void System__promptBranch(System* system, Branches* branches)
{
    printf("Please choose the branch (1-%d):\n", branches->length);
    Branches__print(branches);
    printf("\nEnter your choice (1-%d): ", branches->length);
    scanf("%d", &(system->currentBranch));
}

int System__promptDate(System* system)
{
#ifdef SET_DATE_CURRENT
    Date__fetchNow(&(system->nowDate));
#else
    Date__copy(&(system->nowDate), 2023, 12, 5, 17);
#endif
    printf("\nThe current date is ");
    Date__print(&(system->nowDate));
    printf("\n");
    printf("Available days:\n");
    Date date;
    Date__copy(&date, system->nowDate.year, system->nowDate.month, system->nowDate.day, system->nowDate.hour);
    if(date.hour >= 23)
        Date__addDay(&date, 1);
    for(int i = 0; i < 7; i++)
    {
        printf("%d. ", i + 1);
        Date__printWithoutHour(&date);
        printf("\n");
        Date__addDay(&date, 1);
    }
    Date__destruct(&date);
    printf("\nEnter your choice (0 to end): ");
    int choice;
    scanf("%d", &choice);
    if(choice == 0)
        return -1;
    Date__copy(&(system->currentDate), system->nowDate.year, system->nowDate.month, system->nowDate.day, system->nowDate.hour);
    Date__addDay(&(system->currentDate), choice - 1);
    return 0;
}

void System__promptHour(System* system)
{
    int startHour;
    if(system->currentDate.hour >= 23)
        startHour = 0;
    else
        startHour = system->currentDate.hour + 1;
    if(system->currentDate.day != system->nowDate.day)
        startHour = 0;
    printf("\nEnter hour (%d~23):", startHour);
    scanf("%d", &(system->currentDate.hour));
    cleanInput();
}

int System__promptNumCustomers(System* system)
{
    printf("\nEnter number of customers (1~30, 0 to end):");
    scanf("%d", &(system->currentNumCustomers));
    if(system->currentNumCustomers == 0)
        return -1;
    cleanInput();
    return 0;
}

void System__makeReservation(System* system, Branches* branches)
{
    Entries__addEntry(&(system->entries), system->currentID.str, system->currentBranch, system->currentDate, system->currentNumCustomers);
    printf("\n");
    Entry__print(&(system->entries.entries[system->entries.length - 1]), branches);
    printf("\nReservation successful!\n");
}

void System__promptCancelReservation(System* system)
{
    printf("\nChoose the reservation to cancel (0: keep all reservations): ");
    int choice;
    scanf("%d", &choice);
    if(choice == 0)
        return;
    for(int i = 0; i < system->entries.length; i++)
    {
        if(strcmp(system->entries.entries[i].id.str, system->currentID.str) == 0)
        {
            if(choice == 1)
            {
                String__clean(&(system->entries.entries[i].id));
                printf("\nReservation deleted!\n");
                return;
            }
            choice--;
        }
    }
}