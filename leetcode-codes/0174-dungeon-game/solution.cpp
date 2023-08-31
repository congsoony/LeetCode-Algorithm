class Solution {
public:
int n,m;
int dy[2]={1,0};
int dx[2]={0,1};
bool isrange(int y,int x){
    return 0<=y&&y<n&&0<=x&&x<m;
}
int dijkstra(int shp,vector<vector<int>>& board){
    if(shp+board[0][0]<=0)return -1e8;

    priority_queue<tuple<int,int,int>> pq;
    vector<vector<int>> dist(n,vector<int>(m,-1e8));
    pq.push({shp+board[0][0],0,0});
    dist[0][0]=shp+board[0][0];
    while(!pq.empty()){
        int hp,y,x;
        tie(hp,y,x)=pq.top();
        pq.pop();
        if(dist[y][x]>hp)continue;
        for(int i=0;i<2;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(isrange(ny,nx)&&dist[ny][nx]<hp+board[ny][nx]&&hp+board[ny][nx]>0){
                dist[ny][nx]=hp+board[ny][nx];
                pq.push({hp+board[ny][nx],ny,nx});
            }
        }
    }
    return dist[n-1][m-1];
}
int calculateMinimumHP(vector<vector<int>>& dungeon) {
    tie(n,m) = make_tuple(dungeon.size(),dungeon[0].size());
    int l=1,r=1e6;
    int res =1e8;
    while(l<=r){
        int mid = (l+r)/2;
        if(dijkstra(mid,dungeon)>0){
            r=mid-1;
            res=min(res,mid);
        }
        else
            l=mid+1;
    }
    return res;
}
};
