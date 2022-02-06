/*
 * Baekjoon Online Judge #5525
 * https://www.acmicpc.net/problem/5525
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

func Max(x, y int) int {
	if x < y {
		return y
	}
	return x
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)
	var M int
	fmt.Fscan(reader, &M)
	var S string
	fmt.Fscan(reader, &S)
	l := -1
	nextChar := 'I'
	res := 0
	for _, ch := range S {
		if ch != nextChar {
			res += Max(l+1-N, 0)
			if ch == 'I' {
				l = 0
				nextChar = 'O'
			} else {
				l = -1
				nextChar = 'I'
			}
		} else {
			if nextChar == 'I' {
				nextChar = 'O'
				l++
			} else {
				nextChar = 'I'
			}
		}
	}
	res += Max(l+1-N, 0)
	fmt.Fprintln(writer, res)
}
