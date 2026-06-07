class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end() ||
            beginWord == endWord) {
            return 0;
        }
        map<string, vector<string>> adj;
        int n = wordList.size() + 1, m = beginWord.size();
        wordList.push_back(beginWord);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                string a = wordList[i], b = wordList[j];
                int count = 0;
                for (int i = 0; i < m; i++) {
                    if (a[i] != b[i])
                        count++;
                }
                if (count == 1) {
                    adj[a].push_back(b);
                    adj[b].push_back(a);
                }
            }
        }
        queue<string> q;
        set<string> st;
        q.push(beginWord);
        int steps = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                string curr = q.front();
                q.pop();
                if (curr == endWord)
                    return steps;
                for (string adjacent : adj[curr]) {
                    if (st.count(adjacent) == 0) {
                        st.insert(adjacent);
                        q.push(adjacent);
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};
