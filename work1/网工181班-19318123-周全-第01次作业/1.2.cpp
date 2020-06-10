#include <iostream>
#include <math.h>
#include <iomanip>
// 计算单个数阶乘
long long factorial(int n)
{
    long long answer ;
    if(n == 1)
    {
        answer = 1;
    }
    else
    {
        answer = n * factorial(n - 1);
    }
    return answer;
}
// 求阶乘和
long long sum(int num)
{
    long i;
    long long total = 0;
    for(i =1; i <= num; i++)
    {
        std::cout << "The answer of factorial " << i << " is :" << factorial(i) << std::endl;
        total += factorial(i);
    }
    return total;
}
int main()
{
    long long result;
    int num;
    std::cout << "Please input a number:" << std::endl;
    std::cin >> num ;
    result = sum(num);
    std::cout << "The sum is :" << result << std::endl;
    return 0;
}
