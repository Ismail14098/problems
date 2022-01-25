package leetcode

// https://leetcode.com/problems/two-sum/

func twoSum(nums []int, target int) []int {
	m := map[int]int{}
	for i:=0; i<len(nums); i++ {
		res := target-nums[i]
		if index, ok := m[res]; ok {
			return []int{index, i}
		}
		m[nums[i]] = i
	}
	return []int{}
}

