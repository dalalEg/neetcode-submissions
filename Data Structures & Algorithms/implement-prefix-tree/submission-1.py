class TrieNode:
    def __init__(self):
        self.children = [None] * 26
        self.endOfWord = False

class PrefixTree:

    def __init__(self):
        self.root=TrieNode()

    def insert(self, word: str) -> None:
        temp = self.root
        for w in word:
            i = ord(w) - ord("a")
            if temp.children[i]==None:
                temp.children[i]=TrieNode()
            temp=temp.children[ord(w)-ord('a')]
        temp.endOfWord=True

    def search(self, word: str) -> bool:
        temp = self.root
        for w in word:
            if temp.children[ord(w)-ord('a')]==None:
                return False
            temp=temp.children[ord(w)-ord('a')]
        return  temp.endOfWord



    def startsWith(self, prefix: str) -> bool:
        temp = self.root
        for w in prefix:
            if temp.children[ord(w)-ord('a')]==None:
                return False
            temp=temp.children[ord(w)-ord('a')]
        return  True
        