#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include "nine.h"
#include "nine.cpp"
using namespace std;
int main()
{
    Trie trie;
    while (true)
    {
        int choice{ 0 };
        cout << "star��ӭʹ�����ܾż����뷨!" << endl
            << "��ѡ����Ҫ���еĲ�����" << endl
            << "1.����Ŀ���ַ�������Ӧ���������" << endl
            << "2.ɾ��Ŀ���ַ���" << endl
            << "3.�޸�Ŀ���ַ�������Ӧ���������" << endl
            << "4.��ѯ���뷨������������ʽ�����е���" << endl
            << "5.ͨ�������ַ�����ѯ���ַ��������뷨�е��������" << endl
            << "6.ͨ�������ַ�����ѯ�Ը��ַ���Ϊǰ׺�������ַ��������������" << endl
            << "7.��ѯ���뷨�г���Ƶ����ߵ��ַ���" << endl
            << "8.��ѯ���뷨�������ַ������������" << endl
            << "9.�˳�����" << endl
            << "ƤƤ�����������������ǰ�����֣�";
        cin >> choice;
        if (choice == 1)
        {
            string word;
            int count;
            cout << "�����뵥�ʣ�";
            cin >> word ;
            cout << "������õ��ʳ��ֵĴ�����";
            cin >> count;
            trie.insert(word, count);
            cout << "����ɹ�";
        }

        else if (choice == 2)
        {
            string word;
            trie.remove(word);
        }

        else if (choice == 3)
        {
            cout << "star��ûʵ��" << endl;
        }

        else if (choice == 4)
        {
            cout << "star��ûʵ��" << endl;
        }

        else if (choice == 5)
        {
            cout << "ppx��star��ûʵ��" << endl;
        }

        else if (choice == 6)
        {
            cout << "ppx��star��ûʵ��" << endl;
        }

        else if (choice == 7)
        {
            cout << "ppx��star��ûʵ��" << endl;
        }

        else if (choice == 8)
        {
            cout << "ppx��star��ûʵ��" << endl;
        }

        else
        {
            cout << "���һ��������" << endl;
        }
    }
    return 0;
}