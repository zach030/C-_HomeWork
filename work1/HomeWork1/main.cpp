#include <iostream>
#include <math.h>
using namespace std;

// �ж�100�����֣��Ƿ�Ϊ����
// �������100���ڵ�����

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
                // ��������
                flag = 1;
                break;
            }
        }
        // ����������������
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
        // �������������, flag=1
        if (x % i == 0)
            flag = 1;
    }
    if (!flag)
        // ������
        cout << "��������"<< endl;
    else
        cout << "����������" << endl;
}
int JudgeCon()
{
    char choose;
    cout << "�Ƿ���Ҫ�����ж�������(Y-��,N-��):" << endl;
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
    cout << "��һ�ʣ��ж�����" << endl;
    while(flag)
    {
        cout << "������һ����:" << endl;
        cin >> num ;
        JudgePrime(num);
        flag = JudgeCon();
    }
    cout << "�ڶ��ʣ����100���ڵ�����:" << endl;
    AllPrime();
    return 0;
}

