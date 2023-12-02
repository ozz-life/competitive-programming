class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> b(n);
        for(int i = 0; i < n; ++i) {
            if(i == 0) {
                b[i] = nums[i];
            } else {
                b[i] = b[i - 1] + nums[i];
            }
        }
        return b;
    }
};