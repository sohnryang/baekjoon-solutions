/*
 * Baekjoon Online Judge #9252
 * https://www.acmicpc.net/problem/9252
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

const (
	Up int = iota
	Left
	Diag
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var s1, s2 string
	fmt.Fscan(reader, &s1)
	fmt.Fscan(reader, &s2)
	s1 = " " + s1
	s2 = " " + s2
	dp := make([][]int, len(s1))
	direction := make([][]int, len(s1))
	for i := range s1 {
		dp[i] = make([]int, len(s2))
		direction[i] = make([]int, len(s2))
	}
	for i, c1 := range s1 {
		for j, c2 := range s2 {
			if i == 0 || j == 0 {
				dp[i][j] = 0
			} else if c1 == c2 {
				dp[i][j] = dp[i-1][j-1] + 1
				direction[i][j] = Diag
			} else {
				if dp[i-1][j] > dp[i][j-1] {
					dp[i][j] = dp[i-1][j]
					direction[i][j] = Up
				} else {
					dp[i][j] = dp[i][j-1]
					direction[i][j] = Left
				}
			}
		}
	}
	fmt.Fprintln(writer, dp[len(s1)-1][len(s2)-1])
	i := len(s1) - 1
	j := len(s2) - 1
	res := ""
	for i > 0 && j > 0 {
		switch direction[i][j] {
		case Up:
			i--
		case Left:
			j--
		case Diag:
			res = string(s1[i]) + res
			i--
			j--
		}
	}
	fmt.Fprintln(writer, res)
}
