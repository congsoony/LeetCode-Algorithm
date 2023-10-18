class Solution {
public:
 int n,m;
int dy[8]={-1,-1,-1,0,0,1,1,1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
bool isrange(int y,int x){
	return 0<=y&&y<n&&0<=x&&x<m;
}
void gameOfLife(vector<vector<int>>& board) {
	n = board.size();
	m = board[0].size();
	vector<vector<int>> v= board;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int cnt=0;
			for(int k=0;k<8;k++){
				int ny= i+dy[k];
				int nx=j+dx[k];
				if(isrange(ny,nx))cnt+=board[ny][nx];
			}
			if(board[i][j])v[i][j]=(cnt==2||cnt==3);
			else v[i][j]=cnt==3;
		}
	}
	board=v;
}

};
