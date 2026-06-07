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
    TrieNode* root;
public:
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
         TrieNode* temp=root;
         int i=0;
         while(i<word.size()&&temp!=nullptr&& temp->children[word[i]-'a']!= nullptr){
            temp=temp->children[word[i]-'a'];
            i++;
         }
         while(i<word.size()){
            temp->children[word[i]-'a']=new TrieNode();
            temp=temp->children[word[i]-'a'];
            i++;
         }
  temp->isEndOfWord=true;
    }
    
    bool search(string word) {
        TrieNode* temp=root;
         int i=0;
         while(i<word.size()&&temp!=nullptr&& temp->children[word[i]-'a']!= nullptr){
            temp=temp->children[word[i]-'a'];
            i++;
         }
         return i==word.size() && temp->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp=root;
         int i=0;
         while(i<prefix.size()&&temp!=nullptr&& temp->children[prefix[i]-'a']!= nullptr){
            temp=temp->children[prefix[i]-'a'];
            i++;
         }
         return i==prefix.size();
    }
};
