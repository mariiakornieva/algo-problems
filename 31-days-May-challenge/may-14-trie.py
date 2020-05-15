'''
Implement a trie (Prefix Tree) with insert, search, and startsWith methods.
'''

class Trie:
    class TrieNode:
        def __init__(self, char: str):
            self.value = char
            self.counter = 1
            self.ends_here = False
            self.children = []            
            
    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = self.TrieNode('*')

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        node = self.root
        
        for char in word:
            found = False
            for child in node.children:
                if child.value == char:
                    child.counter += 1
                    node = child
                    found = True
                    break
            if not found:
                new_node = self.TrieNode(char)
                node.children.append(new_node)
                node = new_node
        node.ends_here = True
        

    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        node = self.root
        if not self.root.children:
            return False
        for char in word:
            not_found = True
            for child in node.children:
                if child.value == char:
                    not_found = False
                    node = child
                    break
            if not_found:
                return False

        return node.ends_here

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        node = self.root
        if not self.root.children:
            return False
        for char in prefix:
            not_found = True
            for child in node.children:
                if child.value == char:
                    not_found = False
                    node = child
                    break
            if not_found:
                return False
        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
