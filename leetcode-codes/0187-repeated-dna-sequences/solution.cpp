class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if(s.size()<10) return res;
        unordered_map<long long,int> m;
        long long hash =0;
        long long power =1;
        int size =10;
        for(int i=0;i<size;i++){
            hash = hash +s[size-1-i]*power;
            if(i<size-1)power*=31;
        }
        m[hash]++;
        for(int i=1;i<=s.size()-size;i++){
            hash = 31*(hash-s[i-1]*power)+s[size-1+i];
            if(++m[hash]==2){
                res.push_back(s.substr(i,10));
            }
        }
        return res;
    }
};
