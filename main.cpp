#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include "nine.h"
using namespace std;
int main()
{
    Trie trie;
    while (true)
    {
        int choice{ 0 };
        cout << "star欢迎使用智能九键输入法!" << endl
            << "请选择您要进行的操作：" << endl
            << "1.增加目标字符串及对应的输入次数" << endl
            << "2.删除目标字符串" << endl
            << "3.修改目标字符串及对应的输入次数" << endl
            << "4.查询输入法中满足正则表达式的所有单词" << endl
            << "5.通过输入字符串查询该字符串在输入法中的输入次数" << endl
            << "6.通过输入字符串查询以该字符串为前缀的所有字符串及其输入次数" << endl
            << "7.查询输入法中出现频率最高的字符串" << endl
            << "8.查询输入法中所有字符串及输入次数" << endl
            << "9.退出程序" << endl
            << "皮皮熊邀请你请输入操作前的数字：";
        cin >> choice;
        if (choice == 1)
        {
            string word;
            int count;
            cout << "请输入单词：";
            cin >> word ;
            cout << "请输入该单词出现的次数：";
            cin >> count;
            trie.insert(word, count);
            cout << "输入成功";
        }

        else if (choice == 2)
        {
            string word;
            trie.remove(word);
        }

        else if (choice == 3)
        {
            cout << "star还没实现" << endl;
        }

        else if (choice == 4)
        {
            cout << "star还没实现" << endl;
        }

        else if (choice == 5)
        {
            cout << "ppx和star还没实现" << endl;
        }

        else if (choice == 6)
        {
            cout << "ppx和star还没实现" << endl;
        }

        else if (choice == 7)
        {
            cout << "ppx和star还没实现" << endl;
        }

        else if (choice == 8)
        {
            cout << "ppx和star还没实现" << endl;
        }

        else
        {
            cout << "多给一分求求了" << endl;
        }
    }
    return 0;
}
