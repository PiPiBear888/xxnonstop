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
    int count; // �������
    bool is_end_of_word; // �Ƿ�Ϊ�������ʵĽ�β

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
    void insert(const std::string& word, int count);// �����ַ������������
    bool remove(const std::string& word);// ɾ��Ŀ���ַ���
    bool removeHelper(TrieNode* node, const std::string& word, int index); //ɾ���ĸ�������
    int getCount(const std::string& word);// ��ѯ�ַ����������
    void getWordsWithPrefix(const std::string& prefix, std::vector<std::pair<std::string, int>>& result);// ��ѯ��ĳ��ǰ׺��ͷ�������ַ���
    void dfs(TrieNode* node, const std::string& prefix, std::vector<std::pair<std::string, int>>& result);// �����������
    void queryRegex(const std::string& regex_str, std::vector<std::pair<std::string, int>>& result);// �����ѯ:ƥ�������������ַ���
    void queryRegexHelper(TrieNode* node, const std::string& current_str, std::vector<std::pair<std::string, int>>& result, const std::regex& reg); //�����ѯ��������
};