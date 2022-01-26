class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0, seen[101] = {};
        for (int n: nums) seen[n]++;
        for (int f: seen) if (f) res += f * (f - 1) / 2;
        return res;
    }
};