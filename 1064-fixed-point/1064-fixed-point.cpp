class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        
        int start = 0;
        int end = arr.size()-1;
        
        int ans = -1;
        
        while( start <= end){
            int mid =  ( start + end) /2;
            if(arr[mid] == mid){
            
                ans  = mid;
                end = mid-1;
                }
            else if(arr[mid] < mid){
                start = mid+1;
            }
            else {
                    end = mid-1;
            }
        }
        
        return ans;
        
    }
};