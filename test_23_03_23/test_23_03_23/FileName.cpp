#include<iostream>
using namespace std;

bool ss(int);
int main()
{
    int x;
    cin >> x;
    cout << ss(x) << endl; ;
    return 0;
}
bool ss(int x) {
    for (int i = 2; x % i != 0 && i <= x; i++)
    {
        if (i == x)
            bool ss = 1;
    }
    bool ss = 0;
    return ss;
}

