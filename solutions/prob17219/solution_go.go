/*
 * Baekjoon Online Judge #17219
 * https://www.acmicpc.net/problem/17219
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

	var N, M int
	fmt.Fscanf(reader, "%d %d", &N, &M)
	passwordTable := make(map[string]string)
	for i := 0; i < N; i++ {
		var K, V string
		fmt.Fscan(reader, &K, &V)
		passwordTable[K] = V
	}
	for i := 0; i < M; i++ {
		var S string
		fmt.Fscan(reader, &S)
		fmt.Fprintln(writer, passwordTable[S])
	}
	defer writer.Flush()
}
