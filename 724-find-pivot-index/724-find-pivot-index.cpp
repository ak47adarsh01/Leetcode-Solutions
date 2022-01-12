class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int left_sum=0;
        for(int i=0;i<nums.size();i++){
            if(left_sum==sum-nums[i])
                return i;
            left_sum+=nums[i];
            sum-=nums[i];
        }
        return -1;
        
    }
};