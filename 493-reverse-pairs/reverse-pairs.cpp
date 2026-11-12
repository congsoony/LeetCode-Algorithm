#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int M;
    vector<int> tree;

    // 비재귀 세그먼트 트리 업데이트 (idx 위치에 val 누적)
    void update(int idx, int val) {
        for (tree[idx += M] += val; idx > 1; idx >>= 1) {
            tree[idx >> 1] = tree[idx] + tree[idx ^ 1];
        }
    }

    // 비재귀 세그먼트 트리 구간 쿼리 [l, r] (l부터 r까지의 합)
    int query(int l, int r) {
        if (l > r) return 0;
        int res = 0;
        for (l += M, r += M + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
        }
        return res;
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        // 1. 좌표 압축 (nums[i]와 nums[i]*2 를 모두 모아 정렬 및 중복 제거)
        vector<long long> vals;
        for (int x : nums) {
            vals.push_back((long long)x);
            vals.push_back((long long)x * 2LL);
        }
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        // 2. 비재귀 트리는 리프 노드의 개수(M)의 딱 2배 공간만 필요합니다.
        M = vals.size();
        tree.assign(M * 2, 0);

        int res = 0;

        // 3. 뒤에서부터 순회하며 쿼리 및 업데이트 진행
        for (int i = n - 1; i >= 0; i--) {
            int rank_query = lower_bound(vals.begin(), vals.end(), (long long)nums[i]) - vals.begin();
            
            // 나보다 랭크가 작은(엄격히 작은) 값들의 개수를 쿼리
            res += query(0, rank_query - 1);

            // 내 값의 2배가 되는 위치에 1을 추가
            int rank_update = lower_bound(vals.begin(), vals.end(), (long long)nums[i] * 2LL) - vals.begin();
            update(rank_update, 1);
        }

        return res;
    }
};