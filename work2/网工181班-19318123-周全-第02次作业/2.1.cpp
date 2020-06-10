#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <cstdio>
/*
1�����������ж��ǲ���ˮ�ɻ���:��λ���������͵��ڱ���
2�����������Χ��ˮ�ɻ���
*/
int JudgeNum(int num)
{
    // �����ˮ�ɻ��� ����1�����Ƿ���0
    int a, b, c;
    // a b c �ֱ�������λ��
    int sum = 0;
    std::string res;
    std::stringstream ss;          //������ss
    ss << num;                    // ������aת������ss
    ss >> res;                    //����ssת�����ַ���
    // �����ַ����������±꣬��ȥ0��ASCII�룬�õ�����
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
    // ѭ�������ж�ˮ�ɻ���
    while(flag)
    {
        std::cout << "Please input a number:" << std::endl;
        std::cin >> num ;
        result = JudgeNum(num);
        if(result == 1)
            std::cout << num << " ��ˮ�ɻ���!" << std::endl;
        else
            std::cout << num << " ����ˮ�ɻ���!" << std::endl;
        std::cout << "Continue or Not ? (Y/N):" << std::endl;
        flag = Test();
    }
    std::cout << "Question 2:" << std::endl;
    std::cout << "Please input the limit of the calc:" << std::endl;
    fflush(stdin);
    std::cin >> low >> high;
    std::cout << low << "--" << high << "֮���ˮ�ɻ�����:" << std::endl;
    // �����жϣ��������������
    for(i = low; i <= high; i++)
    {
        result = JudgeNum(i);
        if (result == 1)
            std::cout << i << '\t';
    }
    return 0;
}
