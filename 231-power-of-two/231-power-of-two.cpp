class Solution {
public:
    bool isPowerOfTwo(int n) {
        int low, high, mid, cur;
        low=0;
        high=31;
        while(low<=high) {
            mid=(low+high)/2;
            cur=1<<mid;
            if(cur==n)
                return true;
            else if(cur>n)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};