#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct AoT_Player
{
    int player_id;
    char name[10];
}player[] = {
    {2, "Mikasa"},
    {4, "Armin"},
    {1, "Eren"},
    {5, "Levi"},
    {3, "Christa"}
};
const int NUM_PLAYERS = 5;

int main()
{
    for(int i = 0; i < NUM_PLAYERS; i++)
    {
        for(int j = 0; j < NUM_PLAYERS - i - 1; j++)
        {
            if(player[j].player_id > player[j + 1].player_id)
            {
                AoT_Player tmp;
                tmp = player[j];
                player[j] = player[j + 1];
                player[j + 1] = tmp;
            }
        }
    }
    for(int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("{%d,%s}\n", player[i].player_id, player[i].name);
    }
    return 0;
}