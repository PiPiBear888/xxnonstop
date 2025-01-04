#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <regex>
#include "nine.h"
using namespace std;
// �����ַ������������
void Trie::insert(const string& word, int count)
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

// ɾ��Ŀ���ַ���
bool Trie::remove(const string& word)
{
    return removeHelper(root, word, 0);
}

bool Trie::removeHelper(TrieNode* node, const string& word, int index) {
    if (index == word.size()) {
        if (!node->is_end_of_word) {
            return false; // ���ַ���������
        }
        node->is_end_of_word = false;
        return node->children.empty(); // ֻ��Ҷ�ӽ��ʱ��ɾ���ýڵ�
    }

    char ch = word[index];
    if (node->children.find(ch) == node->children.end()) {
        return false; // �ַ���������
    }

    bool should_delete_current_node = removeHelper(node->children[ch], word, index + 1);

    // ����ӽڵ㲻���������ӽڵ㣬ɾ�����ӽڵ�
    if (should_delete_current_node) {
        delete node->children[ch];
        node->children.erase(ch);
        return node->children.empty() && !node->is_end_of_word;
    }

    return false;
}

// ��ѯ�ַ����������
int Trie::getCount(const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            return -1; // �ַ���������
        }
        node = node->children[c];
    }
    return node->is_end_of_word ? node->count : -1;
}

// ��ѯ��ĳ��ǰ׺��ͷ�������ַ���
void Trie::getWordsWithPrefix(const string& prefix, vector<pair<string, int>>& result) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (node->children.find(c) == node->children.end()) {
            return; // ��ǰ׺
        }
        node = node->children[c];
    }
    dfs(node, prefix, result);
}

// �����������
void Trie::dfs(TrieNode* node, const string& prefix, vector<pair<string, int>>& result) {
    if (node->is_end_of_word) {
        result.push_back({ prefix, node->count });
    }
    for (auto& child : node->children) {
        dfs(child.second, prefix + child.first, result);
    }
}

// �����ѯ��ƥ�������������ַ���
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