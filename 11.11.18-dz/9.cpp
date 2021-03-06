/*Напишите две функции(или метода):
- Функция установки мины на клетку
- Функция, выписывающая или отрисовывающая карту, на текущем шаге игры.*/

#include <stdio.h>
#include <cstdlib>
using namespace std;

void set_min (int** &a, int b, int c, int x, int y)
{
    if ((x <= b) && (y <= c) && (x >= 1) && (y >= 1))
    {
        a[x - 1][y - 1] = -1;
    }
}
void mins_detector (int** &a, int b, int c)
{
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == -1) continue;
            int p = 0;
            
            int x = i, y = j;
            
            if (x > 0) {x -= 1;};
            if (y > 0) {y -= 1;};
            int x_ = x, y_ = y;
            while ((x_ <= (b - 1)) && ((x_ - i) <= 1))
            {
                while ((y_ <= (c - 1)) && ((y_ - j) <= 1))
                {
                    if (a[x_][y_] == -1) {p++;};
                    y_++;
                }
                y_ = y;
                x_++;
            };
            
            a[i][j] = p;
        }
    }
}

int main()
{
    int m, n;
    scanf ("%d%d", &m, &n);
    
    int** pole = new int* [m];
    for (int i = 0; i < m; i++)
        *(pole+i) = new int [n];
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            pole[i][j] = 0;
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == 0)
                printf("%2d", pole[i][j]);
            else
                printf("%4d", pole[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    char d;
    
    while (0 == 0)
    {
        int m_, n_;
        scanf ("%d%d", &m_, &n_);
        set_min(pole, m, n, m_, n_);
        mins_detector(pole, m, n);
        
        system("cls");
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j == 0)
                    printf("%2d", pole[i][j]);
                else
                    printf("%4d", pole[i][j]);
            }
            printf("\n");
        }
        d = getch();
        if (d == 27) {exit(0);};
    }
    
}
