class Solution {
public:
  int singleNumber(vector<int> &nums) {
    //     std::unordered_map<int, int> mp;
    //     for(auto &i : nums) mp[i]++;
    //     for(auto &i : mp) {
    //         if (i.second == 1) return i.first;
    //     }
    //     return -1;

    ///////////////////

    // int result = 0;
    // for(int i = 0; i < nums.size(); ++i){
    //     result = result ^ nums[i];
    // OR
    // result ^= nums[i];
    // }
    // return result;

    //////////
    // int ans = 0;
    // for(auto i : nums) ans = ans ^ i;
    // return ans;
    //////////

    // return std::accumulate(nums.begin(), nums.end(), 0, std::bit_xor<int>());

    ///////
    std::sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 2) {
      if (nums[i] != nums[i - 1])
        return nums[i - 1];
    }
    return nums[nums.size() - 1];
  }
};