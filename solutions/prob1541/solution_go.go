/*
 * Baekjoon Online Judge #1541
 * https://www.acmicpc.net/problem/1541
 */

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var S string
	fmt.Fscan(reader, &S)
	terms := strings.Split(S, "-")
	var res int64
	for i, term := range terms {
		numbers := strings.Split(term, "+")
		var sum int64
		for _, number := range numbers {
			parsed, _ := strconv.ParseInt(number, 10, 32)
			sum += parsed
		}
		res -= sum
		if i == 0 {
			res = -res
		}
	}
	fmt.Fprintln(writer, res)
}
