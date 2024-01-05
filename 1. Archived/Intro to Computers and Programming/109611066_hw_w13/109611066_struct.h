#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef _STRUCT_H_
#define _STRUCT_H_

// if this is not defined, the time is set to 2023/12/05:17
#define SET_DATE_CURRENT

// #define VERBOSE

int checkID(char *id);
void cleanInput();
int digits(int n);
int max(int num1, int num2);

typedef struct String
{
    char *str;
    int length;
    int capacity;
} String;
void String__construct(String *string);
void String__destruct(String *string);
void String__input(String *string);
void String__resize(String *string, int newCapacity);
void String__copy(String *string, const char *str);
void String__clean(String *string);

typedef struct User
{
    String id;
    String password;
    String name;
} User;
void User__construct(User *user);
void User__destruct(User *user);

typedef struct Users
{
    User *users;
    int length;
    int capacity;
} Users;
void Users__construct(Users *users);
void Users__destruct(Users *users);
int Users__addUser(Users *users, const char* id, const char* password, const char* name);
User* Users__at(Users *users, const char* id);
void Users__resize(Users *users, int newCapacity);

typedef struct Date
{
    int year;
    int month;
    int day;
    int hour;
} Date;
void Date__construct(Date *date);
void Date__destruct(Date *date);
void Date__copy(Date *date, int year, int month, int day, int hour);
void Date__fetchNow(Date *date);
void Date__addDay(Date *date, int day);
void Date__print(Date *date);
void Date__printWithoutHour(Date *date);

typedef struct Branch
{
    String name;
} Branch;
void Branch__construct(Branch *branch);
void Branch__destruct(Branch *branch);
void Branch__copy(Branch *branch, const char* name);

typedef struct Branches
{
    Branch *branches;
    int length;
    int capacity;
} Branches;
void Branches__construct(Branches *branches);
void Branches__destruct(Branches *branches);
void Branches__resize(Branches *branches, int newCapacity);
void Branches__addBranch(Branches *branches, const char* name);
void Branches__print(Branches *branches);

typedef struct Entry
{
    String id;
    int branch;
    Date date;
    int numCustomers;
} Entry;
void Entry__construct(Entry *entry);
void Entry__destruct(Entry *entry);
void Entry__copy(Entry *entry, const char* id, int branch, Date date, int numCustomers);
void Entry__print(Entry *entry, Branches *branches);

typedef struct Entries
{
    Entry *entries;
    int length;
    int capacity;
} Entries;
void Entries__construct(Entries *entries);
void Entries__destruct(Entries *entries);
void Entries__resize(Entries *entries, int newCapacity);
void Entries__addEntry(Entries *entries, const char* id, int branch, Date date, int numCustomers);
void Entries__queryID(Entries *entries, Branches* branches, const char* id);

typedef struct System
{
    // database
    Users users;
    Entries entries;

    // constants
    Date nowDate;

    // user input
    int rootChoice;
    int actionChoice;
    
    // current user data
    String currentID;
    String currentPassword;
    String currentName;

    // action data
    int currentBranch;
    Date currentDate;
    int currentNumCustomers;
} System;
void System__construct(System *system);
void System__destruct(System *system);
void System__printWelcome();
void System__promptRootChoice(System *system);
int System__promptID(System *system);
void System__promptPassword(System *system);
void System__promptName(System *system);
void System__register(System *system);
int System__login(System *system);
void System__promptAction(System *system);
void System__promptBranch(System *system, Branches *branches);
int System__promptDate(System *system);
void System__promptHour(System *system);
int System__promptNumCustomers(System *system);
void System__makeReservation(System *system, Branches *branches);
void System__promptCancelReservation(System *system);

#endif