class Solution {
public:
int candy(vector<int>& ratings) {
    int n = ratings.size();
    int res = n;
    vector<pair<int,int>> v={{1e8,0}};
    ratings.insert(ratings.begin(),1e8);
    ratings.push_back(1e8);

    for(int i =0;i<ratings.size();i++)v.push_back({ratings[i],i});
    sort(v.begin(),v.end());
    vector<int> check(n+4);
    for(int i=0;i<n;i++){
        int val,idx;
        tie(val,idx) = v[i];
        if(ratings[idx]>ratings[idx-1]||ratings[idx]>ratings[idx+1]){
            if(ratings[idx]>ratings[idx-1]&&ratings[idx]>ratings[idx+1])
                check[idx] = max(check[idx-1],check[idx+1])+1;
            else if(ratings[idx]>ratings[idx-1])
                check[idx] = check[idx-1]+1;
            else
                check[idx] = check[idx+1]+1;
            res+=check[idx];     
        }
    }
    return res;
}
};
