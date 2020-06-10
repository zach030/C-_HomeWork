#include <iostream>
#include <string.h>
// 排序函数
void sort(char a[5][10])
{
    for(int i=0; i<5; i++)
    {
        int k=i;
        // 临时t数组，用来作为中间值进行交换
        char t[10];
        for(int j=i; j<5; j++)
        // 交换顺序
            if(strcmp(a[j],a[k])<0)
            {
                strcpy(t,a[j]);
                strcpy(a[j],a[k]);
                strcpy(a[k],t);
            }
    }
}
void print(char a[5][10])
{
    for(int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }
}
int main()
{
    //定义一个5*10的二维数组，设定每个字符串长度为10
    char str[5][10];
    std::cout << "Please input 5 strings :" << std::endl;
    for(int i = 0; i <= 4; i++)
        std::cin >> str[i];
    sort(str);
    std::cout << "The sorted strings are :" << std::endl;
    print(str);
    return 0;
}
