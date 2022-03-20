class Solution {
public:
    int minDominoRotations(vector<int> &a, vector<int> &b) {
        // support variables
        int len = a.size(), freq[7], freqA[7], freqB[7], mostFreq = 0;
        for (int i = 0; i < 7; i++) freq[i] = 0, freqA[i] = 0, freqB[i] = 0;
        // getting the frequencies
        for (int i = 0, na, nb; i < len; i++) {
            na = a[i], nb = b[i];
            // increasing overall frequency
            freq[na]++;
            // not counting duplicated tiles (ie: [4, 4]) twice
            if (nb != na) freq[nb]++;
            // increasing freqs of each row
            freqA[na]++;
            freqB[nb]++;
        }
        // finding mostFreq
        for (int i = 1; i < 7; i++) if (freq[mostFreq] < freq[i]) mostFreq = i;
        // exiting if mostFreq is frequent enough
        if (freq[mostFreq] != len) return -1;
        // returning the most convenient amount of switches
        return min(len - freqA[mostFreq], len - freqB[mostFreq]);
    }
};