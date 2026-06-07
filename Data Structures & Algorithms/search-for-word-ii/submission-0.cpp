
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

class PrefixTree {

public:
    TrieNode* root;

    PrefixTree() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* temp = root;
        int i = 0;
        while (i < word.size() && temp != nullptr &&
               temp->children[word[i] - 'a'] != nullptr) {
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

    bool search(string word) {
        TrieNode* temp = root;
        int i = 0;
        while (i < word.size() && temp != nullptr &&
               temp->children[word[i] - 'a'] != nullptr) {
            temp = temp->children[word[i] - 'a'];
            i++;
        }
        return i == word.size() && temp->isEndOfWord;
    }
};
class Solution {
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node,
             string path, unordered_set<string>& res,
             vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())
            return;
        if (visited[i][j])
            return;
        char ch = board[i][j];
        if (node->children[ch - 'a'] == nullptr)
            return;

        visited[i][j] = true;
        node = node->children[ch - 'a'];
        path += ch;

        if (node->isEndOfWord)
            res.insert(path);

        dfs(board, i + 1, j, node, path, res, visited);
        dfs(board, i - 1, j, node, path, res, visited);
        dfs(board, i, j + 1, node, path, res, visited);
        dfs(board, i, j - 1, node, path, res, visited);

        visited[i][j] = false;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        
            PrefixTree* trie = new PrefixTree();
            for (string& word : words)
                trie->insert(word);

            unordered_set<string> result;
            int m = board.size(), n = board[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));

            for (int i = 0; i < m; ++i)
                for (int j = 0; j < n; ++j)
                    dfs(board, i, j, trie->root, "", result, visited);

            return vector<string>(result.begin(), result.end());
        
    }
};
