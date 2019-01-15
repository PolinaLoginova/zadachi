/*У исполнителя четыре команды, которым присвоены номера:
1. прибавь 9
2. возведи в квадрат
3. умножь на 7
4. припиши 1 в конец
Первая из них увеличивает на 9 исходное число x, третья умножает это число на 7, вторая переводит число x в число x*x, 
четвёртая добавляет к числу единицу в конец (например, из числа 30 получается число 301). Программа для исполнителя —
это последовательность команд. Напишите программу, проверяющую, можно ли последовательностью команд исполнителя получить из 
числа X число Y. Если можно, программа должна выписывать YES, в противном случае – NO.*/

#include <iostream>
#include <math.h>
using namespace std;
bool kvadrat( int y )
{
    float n, k; // n- корень, k = y
    bool a;
    k = (float)y;
    n = sqrt(k);
    if ( n == int(n) )
        a = true;
    else a = false;
    return a;
}

int R( int x, int y, int z)
{
    int n = 0;
    if ( x < y && y != z)
    {
        n = R( x, y-9, z);
        if ( kvadrat( y ) == true )
            n = n + R( x, sqrt(y), z);
        if ( y % 7 == 0 )
            n = n + R( x, y / 7, z);
        if ( y % 10 == 1 )
            n = n + R( x, y / 10, z);
    }
    else if ( x == y)
    {
        n = 1;
    }
    //else n = 0; (переменная проинициализирована)
    return n;
}
int main()
{
    int x, y, n, z;
    cout << "Введите Х, который программа должна преобразовать в У, исключая значения  Z,т.е. введите X, Y, Z";
    cin >> x >> y >> z;
    n = R( x, y, z);
    if ( n == 0)
       cout << "NO";
    if ( n != 0)
        cout << "YES";
    return 0;
}
