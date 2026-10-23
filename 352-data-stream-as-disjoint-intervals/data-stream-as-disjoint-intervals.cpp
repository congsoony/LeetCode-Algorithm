class SummaryRanges {
public:

    vector<int> parent,check;
    set<int> s;
    int find(int idx){
        if(parent[idx]==idx)return idx;
        return parent[idx]=find(parent[idx]);
    }
    void unite(int a,int b){
        a = find(a);
        b = find(b);
        if(a<b)
            parent[a]=b;
        else
            parent[b]=a;
    }
    SummaryRanges() {
        check=parent = vector<int>(10005);
        for(int i =1;i<=10004;i++)parent[i]=i;
    }
    
    void addNum(int value) {
        check[value]=1;
        s.insert(value);
        if(value-1>=0&&check[value-1]){
            unite(value-1,value);
            s.erase(value);
        }
        if(check[value+1]){
            unite(value,value+1);
            s.erase(value+1);
        }
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ret;
        for(int i:s){
            ret.push_back({i,find(i)});
        }
        return ret;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */