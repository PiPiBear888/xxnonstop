#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
using namespace std;
class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    int count; // 输入次数
    bool is_end_of_word; // 是否为完整单词的结尾

    TrieNode() : count(0), is_end_of_word(false) {}
};

class Trie
{
private:
    TrieNode* root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // 插入字符串及输入次数
    void insert(const string& word, int count)
    {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
        node->count = count;
    }

    // 删除目标字符串
    bool remove(const string& word)
    {
        return removeHelper(root, word, 0);
    }

    bool removeHelper(TrieNode* node, const string& word, int index) {
        if (index == word.size()) {
            if (!node->is_end_of_word) {
                return false; // 该字符串不存在
            }
            node->is_end_of_word = false;
            return node->children.empty(); // 只有叶子结点时，删除该节点
        }

        char ch = word[index];
        if (node->children.find(ch) == node->children.end()) {
            return false; // 字符串不存在
        }

        bool should_delete_current_node = removeHelper(node->children[ch], word, index + 1);

        // 如果子节点不再有其它子节点，删除该子节点
        if (should_delete_current_node) {
            delete node->children[ch];
            node->children.erase(ch);
            return node->children.empty() && !node->is_end_of_word;
        }

        return false;
    }

    // 查询字符串输入次数
    int getCount(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return -1; // 字符串不存在
            }
            node = node->children[c];
        }
        return node->is_end_of_word ? node->count : -1;
    }

    // 查询以某个前缀开头的所有字符串
    void getWordsWithPrefix(const string& prefix, vector<pair<string, int>>& result) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return; // 无前缀
            }
            node = node->children[c];
        }
        dfs(node, prefix, result);
    }

    // 深度优先搜索
    void dfs(TrieNode* node, const string& prefix, vector<pair<string, int>>& result) {
        if (node->is_end_of_word) {
            result.push_back({ prefix, node->count });
        }
        for (auto& child : node->children) {
            dfs(child.second, prefix + child.first, result);
        }
    }

    // 正则查询：匹配满足条件的字符串
    void queryRegex(const string& regex_str, vector<pair<string, int>>& result) {
        regex reg(regex_str);
        queryRegexHelper(root, "", result, reg);
    }

    void queryRegexHelper(TrieNode* node, const string& current_str, vector<pair<string, int>>& result, const regex& reg) {
        if (node->is_end_of_word && regex_match(current_str, reg)) {
            result.push_back({ current_str, node->count });
        }
        for (auto& child : node->children) {
            queryRegexHelper(child.second, current_str + child.first, result, reg);
        }
    }
};

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
