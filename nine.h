#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

class TrieNode
{
public:
    std::unordered_map<char, TrieNode*> children;
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
    void insert(const std::string& word, int count);// 插入字符串及输入次数
    bool remove(const std::string& word);// 删除目标字符串
    bool removeHelper(TrieNode* node, const std::string& word, int index); //删除的辅助函数
    int getCount(const std::string& word);// 查询字符串输入次数
    void getWordsWithPrefix(const std::string& prefix, std::vector<std::pair<std::string, int>>& result);// 查询以某个前缀开头的所有字符串
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::pair<std::string, int>>& result);// 深度优先搜索
    void queryRegex(const std::string& regex_str, std::vector<std::pair<std::string, int>>& result);// 正则查询:匹配满足条件的字符串
    void queryRegexHelper(TrieNode* node, const std::string& current_str, std::vector<std::pair<std::string, int>>& result, const std::regex& reg); //正则查询辅助函数
};