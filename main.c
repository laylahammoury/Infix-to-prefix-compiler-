//~~~~~~~~~ main.c ~~~~~~~~

#include "global.h"

int main(int argc, char* argv[])
{
    int i;
    if (argc >= 2)
    {
        printf("The arguments supplied are:\n");
        for (i = 1; i < argc; i++)
        {
            printf("%s\t", argv[i]);
        }
    }
    else
    {
        printf("argument list is empty.\n");
    }
    ofptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix\\output.txt", "w");
    ifptr = fopen("C:\\Users\\Layla H\\source\\repos\\infix to prefix\\infix to prefix\\input.txt", "r");

    init();
    parse();

    fclose(ifptr);
    fclose(ofptr);
    exit(0); /* successful termination */
    return 0;
}



