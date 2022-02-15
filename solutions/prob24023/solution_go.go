/*
 * Baekjoon Online Judge #24023
 * https://www.acmicpc.net/problem/24023
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

	var N, K int
	fmt.Fscan(reader, &N, &K)
	A := make([]int, N)
	for i := range A {
		fmt.Fscan(reader, &A[i])
	}

	lo := 0
	orSum := 0
	// f(0, 0) = 0, f(0, 1) = 1, f(1, 0) = 0, f(1, 1) = 0
	// f(x, y) = (x + y) and (y == 1)
	for i, elem := range A {
		if ((elem ^ K) & elem) != 0 {
			lo = i + 1
			orSum = 0
			continue
		}
		orSum |= elem
		if orSum == K {
			fmt.Fprintln(writer, lo+1, i+1)
			break
		}
	}
	if orSum != K {
		fmt.Fprintln(writer, -1)
	}
}
