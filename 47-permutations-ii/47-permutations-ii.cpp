class Solution {
private:
	void generatePermutations(vector<int>& nums, bool visited[], vector<int>& temp, vector<vector<int>>& ans){
		//Base Case
		if(temp.size() == nums.size()){
			ans.push_back(temp);
			return;
		}
		//Recursive Cases
		for(int i=0;i<nums.size();i++){
			if(visited[i] == true) continue;
			visited[i] = true;
			temp.push_back(nums[i]);
			generatePermutations(nums, visited, temp, ans);
			temp.pop_back();
			visited[i] = false;
			while(i < nums.size()-1 and nums[i] == nums[i+1]) // ignoring the same elements as first element of permutation
				++i;
		}
	}
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        bool visited[n];
        for(int i=0;i<n;i++) visited[i] = false;
        vector<vector<int>> ans;
    	vector<int> temp;
    	sort(nums.begin(), nums.end());
    	generatePermutations(nums, visited, temp, ans);
    	return ans;
    }
};