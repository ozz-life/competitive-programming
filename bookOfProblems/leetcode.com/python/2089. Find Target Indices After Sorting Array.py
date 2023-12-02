class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        result = []

        nums.sort()
        for index, i in enumerate(nums):
            if i == target:
                result.append(index)

        return result


################################################################################


class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        return [index for index, i in enumerate(sorted(nums)) if i == target]


################################################################################

class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        def leftmost_binary_search(a, x):
            l = -1
            r = len(a)
            while l <= r:
                m = l + (r - l) // 2
                if a[m] < x:
                    l = m + 1
                else:
                    r = m - 1
            return l
        
        def rightmost_binary_search(a, x):
            l = 0
            r = len(a) - 1
            while l <= r:
                m = l + (r - l) // 2
                if a[m] <= x:
                    l = m + 1
                else:
                    r = m - 1
            return r

        nums.sort()
        result = []

        left = leftmost_binary_search(nums, target)
        right = rightmost_binary_search(nums, target)

        if left < right:
            return [i for i in range(left, right + 1)]

        if left == right:
            return [left]
        
        return []

