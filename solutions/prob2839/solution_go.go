/*
 * Baekjoon Online Judge #2839
 * https://www.acmicpc.net/problem/2839
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

	var n_input int
	fmt.Fscan(reader, &n_input)
	for i := (n_input / 5) * 5; i >= 0; i -= 5 {
		if (n_input-i)%3 != 0 {
			continue
		}
		fmt.Fprintln(writer, i/5+(n_input-i)/3)
		return
	}
	fmt.Fprintln(writer, -1)
}
