'''
  Queue Reconstruction by Height
Suppose you have a random list of people standing in a queue.
Each person is described by a pair of integers (h, k), where h is the height of the person
and k is the number of people in front of this person who have a height greater than or equal to h. 
Write an algorithm to reconstruct the queue.
'''

class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        # select by shortest
        result = [[-1,-1] for _ in range(len(people))]
        people.sort(key=lambda p: (p[0], p[1]))
        
        for i in range(len(people)):
            count = people[i][1]
            for j in range(len(people)):
                if result[j][0] == -1 and count == 0:
                    result[j] = people[i]
                    break;
                elif result[j][0] == -1 or result[j][0] >= people[i][0]:
                    count-=1
        
        return result
