class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int> &piles, int index) {
        if (index == piles.size() / 2) return 0;
        if (memo.count(index)) return memo[index];
        int n = piles.size() - 1;
        int l = piles[index] + dfs(piles, index + 1);
        int r = piles[n - index] + dfs(piles, index + 1);
        return memo[index] = max(l, r);
    }
    bool stoneGame(vector<int>& piles) {
        return dfs(piles, 0) * 2 > accumulate(begin(piles), end(piles), 0);
    }
};