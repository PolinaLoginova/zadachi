/*Дан массив, содержащий N неотрицательных целых чисел. Напишите на одном из
языков программирования программу, которая находит в этом массиве количество 
элементов, значение которых менее чем в два раза превосходит значение
предшествующего элемента.*/

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int i, k = 0, n, b = 30000;
	cin >> n;
	int *s = new int(n);
	for(i = 1; i < n; i++)
		cin >> s[i];
	for(i = 1; i < n; i++)
	{
		if(s[i] <= 2 * s[i-1])
			k++;
	}
	cout << k;
	return 0;
}
