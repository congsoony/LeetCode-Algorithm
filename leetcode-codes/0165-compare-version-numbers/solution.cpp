class Solution {
public:
vector<string> split(string &s,char delimiter='.'){
    stringstream ss(s);
    string temp;
    vector<string> v;
    while(getline(ss,temp,delimiter))v.push_back(temp);
    return v;
}
int compareVersion(string version1, string version2) {
    vector<string>v1,v2;
    tie(v1,v2)= make_tuple(split(version1),split(version2));
    int idx=0;
    for(int i=0;i<v1.size()&&i<v2.size();i++,idx++){
        int a = stoi(v1[i]);
        int b = stoi(v2[i]);
        if(a<b) return -1;
        else if(a>b) return 1;
    }
    for(int i=idx;i<v1.size();i++)if(stoi(v1[i])>0)return 1;
    for(int i=idx;i<v2.size();i++)if(stoi(v2[i])>0)return -1;
    return 0;
}
};
