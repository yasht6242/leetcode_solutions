class Solution {
private:
    void generateCombination(int n, int k, int current, vector<int>& combination, vector<vector<int>>& result){
        if(combination.size()==k){
            result.push_back(combination);
            return;
        }
        for(int i =current;i<=n;i++){
            combination.push_back(i);
            generateCombination(n,k,i+1,combination,result);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> combination;
        generateCombination(n,k,1,combination,result);
        return result;
    }
};