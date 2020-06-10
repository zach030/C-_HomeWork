#include <iostream>
void move(int x, int y)
{
    std::cout << x << "-->" << y << std::endl;
}
void Hanoi(int num, int a, int b, int c)
{
    if(num == 1)
        move(a, c);
    else
    {
        Hanoi(num-1, a, c, b);
        move(a, c);
        Hanoi(num-1, b, a, c);
    }
}
int main()
{
    int num, flag = 1;
    char choose;
    while(flag)
    {
        std::cout << "ººÅµËþÎÊÌâ:" << std::endl;
        std::cout << "Please input the number of the diskes:" << std::endl;
        std::cin >> num;
        std::cout << "The steps of moving diskes:" << std::endl;
        Hanoi(num, 1, 2, 3);
        std::cout << "Do you want to go on?(Y/N):" << std::endl;
        std::cin >> choose;
        if((choose == 'Y')||(choose == 'y'))
            flag = 1;
        else
            flag = 0;
    }
    return 0;
}
