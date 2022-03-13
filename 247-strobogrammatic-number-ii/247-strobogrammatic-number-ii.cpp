class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        map<char,char>hm = {{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        string current = "";
        for(int i = 0 ; i<n; ++i){
            current += " ";
        }
        vector<string>ans;
        help_findStrobogrammatic(ans, hm, current, 0,n-1);
        return ans;
    }
    
    void help_findStrobogrammatic(vector<string>&ans, map<char,char>&hm, 
                                  string current, int l, int r){
        if(l>r){
            ans.push_back(current);
            return;
        }
        
        if(l == r){
            for(auto p:hm){
                if(('6' != p.first) && ('9' != p.first)){
                    current[l] = p.first;
                    current[r] = p.second;
                    help_findStrobogrammatic(ans, hm, current, l+1, r-1);
                }
            }
            return;
        }
        
        if(0 == l){
            for(auto p:hm){
                if('0' != p.first){
                    current[l] = p.first;
                    current[r] = p.second;
                    help_findStrobogrammatic(ans, hm, current, l+1, r-1);
                }
            }
            return;
        }
        
        for(auto p:hm){
            current[l] = p.first;
            current[r] = p.second;
            help_findStrobogrammatic(ans, hm, current, l+1, r-1);
        }
        return;
    }
};