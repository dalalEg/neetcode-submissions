class TreeNode:
    def __init__(self):
        self.children=[None]*26
        self.isItEnd=False
class PrefixTree:

    def __init__(self):
        self.root=TreeNode()
    
    def insert(self, word: str) -> None:
        temp=self.root
        for w in word:
            if temp.children[ord(w)-ord('a')]==None:
               temp.children[ord(w)-ord('a')]=TreeNode()
            temp= temp.children[ord(w)-ord('a')]
        temp.isItEnd=True

    def search(self, word: str) -> bool:
        temp=self.root
        for w in word:
            if temp.children[ord(w)-ord('a')]==None:
                return False
            temp= temp.children[ord(w)-ord('a')]
        return temp.isItEnd

    def startsWith(self, prefix: str) -> bool:
        temp=self.root
        for w in prefix:
            if temp.children[ord(w)-ord('a')]==None:
                return False
            temp= temp.children[ord(w)-ord('a')]
        return True