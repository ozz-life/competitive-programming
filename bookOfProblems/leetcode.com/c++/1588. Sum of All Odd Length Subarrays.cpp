class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    // Two pointers
    // int n = arr.size();
    // int ans = 0;

    // for (int k = 1; k <= n; k += 2) {
    //   int l = 0, r = 0;
    //   int sum = 0;

    //   while (r < n) {
    //     sum += arr[r];
    //     if (r - l + 1 < k) {
    //       ++r;
    //     } else if (r - l + 1 == k) {
    //       ans += sum;
    //       sum -= arr[l];
    //       ++l;
    //       ++r;
    //     }
    //   }
    // }
    // return ans;

    ///////////////////////////////////////////////////////////

    // std::vector<int> prefix_sum(arr.size() + 1, 0);
    // partial_sum(arr.begin(), arr.end(), prefix_sum.begin() + 1);

    // int ans = 0;
    // for (int i = 1; i <= arr.size(); i++) {
    //   ans += prefix_sum[i] - prefix_sum[i - 1];

    //   if (i >= 3) {
    //     int r = i;
    //     for (int l = i - 3; l >= 0; l -= 2)
    //       ans += prefix_sum[r] - prefix_sum[l];
    //   }
    // }

    // return ans;

    ////////////////////////////////////////////////////////////

	std::vector<int> prefix_sum(arr.size() + 1);

    for (int i = 0; i < arr.size(); i++) {
      prefix_sum[i + 1] = prefix_sum[i] + arr[i];
    }

    int subarrayLength = 3, len = arr.size(), ans = 0;
    while (len - subarrayLength >= 0) {
      for (int i = subarrayLength; i < len + 1; i++) {
        ans += (prefix_sum[i] - prefix_sum[i - subarrayLength]);
      }
      subarrayLength += 2;
    }

    ans += prefix_sum[len];
    return ans;
  }
};