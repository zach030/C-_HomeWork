#include <iostream>
#include <string.h>
// ������
void sort(char a[5][10])
{
    for(int i=0; i<5; i++)
    {
        int k=i;
        // ��ʱt���飬������Ϊ�м�ֵ���н���
        char t[10];
        for(int j=i; j<5; j++)
        // ����˳��
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
    //����һ��5*10�Ķ�ά���飬�趨ÿ���ַ�������Ϊ10
    char str[5][10];
    std::cout << "Please input 5 strings :" << std::endl;
    for(int i = 0; i <= 4; i++)
        std::cin >> str[i];
    sort(str);
    std::cout << "The sorted strings are :" << std::endl;
    print(str);
    return 0;
}
