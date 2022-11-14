/*
 * Baekjoon Online Judge #12015
 * https://www.acmicpc.net/problem/12015
 */

package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	if n == 1 {
		fmt.Fprintln(writer, 1)
		return
	}
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(reader, &a[i])
	}
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = math.MaxInt
	}
	dp[0] = math.MinInt
	for i := 0; i < n; i++ {
		lo := -1
		hi := n
		var mid int
		for lo+1 < hi {
			mid = (lo + hi) / 2
			if dp[mid] < a[i] {
				lo = mid
			} else {
				hi = mid
			}
		}
		if dp[hi-1] < a[i] && a[i] < dp[hi] {
			dp[hi] = a[i]
		}
	}
	res := 0
	for i, x := range dp {
		if x == math.MaxInt {
			res = i - 1
			break
		}
	}
	if res == 0 {
		res = n
	}
	fmt.Fprintln(writer, res)
}
