class Solution {
public:
    int countPrimes(int n) {
        vector<int> v;
        bool p[5000001] = { 0 };
        p[0] = 1;
        p[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (p[i] == false) {
                v.push_back(i);
                for (int j = i *2; j <= n; j += i)
                    p[j] = true;
            }
        }
        int cnt = 0;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= n)
                break;
            cnt++;
        }
        return cnt;
    }
};
