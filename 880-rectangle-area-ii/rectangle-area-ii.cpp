class Solution {
public:
    vector<int> cnt;
    vector<long long> len;
    vector<int> Y;
    
    void update(int node,int start,int end ,int l, int r,int val){
        if(l>end || r<start)return;
        if(l<=start&&end<=r){
            cnt[node]+=val;
        }
        else{
            int mid = (start+end)/2;
            update(node*2,start,mid,l,r,val);
            update(node*2+1,mid+1,end,l,r,val);
        }

        if(cnt[node]> 0){
            len[node]= Y[end+1] - Y[start];
        }
        else{
            if(start ==end)len[node] =0;
            else len[node]=len[node*2] + len[node*2+1];
        }
    }

    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9+7;
        vector<tuple<int,int,int,int>> events;
        for(auto &rect : rectangles){
            events.emplace_back(rect[0],1 , rect[1],rect[3]);
            events.emplace_back(rect[2],-1,rect[1],rect[3]);
            Y.push_back(rect[1]);
            Y.push_back(rect[3]);
        }
        sort(Y.begin(),Y.end());
        Y.erase(unique(Y.begin(),Y.end()),Y.end());

        sort(events.begin(),events.end());

        int m = Y.size();
        cnt = vector<int>(m*4);
        len = vector<long long>(m*4);

        long long ans = 0;
        auto [prev_x, _type, _y1,_y2] = events[0];
        for(auto &e : events){
            auto[x,type,y1,y2] = e;
            ans = (ans+len[1] * (x-prev_x))%MOD;
            prev_x = x;
            int l = lower_bound(Y.begin(),Y.end(),y1) - Y.begin();
            int r = lower_bound(Y.begin(),Y.end(),y2) - Y.begin() -1;
            if(l<=r){
                update(1,0,m-2,l,r,type);
            }
        }
        return ans;

    }
};