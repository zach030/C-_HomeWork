#include <iostream>
#include <math.h>
using namespace std;

// 判断100的数字，是否为素数
// 输出所有100以内的素数

void AllPrime()
{
    int i, j;
    for(i = 1; i <= 100; i++)
    {
        int flag = 0;
        for (j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                // 不是素数
                flag = 1;
                break;
            }
        }
        // 是素数的情况，输出
        if(!flag)
            cout << i << ' ';
    }
}
int JudgePrime(int x)
{
    int i;
    int flag = 0;
    for(i = 2; i <= sqrt(x); i++)
    {
        // 不是素数的情况, flag=1
        if (x % i == 0)
            flag = 1;
    }
    if (!flag)
        // 是素数
        cout << "是素数！"<< endl;
    else
        cout << "不是素数！" << endl;
}
int JudgeCon()
{
    char choose;
    cout << "是否需要继续判断素数？(Y-是,N-否):" << endl;
    cin >> choose ;
    if ((choose == 'Y') || (choose == 'y'))
        return 1;
    else
        return 0;
}
int main()
{
    int num, key;
    int flag =1;
    cout << "第一问：判断素数" << endl;
    while(flag)
    {
        cout << "请输入一个数:" << endl;
        cin >> num ;
        JudgePrime(num);
        flag = JudgeCon();
    }
    cout << "第二问：输出100以内的素数:" << endl;
    AllPrime();
    return 0;
}

