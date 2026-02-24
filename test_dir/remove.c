#include <stdio.h>

int main()
{
    FILE* fp = fopen("test.txt", "r");
    int count = 0;
    int val;

    while (fscanf(fp, "%d", &val) == 1)
    {
        printf("Value read: %d\n", val);
        count ++;
    }
    printf("Count is: %d\n", count);
    printf("Current position in file is: %ld", ftell(fp));
    return 0;
}