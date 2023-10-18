class Solution {
private:
    void generatePermutations(vector<vector<int>>& permutations, vector<int>& current, vector<int>& nums, vector<bool>& used){
    if (current.size() == nums.size()) {
        permutations.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        current.push_back(nums[i]);
        generatePermutations(permutations, current, nums, used);
        current.pop_back();
        used[i] = false;
    }
}
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> current;
        vector<bool> used(nums.size(),false);
        generatePermutations(permutations,current,nums,used);
        return permutations;
    }
};