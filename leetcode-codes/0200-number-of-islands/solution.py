class Solution(object):
    def bfs(self,grid,check,y,x):
        q = deque()
        dy,dx=[-1,0,1,0],[0,1,0,-1]
        q.append((y,x))
        check[y][x]=1
        n = len(grid)
        m = len(grid[0])
        while q:
            y,x=q.popleft()
            for i in range(4):
                ny =y+dy[i]
                nx= x+dx[i]
                if 0<=ny and ny<n and 0<=nx and nx<m and check[ny][nx]==0 and grid[ny][nx]=="1":
                    q.append((ny,nx))
                    check[ny][nx]=1
    def numIslands(self, grid):
        res = 0
        n = len(grid)
        m = len(grid[0])
        check =[[0 for j in range(m)]for i in range(n)]

        for i in range(n):
            for j in range(m):
                if check[i][j]==0 and grid[i][j]=="1":
                    self.bfs(grid,check,i,j)
                    res+=1
        return res  
        
