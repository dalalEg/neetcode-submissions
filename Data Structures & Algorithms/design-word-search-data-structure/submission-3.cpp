class TrieNode {
   public:
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; ++i) children[i] = nullptr;
    }
};
class WordDictionary {
    TrieNode* root;
    bool dfs(int i, string word, TrieNode* temp) {
        if (temp == nullptr) {
            return false;
        }
        if (i == word.size()) return temp->isEndOfWord;
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (dfs(i + 1, word, temp->children[j])) return true;
            }
            return false;
        } else {
            return dfs(i + 1, word, temp->children[word[i] - 'a']);
        }
    }

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        int i = 0;
        while (i < word.size() && temp != nullptr && temp->children[word[i] - 'a'] != nullptr) {
            temp = temp->children[word[i] - 'a'];
            i++;
        }
        while (i < word.size()) {
            temp->children[word[i] - 'a'] = new TrieNode();
            temp = temp->children[word[i] - 'a'];
            i++;
        }
        temp->isEndOfWord = true;
    }

    bool search(string word) { return dfs(0, word, root); }
};
