// class Solution {
// public:
//   vector<int> twoSum(vector<int> &nums, int target) {
//     // for(int i = 0; i < nums.size(); ++i) {
//     //     for(int j = i + 1; j < nums.size(); j++) {
//     //         if (nums[i] + nums[j] == target) {
//     //             return {i, j};
//     //         }
//     //     }
//     // }

//     // return {};

//     // unordered_map<int, int> map;
//     // for (int i = 0; i < nums.size(); i++) {
//     //     int diff = target - nums[i];
//     //     if (map.find(diff) != map.end()) {
//     //         return { map[diff], i };
//     //     }
//     //     // map[nums[i]] = i;
//     //     map.insert(make_pair(nums[i], i));
//     // }
//     // return {-1, -1}; // or return {};

//     int n = nums.size();
//     vector<int> ans;
//     vector<pair<int, int>> temp;

//     // Создаем вектор пар (число, индекс)
//     for (int i = 0; i < n; i++) {
//       temp.push_back({nums[i], i});
//     }

//     // Сортируем вектор по значениям чисел
//     sort(temp.begin(), temp.end());

//     int left = 0, right = n - 1;

//     // Используем два указателя: один на начало, другой на конец вектора
//     while (left < right) {
//       int sum = temp[left].first + temp[right].first;

//       // Если сумма равна target, добавляем индексы в ответ и выходим из
//       цикла if (sum == target) {
//         ans.push_back(temp[left].second);
//         ans.push_back(temp[right].second);
//         break;
//       }
//       // Если сумма больше target, уменьшаем правый указатель
//       else if (sum > target) {
//         right--;
//       }
//       // Если сумма меньше target, увеличиваем левый указатель
//       else {
//         left++;
//       }
//     }

//     return ans;
//   }
// };

// Bruteforce
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return {i, j};
        }
      }
    }

    return {};
  }
};

// Unordered Map
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (map.find(diff) != map.end()) {
        return {map[diff], i};
      }
      map[nums[i]] = i;
      //map.insert(make_pair(nums[i], i));
    }
    return {-1, -1}; // or return {};
  }
};

// Two pointer
class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    int n = nums.size();
    vector<int> ans;
    vector<pair<int, int>> temp;

    // Создаем вектор пар (число, индекс)
    for (int i = 0; i < n; i++) {
      temp.push_back({nums[i], i});
    }

    // Сортируем вектор по значениям чисел
    sort(temp.begin(), temp.end());

    int left = 0, right = n - 1;

    // Используем два указателя: один на начало, другой на конец вектора
    while (left < right) {
      int sum = temp[left].first + temp[right].first;

      // Если сумма равна target, добавляем индексы в ответ и выходим из цикла
      if (sum == target) {
        ans.push_back(temp[left].second);
        ans.push_back(temp[right].second);
        break;
      }
      // Если сумма больше target, уменьшаем правый указатель
      else if (sum > target) {
        right--;
      }
      // Если сумма меньше target, увеличиваем левый указатель
      else {
        left++;
      }
    }

    return ans;
  }
};