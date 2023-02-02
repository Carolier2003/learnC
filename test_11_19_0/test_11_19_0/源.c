//注意
    //1:该程序每次运行的时间必须小于200毫秒，否则会超时,程序超时将不会测试剩余的测试集
    //2:该程序每次运行使用的内存不能超过1M，否则会返回错误
    //3:该程序每次运行输出的结果最多显示1000个字符(多余的不显示),每行末尾的所有空格用□表示
#include <stdio.h>
int main()
{
    //获取参数方式 scanf
    //int x  =0;
    //int y = 0;
    //scanf("%d", &x);

    //结果输出使用prinf
    //printf("%d",x);

    // 请在此添加你的代码
    /********** Begin *********/
    int n, x, y = 0, i, m, number = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        m = i;
        y = 0;
        do
        {
            x = m % 10;
            y += x;
            m = m / 10;

        } while (m);
        
        if (y % 15 == 0)
            number++;

    }

    printf("%d", number);

    /********** End **********/

    return 0;
}
