package leetcode

// https://leetcode.com/problems/intersection-of-two-arrays-ii/

func intersect(nums1 []int, nums2 []int) []int {
	m := make(map[int]int)
	for i:=0;i<len(nums1);i++ {
		m[nums1[i]] += 1
	}
	var result []int
	for i:=0;i<len(nums2);i++ {
		if x, ok := m[nums2[i]]; ok && x != 0 {
			m[nums2[i]] -= 1
			result = append(result, nums2[i])
		}
	}
	return result
}
