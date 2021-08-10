#include <bits/stdc++.h>
using namespace std;

class A
{
public:
    int a;
    void funcA()
    {
        cout << "funcA \n";
    }

private:
    int b;
    void funcB()
    {
        cout << "funcB \n";
    }

protected:
    int c;
    void funcC()
    {
        cout << "func C \n";
    }
};

int main()
{
    A obj;
    obj.funcA();
    return 0;
}