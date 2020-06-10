#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdio>
/*
1、输入数字判断是不是水仙花数:各位数的立方和等于本身
2、输出给定范围的水仙花数
*/
int JudgeNum(int num)
{
    // 如果是水仙花数 返回1，不是返回0
    int a, b, c;
    // a b c 分别存放三个位数
    int sum = 0;
    std::string res;
    std::stringstream ss;          //定义流ss
    ss << num;                    // 将数字a转化成流ss
    ss >> res;                    //将流ss转化成字符串
    // 利用字符串的数组下标，减去0的ASCII码，得到数字
    //std::string res = std::to_string(num);
    a = res[0] - '0', b = res[1] - '0', c = res[2] - '0';
    sum = pow(a, 3) + pow(b, 3) + pow(c ,3);
    if (sum == num)
        return 1;
    else
        return 0;
}
int Test()
{
    char key;
    fflush(stdin);
    std::cin >> key;
    if ((key == 'Y')||(key == 'y'))
        return 1;
    else
        return 0;
}
int main()
{
    int flag = 1;
    int num, low, high, result = 0;
    int i;
    std::cout << "Question 1:" << std::endl;
    // 循环输入判断水仙花数
    while(flag)
    {
        std::cout << "Please input a number:" << std::endl;
        std::cin >> num ;
        result = JudgeNum(num);
        if(result == 1)
            std::cout << num << " 是水仙花数!" << std::endl;
        else
            std::cout << num << " 不是水仙花数!" << std::endl;
        std::cout << "Continue or Not ? (Y/N):" << std::endl;
        flag = Test();
    }
    std::cout << "Question 2:" << std::endl;
    std::cout << "Please input the limit of the calc:" << std::endl;
    fflush(stdin);
    std::cin >> low >> high;
    std::cout << low << "--" << high << "之间的水仙花数有:" << std::endl;
    // 遍历判断，符合条件的输出
    for(i = low; i <= high; i++)
    {
        result = JudgeNum(i);
        if (result == 1)
            std::cout << i << '\t';
    }
    return 0;
}
