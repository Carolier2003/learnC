#include <iostream>
using namespace std;
void Reverse(int* start, int* end)
{
	/**********   Begin   **********/
	int n = end - start;
	int count = n;
	int temp = 0;
	for (int i = 0; i <= n / 2; i++) {
		temp = *start;
		*start++ = *end;
		*end-- = temp;
		}
			
	//}
	//补充代码完成功能

	/**********   End   **********/
}