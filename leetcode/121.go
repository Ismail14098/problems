package leetcode

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

func maxProfit(prices []int) int {
	if len(prices) == 1 {
		return 0
	}
	l, r := 0, 1
	max := 0
	for r < len(prices) {
		if prices[r] > prices[l]  {
			profit := prices[r] - prices[l]
			if profit > max {
				max = profit
			}
		}
		if prices[r]<prices[l] {
			l = r
		}
		r++
	}
	return max
}
