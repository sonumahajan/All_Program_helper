
 #include<stdio.h>

int main()
{
    int n = 7;
        int x = 2;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (j == 1 || j == x)
                    printf("%2c", 'D');
                else
                    printf("%2c", ' ');
            }
            printf("\n");
            if (i <= n / 2)
                x++;
            else
                x--;
        }
    return 0;
}