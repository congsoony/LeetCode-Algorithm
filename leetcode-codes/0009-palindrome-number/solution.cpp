class Solution {
public:
    bool isPalindrome(int x) {
        string t=to_string(x);
        int l=0,r=t.size()-1;
        while(l<=r){
            if(t[l]!=t[r])return false;
            l++;
            r--;
        }
        return true;
    }
};
