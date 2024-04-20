// Жадный алгоритм. Имеет квадратичную сложность O(n^2), где n - количество
// интервалов. Берём каждый исходный отрезок - и ищем, с какими он имеет
// пересечения. Худший случай - нет пересечений, нужно каждый с каждым сравнить,
// чтобы понять , что это действительно так.

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    std::vector<bool> used(intervals.size(), false);
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < intervals.size(); ++i) {
      assert(intervals[i][0] <= intervals[i][1]);
      if (!used[i]) {
        used[i] = true;
        int leftI = intervals[i][0];
        int rightI = intervals[i][1];

        while (true) {
          bool change = false;
          for (int j = 0; j < intervals.size(); ++j) {
            int leftJ = intervals[j][0];
            int rightJ = intervals[j][1];
            if (!used[j] && !(rightI < leftJ || rightJ < leftI)) {
              leftI = min(leftI, leftJ);
              rightI = max(rightI, rightJ);
              used[j] = true;
              change = true;
            }
          }

          if (!change) {
            break;
          }
        }
        ans.push_back({leftI, rightI});
      }
    }
    return ans;
  }
};

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
      return intervals;
    }
    // отсортирует как надо, потому что вектора, когда сравниваются,
    // сравниваются по первым элементам, т.е сортировка будет по левым границам
    sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> ans;
    ans.reserve(intervals.size());
    ans.push_back(move(intervals[0]));

    for (int i = 1; i < intervals.size(); ++i) {
      if (ans.back()[1] >= intervals[i][0]) {
        ans.back()[1] = max(ans.back()[1], intervals[i][1]);
      } else {
        ans.push_back(move(intervals[i]));
      }
    }
    return ans;
  }
};

// Или

class Solution {
public:
  std::vector<std::vector<int>>
  merge(std::vector<std::vector<int>> &intervals) {
    if (intervals.empty()) {
      return {};
    }

    // Сортируем интервалы по начальным точкам
    std::sort(intervals.begin(), intervals.end(),
              [](const auto &a, const auto &b) { return a[0] < b[0]; });

    std::vector<std::vector<int>> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); ++i) {
      if (merged.back()[1] >= intervals[i][0]) {
        // Перекрывающиеся интервалы, объединяем их
        merged.back()[1] = std::max(merged.back()[1], intervals[i][1]);
      } else {
        // Неперекрывающиеся интервалы, добавляем новый интервал
        merged.push_back(intervals[i]);
      }
    }

    return merged;
  }
};

// Или

class Solution {
public:
  map<vector<int>, vector<vector<int>>> graph;
  map<int, vector<vector<int>>> nodes_in_comp;
  set<vector<int>> visited;

  bool overlap(vector<int> &a, vector<int> &b) {
    return a[0] <= b[1] and b[0] <= a[1];
  }

  // Строим граф, в котором существует неориентированное ребро между интервалами
  // u и v, если u и v пересекаются
  void buildGraph(vector<vector<int>> &intervals) {
    for (auto interval1 : intervals) {
      for (auto interval2 : intervals) {
        if (overlap(interval1, interval2)) {
          graph[interval1].push_back(interval2);
          graph[interval2].push_back(interval1);
        }
      }
    }
  }

  // Объединяет все узлы в этой связанной компоненте в один интервал
  vector<int> mergeNodes(vector<vector<int>> &nodes) {
    int min_start = nodes[0][0];
    for (auto node : nodes) {
      min_start = min(min_start, node[0]);
    }

    int max_end = nodes[0][1];
    for (auto node : nodes) {
      max_end = max(max_end, node[1]);
    }

    return {min_start, max_end};
  }

  // Используем поиск в глубину, чтобы пометить все узлы в одной связанной
  // компоненте одним и тем же целым числом
  void markComponentDFS(vector<int> &start, int comp_number) {
    stack<vector<int>> stk;
    stk.push(start);

    while (!stk.empty()) {
      vector<int> node = stk.top();
      stk.pop();

      // Не найдено.
      if (visited.find(node) == visited.end()) {
        visited.insert(node);

        nodes_in_comp[comp_number].push_back(node);

        for (auto child : graph[node]) {
          stk.push(child);
        }
      }
    }
  }

  // получает связные компоненты графа перекрытия интервалов.
  void buildComponents(vector<vector<int>> &intervals) {
    int comp_number = 0;

    for (auto interval : intervals) {
      if (visited.find(interval) == visited.end()) {
        markComponentDFS(interval, comp_number);
        comp_number++;
      }
    }
  }

  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    buildGraph(intervals);
    buildComponents(intervals);

    // Для каждого компонента объедините все интервалы в один интервал.
    vector<vector<int>> merged;
    for (size_t comp = 0; comp < nodes_in_comp.size(); comp++) {
      merged.push_back(mergeNodes(nodes_in_comp[comp]));
    }

    return merged;
  }
};
