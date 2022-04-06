class Solution {
public:
    vector<string> expand(string str) {
        // adding '{' to str to digest the end of the string 
        auto substrings = getSubstrings(str + '{');
        vector<string> output;
        // start backtracking
        generateStrings(substrings, output, "", 0);
        return output;
    }
private:
    vector<vector<string>> getSubstrings(const string& str) {
        stack<char> to_process;
        vector<vector<string>> substrings;
        for (auto c : str) {
            if (isalpha(c)) {
                to_process.emplace(c);
            } else {
                if (c == '{') { // process single word
                    string ptrn = "";
                    while (!empty(to_process)) {
                        ptrn += to_process.top();
                        to_process.pop();
                    }
                    if (!empty(ptrn)) {
                        reverse(begin(ptrn), end(ptrn));
                        substrings.push_back({ptrn});
                    }
                } else if (c == '}') { // process character combinations
                    vector<string> ptrn = {};
                    while (!empty(to_process)) {
                        ptrn.emplace_back(string(1, to_process.top()));
                        to_process.pop();
                    }
                    if (!empty(ptrn)) {
                        sort(begin(ptrn), end(ptrn));
                        substrings.push_back(ptrn);
                    }
                }
            }
        }
        return substrings;
    }
    
    void generateStrings(const vector<vector<string>>& substrings, vector<string>& output, string curr, int idx) {
        if (idx >= size(substrings)) {
            output.emplace_back(curr);
            return;
        }
        for (auto i = 0; i < size(substrings[idx]); ++i) {
            generateStrings(substrings, output, curr + substrings[idx][i], idx + 1);
        }
    }
};