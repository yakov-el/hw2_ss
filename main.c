#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"


int main()
{

    while (1)
    {
        char input = 0;
        int i, j;
        int v, w;

        scanf("%c", &input);
        switch (input)
        {
        case 'A':
            setMatrix();
            break;

        case 'B':

            scanf("%d", &i);
            scanf("%d", &j);

            int error = thereIsPath(i, j);
            if (error == 0){printf("True\n");}
            else{ printf("False\n"); }
                
            break;
        case 'C':

            scanf("%d", &v);
            scanf("%d", &w);
            giveMeValue(v, w);

            break;

        case 'D':
            exit(0);
        }
    }
}