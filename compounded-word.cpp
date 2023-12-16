
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
#include <unordered_map>
#include <chrono>

class Node {
public:
    char character;
    std::unordered_map<char, Node*> children;
    bool isTerminal;

    Node(char ch = '\0', bool isTerm = false) : character(ch), isTerminal(isTerm) {}
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(const std::string& word) {
        Node* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end())
                current->children[ch] = new Node(ch);
            current = current->children[ch];
        }
        current->isTerminal = true;
    }

    bool search(const std::string& word) {
        Node* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end())
                return false;
            current = current->children[ch];
        }
        return current->isTerminal;
    }

    std::vector<std::string> getPrefixes(const std::string& word) {
        std::string prefix = "";
        std::vector<std::string> prefixes;
        Node* current = root;
        for (char ch : word) {
            if (current->children.find(ch) == current->children.end())
                return prefixes;
            current = current->children[ch];
            prefix += ch;
            if (current->isTerminal)
                prefixes.push_back(prefix);
        }
        return prefixes;
    }
};

class Solution {
private:
    Trie trie;
    std::deque<std::pair<std::string, std::string>> queue;

public:
    void buildTrie(const std::string& filePath) {
        try {
            std::ifstream file(filePath);
            std::string word;
            while (std::getline(file, word)) {
                std::string trimmedWord = word.substr(0, word.find_last_not_of("\n") + 1);
                std::vector<std::string> prefixes = trie.getPrefixes(trimmedWord);
                for (const std::string& prefix : prefixes) {
                    queue.push_back(std::make_pair(trimmedWord, trimmedWord.substr(prefix.length())));
                }
                trie.insert(trimmedWord);
            }
            file.close();
        } catch (...) {
            std::cout << "There was some error with the file!" << std::endl;
            exit(0);
        }
    }

    std::pair<std::string, std::string> findLongestCompoundWords() {
        std::string longestWord = "";
        int longestLength = 0;
        std::string secondLongest = "";

        while (!queue.empty()) {
            std::string word = queue.front().first;
            std::string suffix = queue.front().second;
            queue.pop_front();

            if (trie.search(suffix) && word.length() > longestLength) {
                secondLongest = longestWord;
                longestWord = word;
                longestLength = word.length();
            } else {
                std::vector<std::string> prefixes = trie.getPrefixes(suffix);
                for (const std::string& prefix : prefixes) {
                    queue.push_back(std::make_pair(word, suffix.substr(prefix.length())));
                }
            }
        }

        return std::make_pair(longestWord, secondLongest);
    }
};

int main() {
    Solution sol;
    auto start = std::chrono::high_resolution_clock::now();
    sol.buildTrie("Input_01.txt");
    auto end = std::chrono::high_resolution_clock::now();

    std::pair<std::string, std::string> result = sol.findLongestCompoundWords();

    double time_taken = std::chrono::duration_cast<std::chrono::duration<double>>(end - start).count();

    std::cout << "Longest Compound Word: " << result.first << std::endl;
    std::cout << "Second Longest Compound Word: " << result.second << std::endl;
    std::cout << "Time taken: " << time_taken << " seconds" << std::endl;

    return 0;
}
