class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        int i=0;
        vector<int> ans;
        int visited=0;
        while(i<s.length()){
            int curLimit=m[s[i]];
            while(i<=curLimit){
                curLimit=max(curLimit, m[s[i]]);
                i++;
            }            
            ans.push_back(i-visited);
            visited=i;
        }
        return ans;
    }
};