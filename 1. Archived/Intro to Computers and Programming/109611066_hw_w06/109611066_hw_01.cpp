#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void morse_code_decoder() {
    fflush(stdin);

    char input[105];

    int i = 0;
    while(true)
    {
        char c;
        c = getchar();
        if(c == '\n')
        {
            input[i] = '\0';
            break;
        }
        else // c is an input
            input[i] = c;
        i++;
    }

    for(i = 0; input[i] != 0; i++)
    {
        int num;
        if(input[i] == '.') // 1 ~ 5
        {
            num = 0;
            for(int j = 0; j < 5; j++)
                if(input[i + j] == '.')
                    num++;
            i += 4;
        }
        else if(input[i] == '-') // 6 ~ 0
        {
            num = 5;
            for(int j = 0; j < 5; j++)
                if(input[i + j] == '-')
                    num++;
            i += 4;
        }
        else if(input[i] == '/')
        {
            printf(" ");
            continue;
        }
        else if(input[i] == ' ')
        {
            continue;
        }

        num %= 10;

        printf("%d", num);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    while (n--) { morse_code_decoder(); }
    return 0;
}
/*
.---- ....- ..--- ---.. ..... --...

.---- ....- ----- / .---- .---- ...-- / ---.. --... / ---.. --...
..... ..--- .---- .---- ...-- / .---- .---- ....- ---.. ---..
..... ..--- ----- / .---- ...-- .---- ....- / ..--- .---- ----. ----.

*/