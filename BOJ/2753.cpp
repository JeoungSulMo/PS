#include <stdio.h>

int main()
{
    int A, B, cnt = 0;
    while (cnt < 10)
    {
        cnt++;
        scanf("%d %d", &A, &B);
        printf("%d", A + B);
    }

    return 0;
}