package leetcode

// https://leetcode.com/problems/reshape-the-matrix/

func matrixReshape(mat [][]int, r int, c int) [][]int {
	m, n := len(mat), len(mat[0])
	if m*n != r*c {
		return mat
	}
	result := make([][]int, r)
	for i := range result {
		result[i] = make([]int, c)
	}
	i, j, i1, j1 := 0,0,0,0
	k := 0
	for k < r*c {
		if j == n {
			j = 0
			i++
		}
		if j1 == c {
			j1 = 0
			i1++
		}
		if i1 == r || i == m {
			break
		}
		result[i1][j1] = mat[i][j]
		j1++
		j++
		k++
	}
	return result
}
