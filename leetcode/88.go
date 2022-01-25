package leetcode

// https://leetcode.com/problems/merge-sorted-array/

// TODO: resolve
func merge(nums1 []int, m int, nums2 []int, n int)  {
	i, j := len(nums1)-n, 0
	for i<len(nums1) && j<len(nums2) {
		nums1[i]=nums2[j]
		i++
		j++
	}

	res := mergeSort(nums1, 0, len(nums1)-1)
	for i:=0;i<len(res);i++{
		nums1[i]=res[i]
	}
}

func merge1(left, right []int) []int {
	result := make([]int, len(left) + len(right))
	i, j, k := 0, 0, 0
	for i < len(left) && j < len(right) {
		if left[i] <= right[j] {
			result[k] = left[i]
			i++
		} else {
			result[k] = right[j]
			j++
		}
		k++
	}
	for i := i; i < len(left); i++ {
		result[k] = left[i]
		k++
	}
	for j := j; j < len(right); j++ {
		result[k] = right[j]
		k++
	}
	return result
}

func mergeSort(ints []int, l, r int) []int {
	if l == r {
		return []int{ints[l]}
	}

	m := (l+r)/2
	left := mergeSort(ints, l, m)
	right := mergeSort(ints, m+1, r)
	return merge1(left, right)
}
