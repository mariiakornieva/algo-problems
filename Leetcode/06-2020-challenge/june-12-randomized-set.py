'''
  Insert Delete GetRandom O(1)
Design a data structure that supports all following operations in average O(1) time.
- insert(val): Inserts an item val to the set if not already present.
- remove(val): Removes an item val from the set if present.
- getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
'''

class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        self.address = {}

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.address.keys():
            self.data.append(val)
            self.address[val] = len(self.data)-1
            return True
        return False
        

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.address.keys():
            idx = self.address[val]
            self.data[idx] = self.data[-1]
            self.address[self.data[idx]] = idx
            self.data.pop()
            del self.address[val]
            return True
        return False

    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        rand = randint(0, len(self.data)-1)
        return self.data[rand]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
