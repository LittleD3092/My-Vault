#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int max(int num1, int num2, int num3)
{
    if(num1 >= num2 && num1 >= num3)
        return num1;
    else if(num2 >= num1 && num2 >= num3)
        return num2;
    else // num3 >= num1 && num3 >= num2
        return num3;
}

int main()
{
    // divide and conquer
    // cache
    int dp[101][3];

    // set initial values
    // not possible
    for(int i = 0; i <= 3; i++)
        for(int j = 0; j <= 2; j++)
            dp[i][j] = -1;
    dp[7][0] = -1;
    dp[7][1] = -1;
    dp[7][2] = -1;
    
    // available
    dp[6][0] = 1; dp[6][1] = 0; dp[6][2] = 0;
    dp[5][0] = 0; dp[5][1] = 1; dp[5][2] = 0;
    dp[4][0] = 0; dp[4][1] = 0; dp[4][2] = 1;
    
    // calculate the rest of dp
    for(int i = 8; i <= 100; i++)
    {
        // three possible cases
        int buy6[3] = {
            dp[i - 6][0] + 1, 
            dp[i - 6][1], 
            dp[i - 6][2]
        };
        int buy5[3] = {
            dp[i - 5][0], 
            dp[i - 5][1] + 1, 
            dp[i - 5][2]
        };
        int buy4[3] = {
            dp[i - 4][0], 
            dp[i - 4][1], 
            dp[i - 4][2] + 1
        };

        // find the maximum
        int sumBuy6 = buy6[0] + buy6[1] + buy6[2];
        int sumBuy5 = buy5[0] + buy5[1] + buy5[2];
        int sumBuy4 = buy4[0] + buy4[1] + buy4[2];
        if(sumBuy6 >= sumBuy5 && sumBuy6 >= sumBuy4)
        {
            dp[i][0] = buy6[0];
            dp[i][1] = buy6[1];
            dp[i][2] = buy6[2];
        }
        else if(sumBuy5 >= sumBuy6 && sumBuy5 >= sumBuy4)
        {
            dp[i][0] = buy5[0];
            dp[i][1] = buy5[1];
            dp[i][2] = buy5[2];
        }
        else // sumBuy4 >= sumBuy6 && sumBuy4 >= sumBuy5
        {
            dp[i][0] = buy4[0];
            dp[i][1] = buy4[1];
            dp[i][2] = buy4[2];
        }
    }

    // input
    int dollars;
    scanf("%d", &dollars);

    // output
    // // to output the amount of each type pens,
    // // use the following code
    // printf("%d %d %d\n", dp[dollars][0], dp[dollars][1], dp[dollars][2]);
    
    // to output the total amount of pens,
    // use the following code
    printf("%d\n", dp[dollars][0] + dp[dollars][1] + dp[dollars][2]);

    return 0;
}