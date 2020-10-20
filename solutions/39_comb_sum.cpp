//https://leetcode.com/problems/combination-sum/

class Solution {
    using VVI = vector<vector<int>>;
    using VI = vector<int>;
    
public:
    void backtrack(VVI& res, VI& current, VI& candidates, int i, int localSum, const int target)
    {
        if(i >= candidates.size() || localSum < 0 || localSum > target) 
        {
            return;
        }
        
        if (localSum == target)
        {
            res.push_back(current);
        }
        
        for(int j = i; j < candidates.size(); j++)
        {
            localSum += candidates[j];
            current.push_back(candidates[j]);
            backtrack(res, current, candidates, j, localSum, target);
            current.pop_back();
            localSum -= candidates[j];
        }
    }
    
    VVI combinationSum(VI& candidates, int target) {
        VVI result;
        VI temp;
        backtrack(result, temp, candidates, 0, 0, target);
        return result;
    }
};