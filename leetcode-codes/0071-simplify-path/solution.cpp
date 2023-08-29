class Solution {
public:
vector<string> split(string &s,char delimiter=' '){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,delimiter))v.push_back(temp);
    return v;
}
string simplifyPath(string path) {
    regex re("//");
    path = regex_replace(path,re,"/");
    vector<string> v=split(path,'/');
    vector<string> rv;
    for(string &s:v){
        if(s=="."||s=="")continue;
        else if(s==".."){
            if(!rv.empty())rv.pop_back();
        }
        else{
            rv.push_back(s);
        }
    }
    string res="/";
    for(string &s:rv)res+=s+"/";
    if(res.size()>1)res.pop_back();
    return res;
}
};
