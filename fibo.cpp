#include<iostream>
using namespace std;
int fib (int y)
{
    if (y == 0 || y == 1)
    {
        return (y);
        
    }
    else
    {
        return (fib (y - 1) + fib (y - 2));
        
    }
}

int main ()
{
    int y, i = 0;
    cout << "Enter the amount of series= ";
    cin >> y;
    cout << "\n Fibonacci series:";
    while (i < y)
    {
        cout << " " << fib (i);
        i++;
        
    }
    return 0;
}
