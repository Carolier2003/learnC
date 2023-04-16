#include <cstdio>
#ifdef ANS
#include "usr-ans.h"
#else
#include "usr.h"
#endif


int main()
{
    int arr[30], n;
    while (cin >> n)
    {
        for (int s = 0; s < n; s++)
            cin >> arr[s];
        Reverse(arr, arr + n - 1);
        for (int s = 0; s < n; s++)
            cout << arr[s] << " ";
        cout << endl;
    }
}
