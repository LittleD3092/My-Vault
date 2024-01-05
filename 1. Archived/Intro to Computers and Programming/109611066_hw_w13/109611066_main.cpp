#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "109611066_struct.h"

int main()
{
    System system;
    System__construct(&system);
    Branches branches;
    Branches__construct(&branches);
    Branches__addBranch(&(branches), "Taipei Xinyi");
    Branches__addBranch(&(branches), "Taipei Fuxing");
    Branches__addBranch(&(branches), "Taipei Tienmu");
    Branches__addBranch(&(branches), "Taipei Taipei 101");
    Branches__addBranch(&(branches), "Taipei Nanxi");
    Branches__addBranch(&(branches), "Taipei A4");
    Branches__addBranch(&(branches), "Taipei A13");
    Branches__addBranch(&(branches), "Taipei Xinsheng");
    Branches__addBranch(&(branches), "Taipei Banqiao");
    Branches__addBranch(&(branches), "Hsinchu");
    Branches__addBranch(&(branches), "Taichung");
    Branches__addBranch(&(branches), "Kaohsiung");
    System__printWelcome();
    while(system.rootChoice != 3)
    {
        System__promptRootChoice(&system);
        if(system.rootChoice == 1)
        {
            int err = System__promptID(&system);
            if(err != 0)
                continue;
            System__promptPassword(&system);
            err = System__login(&system);
            if(err != 0)
                continue;
            
            while(system.actionChoice != 3)
            {
                System__promptAction(&system);
                if(system.actionChoice == 1)
                {
                    System__promptBranch(&system, &branches);
                    int err = System__promptDate(&system);
                    if(err != 0)
                        continue;
                    System__promptHour(&system);
                    System__promptNumCustomers(&system);
                    System__makeReservation(&system, &branches);
                }
                else if(system.actionChoice == 2)
                {
                    printf("\n");
                    Entries__queryID(&(system.entries), &branches, system.currentID.str);
                    System__promptCancelReservation(&system);
                }
                else if(system.actionChoice == 3)
                {
                    system.actionChoice = 0;
                    break;
                }
                else
                {
                    printf("Invalid choice!\n");
                }
            }
        }
        else if(system.rootChoice == 2)
        {
            int err = System__promptID(&system);
            if(err != 0)
                continue;
            System__promptPassword(&system);
            System__promptName(&system);
            System__register(&system);
        }
        else if(system.rootChoice == 3)
        {
            printf("\nThank you! Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice!\n");
        }
    }
    System__destruct(&system);
    return 0;
}