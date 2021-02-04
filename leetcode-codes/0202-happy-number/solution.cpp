class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visit;
        while (true) {
            int t = n;
            int sum = 0;
            while (t) {
                sum += pow(t % 10, 2);
                t /= 10;
            }
            if (visit.count(sum))
                break;
            visit.insert(sum);
            if (sum == 1)
                return true;
            n = sum;
        }
        return false;
    }
};
