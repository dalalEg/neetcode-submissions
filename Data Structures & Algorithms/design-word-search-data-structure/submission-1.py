class TrieNode :
    def __init__(self):
        self.children={}
        self.end=False
class Trie:
    def __init__(self):
        self.root=TrieNode()
    def insert (self,word):
        temp=self.root
        for c in word :
            if c not in temp.children:
                temp.children[c]=TrieNode()
            temp=temp.children[c]
        temp.end=True
    def search(self,word):
        def dfs(j, root):
            cur = root

            for i in range(j, len(word)):
                c = word[i]
                if c == ".":
                    for child in cur.children.values():
                        if dfs(i + 1, child):
                            return True
                    return False
                else:
                    if c not in cur.children:
                        return False
                    cur = cur.children[c]
            return cur.end
        return dfs(0, self.root)

class WordDictionary:

    def __init__(self):
        self.dictionary=Trie()
    def addWord(self, word: str) -> None:
        self.dictionary.insert(word)
     
    def search(self, word: str) -> bool:
        return  self.dictionary.search(word)