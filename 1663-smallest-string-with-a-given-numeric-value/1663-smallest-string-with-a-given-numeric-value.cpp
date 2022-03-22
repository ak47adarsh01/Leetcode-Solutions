class Solution {
public:
    string getSmallestString(int n, int k) {
        // support variables
        string res(n, '*');
        int i = n - 1;
        // getting rid of the largest "load"
        while (k - 26 > i) {
            k -= 26;
            res[i--] = 'z';
        }
        // possible central character
        if (i < k) res[i--] = 'a' + (k -= i + 1);
        // 'a's to the end of the world and beyond!
        while (i > -1) res[i--] = 'a';
        return res;
    }
};