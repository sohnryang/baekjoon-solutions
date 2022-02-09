/*
 * Baekjoon Online Judge #9375
 * https://www.acmicpc.net/problem/9375
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var T int
	fmt.Fscan(reader, &T)
	for i := 0; i < T; i++ {
		var N int
		fmt.Fscan(reader, &N)
		clothes := make(map[string]int)
		for j := 0; j < N; j++ {
			var S string
			fmt.Fscan(reader, &S)
			fmt.Fscan(reader, &S)
			_, exists := clothes[S]
			if !exists {
				clothes[S] = 0
			}
			clothes[S]++
		}
		res := 1
		for _, v := range clothes {
			res *= v + 1
		}
		fmt.Fprintln(writer, res-1)
	}
}
