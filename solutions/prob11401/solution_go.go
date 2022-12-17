/*
 * Baekjoon Online Judge #11401
 * https://www.acmicpc.net/problem/11401
 */

package main

import (
	"bufio"
	"fmt"
	"os"
)

const Mod = 1_000_000_007

func modFactorial(n int64) int64 {
	var res int64
	res = 1
	for i := int64(0); i < n; i++ {
		res *= i + 1
		res %= Mod
	}
	return res
}

func egcd(a int64, b int64) (int64, int64) {
	if b > 0 {
		x, y := egcd(b, a%b)
		return y, x - (a/b)*y
	}
	return 1, 0
}

func modInv(x int64, m int64) int64 {
	g, _ := egcd(x, m)
	return (g + m) % m
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()
	var nInput, kInput int64
	fmt.Fscan(reader, &nInput, &kInput)
	facN := modFactorial(nInput)
	facK := modFactorial(kInput)
	facNMinK := modFactorial(nInput - kInput)
	fmt.Fprintln(writer, facN*modInv(facK*facNMinK%Mod, Mod)%Mod)
}
