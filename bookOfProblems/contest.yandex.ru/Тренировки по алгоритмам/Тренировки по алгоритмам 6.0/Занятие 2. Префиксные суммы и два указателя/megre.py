def merge(nums1, nums2):
    merged = [0] * (len(nums1) + len(nums2))
    first1 = first2 = 0
    for k in range(len(nums1) + len(nums2)):
        # Если первая последовательность ещё не кончилась
        # И вторая последовательность кончилась
        # ИЛИ число в первой последовательности меньше или равно, чем во второй
        if first1 != len(nums1) and (
            first2 == len(nums2) or nums1[first1] <= nums2[first2]
        ):
            merged[k] = nums1[first1]
            first1 += 1
        else:
            merged[k] = nums2[first2]
            first2 += 1
        return megred
