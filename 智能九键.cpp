#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    int count; // 输入次数
    bool is_end_of_word; // 是否为完整单词的结尾

    TrieNode() : count(0), is_end_of_word(false) {}
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // 插入字符串及输入次数
    void insert(const std::string& word, int count) {
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
    bool remove(const std::string& word) {
        return removeHelper(root, word, 0);
    }

    bool removeHelper(TrieNode* node, const std::string& word, int index) {
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
    int getCount(const std::string& word) {
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
    void getWordsWithPrefix(const std::string& prefix, std::vector<std::pair<std::string, int>>& result) {
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
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::pair<std::string, int>>& result) {
        if (node->is_end_of_word) {
            result.push_back({prefix, node->count});
        }
        for (auto& child : node->children) {
            dfs(child.second, prefix + child.first, result);
        }
    }

    // 正则查询：匹配满足条件的字符串
    void queryRegex(const std::string& regex_str, std::vector<std::pair<std::string, int>>& result) {
        std::regex reg(regex_str);
        queryRegexHelper(root, "", result, reg);
    }

    void queryRegexHelper(TrieNode* node, const std::string& current_str, std::vector<std::pair<std::string, int>>& result, const std::regex& reg) {
        if (node->is_end_of_word && std::regex_match(current_str, reg)) {
            result.push_back({current_str, node->count});
        }
        for (auto& child : node->children) {
            queryRegexHelper(child.second, current_str + child.first, result, reg);
        }
    }
};
