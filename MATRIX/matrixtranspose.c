#include <stdio.h>
int main()
{
    int m, n;
    printf("ENTER THE VALUES OF NUMBER OF ROWS AND COLUMNS");
    scanf("%d %d", &m, &n);
    int a[m][n];
    
    int c[10][10];

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
            if(i>j){
                c[i][j] = a[j][i];
            }
        }
    }

    printf("PRINTING THE MATRIX\n ");
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", c[j][i]);
        }
        printf("\n");
    }

    return 0;
}