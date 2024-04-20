// class Solution {
// public:
//   int lengthOfLongestSubstring(string s) {
//     int ans = 0;
//     for (int len = 1; len < 128 && len < s.size(); ++len) {
//       bool goodLen = false;
//       for (int first = 0; first + len <= s.size(); ++first) {
//         bool used[128] = {};
//         bool good = true;
//         for (int i = first; i < first + len; ++i) {
//           char c = s[i];
//           if (used[c]) {
//             good = false;
//             break;
//           }
//           used[c] = true;
//         }
//         if (good) {
//           ans = len;
//           goodLen = true;
//           break;
//         }
//       }
// 	  if(!goodLen) {
// 		break;
// 	  }
//     }

//     return ans;
//   }
// };

////////////////////////////////////////////////////////////////////////////////

// class Solution {
// public:
//   int lengthOfLongestSubstring(string s) {
//     int ans = 0;
//     for (int first = 0; first < s.size(); ++first) {
//       bool used[128] = {};
//       for (int i = first; i < s.size(); ++i) {
//         char c = s[i];
//         if (used[c]) {
//           break;
//         }
//         used[c] = true;
//         ans = max(ans, i - first + 1);
//       }
//     }

//     return ans;
//   }
// };

////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int ans = 0;
    bool used[128] = {};

    for (int left = 0, right = 0; left < s.size(); ++left) {
      while (right < s.size() && !used[s[right]]) {
        used[s[right]] = true;
        ++right;
      }
      ans = max(ans, right - left);
      used[s[left]] = false;
    }

    return ans;
  }
};