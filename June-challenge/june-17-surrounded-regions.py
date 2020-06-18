'''
  Surrounded Regions
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
'''

class Solution:
    def __init__(self):
        self.seen = False

    def mark(self, board, i, j, rows, cols):
        if i<0 or i >rows-1 or j<0 or j >cols-1:
            return
        if board[i][j] == 'X':
            return
            
        board[i][j] = 'X'
        self.mark(board, i+1,j, rows, cols)
        self.mark(board, i-1,j, rows, cols)
        self.mark(board, i,j+1, rows, cols)
        self.mark(board, i,j-1, rows, cols)
        
    def dfs(self, board, i, j, rows, cols, visited):
        if i<0 or i >rows-1 or j<0 or j >cols-1:
            return
        if board[i][j] == 'X' or visited[i][j]:
            return
        if i <=0 or i>=rows-1 or j <=0 or j >= cols-1:
            self.seen = True
        visited[i][j]=True
        self.dfs(board, i-1,j,rows, cols, visited)
        self.dfs(board, i+1,j,rows, cols, visited)
        self.dfs(board, i,j-1,rows, cols, visited)
        self.dfs(board, i,j+1,rows, cols, visited)
        
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        if rows <= 1:
            return
        cols = len(board[0])
        if cols <= 1:
            return
        
        self.seen = False
        visited = [[False for _ in range(cols)] for _ in range(rows)]
        
        for i in range(1, rows-1):
            for j in range(1, cols-1):
                if board[i][j] == "O" and not visited[i][j]:
                    self.seen = False
                    self.dfs(board, i, j, rows, cols, visited)
                    if not self.seen:
                        self.mark(board, i, j, rows, cols)
                    self.seen = True
