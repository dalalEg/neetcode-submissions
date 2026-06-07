class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class WordDictionary {
    TrieNode* root;

    bool dfs(const string& word, TrieNode* node, int i) {
        if (!node) return false;
        if (i == word.size()) return node->isEndOfWord;

        char c = word[i];
        if (c == '.') {
            for (int j = 0; j < 26; ++j) {
                if (dfs(word, node->children[j], i + 1)) return true;
            }
            return false;
        } else {
            return dfs(word, node->children[c - 'a'], i + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) {
        return dfs(word, root, 0);
    }
};