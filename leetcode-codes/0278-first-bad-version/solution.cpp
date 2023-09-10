// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#define ll long long
class Solution {
public:
int firstBadVersion(int n) {
    ll first= 0;
    ll last =n;
    ll res = 0;
    while(first<=last){
        ll mid = (first+last)/2;
        if(isBadVersion(mid)){
            res=mid;
            last=mid-1;
        }
        else first=mid+1;
    }
    return res;
}
};
