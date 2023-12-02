class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> leftSum(n), rightSum(n), answer(n);
        
        for(int i = 0; i < n - 1; ++i) {
            leftSum[i + 1] = leftSum[i] + nums[i];
        }
        
        for(int i = n - 2; i >= 0; --i) {
            rightSum[i] = rightSum[i + 1] + nums[i + 1];
        }

        for(int i = 0; i < n; ++i) {
            answer[i] = std::abs(leftSum[i] - rightSum[i]);
        }
        
        return answer;
    }
};