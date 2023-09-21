class Solution {
public:
int maxPoints(vector<vector<int>>& points) {
	sort(points.begin(),points.end());
	int res =0;
	for(int i=0;i<points.size();i++){
		map<double,int> s;
		for(int j=0;j<points.size();j++){
			if(i==j)continue;
			double d = (double)(points[j][0]-points[i][0])/(double)(points[j][1]-points[i][1]);
			s[d]++;
			res = max(res,s[d]);
		}
	}
	return res+1;
}
};
