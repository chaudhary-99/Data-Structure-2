#include <stdio.h>
int main()
{
    int m, n;
    printf("ENTER THE VALUES OF NUMBER OF ROWS AND COLUMNS");
    scanf("%d %d", &m, &n);
    int a[m][n];
    
    printf("ENTER THE MATRIX 1\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
           int temp;
           temp = a[i][j];
           a[i][j]=a[j][i];
           a[j][i]=temp;

        }
    }

    printf("PRINTING THE MATRIX\n ");
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}