class Solution {
public:
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
	int sum=0;
	int res =0;
	int total=0;
	for(int i=0;i<gas.size();i++){
		sum+=gas[i]-cost[i];
		total+=gas[i]-cost[i];
		if(total<0){
			res=i+1;
			total=0;
		}
	}
	return (sum>=0?res:-1);
}
};
