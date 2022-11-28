/*
 * Baekjoon Online Judge #1016
 * https://www.acmicpc.net/problem/1016
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

	var minInput, maxInput int64
	fmt.Fscan(reader, &minInput, &maxInput)
	maxSquare := int64(math.Sqrt(float64(maxInput)))
	nonFree := make(map[int64]bool)
	for i := int64(2); i <= maxSquare; i++ {
		minCoeff := int64(math.Ceil(float64(minInput) / float64(i*i)))
		maxCoeff := int64(float64(maxInput) / float64(i*i))
		for j := minCoeff; j <= maxCoeff; j++ {
			nonFree[j*i*i] = true
		}
	}
	fmt.Fprintln(writer, maxInput-minInput+int64(1)-int64(len(nonFree)))
}
