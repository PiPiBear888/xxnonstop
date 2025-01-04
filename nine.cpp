#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include "nine.h"
using namespace std;
// 插入字符串及输入次数
void Trie::insert(const string& word, int count) // 插入字符串及输入次数
{
    TrieNode* node = root;
    for (char c : word) 
    {
        if (node->children.find(c) == node->children.end()) 
        {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    if (node->is_end_of_word) 
    {
        // 如果目标字符串已存在，输出已存在和输入次数
        std::cout << word << " 存在，已输入次数为 " << node->count << " 次" << std::endl;
    }
    else 
    {
        // 插入新的字符串
        node->is_end_of_word = true;
        node->count = count;
        std::cout << "添加成功" << std::endl;
    }
}

// 删除目标字符串
void Trie::remove(const std::string& word) {
    if (removeHelper(root, word, 0)) {
        std::cout << "删除成功" << std::endl;
    }
    else {
        std::cout << "删除失败，" << word << " 不存在" << std::endl;
    }
}

// 辅助函数：递归删除字符串
bool Trie::removeHelper(TrieNode* node, const std::string& word, int index) {
    if (index == word.size()) {
        // 如果已经遍历到最后，检查是否为完整字符串
        if (node->is_end_of_word) {
            node->is_end_of_word = false; // 标记为非有效字符串
            return true; // 删除成功
        }
        return false; // 字符串不存在
    }

    char ch = word[index];
    // 如果当前字符不在子节点中，说明目标字符串不存在
    if (node->children.find(ch) == node->children.end()) {
        return false; // 字符串不存在
    }

    // 递归删除
    bool can_delete = removeHelper(node->children[ch], word, index + 1);

    // 如果子节点可以删除且该节点没有其他子节点，也可以删除当前节点
    if (can_delete) {
        delete node->children[ch];
        node->children.erase(ch);

        // 如果当前节点不是字符串的结束节点且没有子节点，则当前节点也可以删除
        return node->children.empty() && !node->is_end_of_word;
    }

    return false;
}

// 查询字符串输入次数
int Trie::getCount(const string& word) {
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
void Trie::getWordsWithPrefix(const string& prefix, vector<pair<string, int>>& result) {
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
void Trie::dfs(TrieNode* node, const string& prefix, vector<pair<string, int>>& result) {
    if (node->is_end_of_word) {
        result.push_back({ prefix, node->count });
    }
    for (auto& child : node->children) {
        dfs(child.second, prefix + child.first, result);
    }
}

// 正则查询：匹配满足条件的字符串
void Trie::queryRegex(const string& regex_str, vector<pair<string, int>>& result) {
    regex reg(regex_str);
    queryRegexHelper(root, "", result, reg);
}

void Trie::queryRegexHelper(TrieNode* node, const string& current_str, vector<pair<string, int>>& result, const regex& reg) {
    if (node->is_end_of_word && regex_match(current_str, reg)) {
        result.push_back({ current_str, node->count });
    }
    for (auto& child : node->children) {
        queryRegexHelper(child.second, current_str + child.first, result, reg);
    }
}
