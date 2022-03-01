class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int left = 0, right = nums.size()-1;
        int Kstart = nums[0]-1;
        while(left>=0 && right<nums.size() && left <= right){
            int mid = left + (right-left)/2;
            if(nums[mid]-mid-1 < k+Kstart){
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return left+k+Kstart;
    }
};