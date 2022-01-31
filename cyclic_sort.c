#include <stdio.h>

int main(void)
{
    int a[] = {9, 7, 3, 1, 3, 7, 5, 4, 9};
    int b[10] = {0};

    printf("Array a contains the values 1-10: ");
    for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++)
    {
        printf("%d ", a[i]);
        b[a[i] - 1] = a[i];
    }

    printf("\nThe missing numbers are: ");

    for (int i = 0; i < sizeof(b)/sizeof(b[0]); i++)
    {
        if (b[i] == 0)
            printf("%d ", i+1);
    }
    printf("\n");


    return 0;
}
