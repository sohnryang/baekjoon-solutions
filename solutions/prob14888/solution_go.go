/*
 * Baekjoon Online Judge #14888
 * https://www.acmicpc.net/problem/14888
 */

package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

type State struct {
	i int
	v int
	o [4]int
}

const (
	MaxResult = 1e9 + 1
	MinResult = -MaxResult
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)

	A := make([]int, N)
	for i := range A {
		fmt.Fscan(reader, &A[i])
	}
	var opCount [4]int
	for i := range opCount {
		fmt.Fscan(reader, &opCount[i])
	}

	stack := list.New()
	stack.PushBack(State{1, A[0], opCount})
	min, max := int(MaxResult), int(MinResult)
	for stack.Len() > 0 {
		here := stack.Back().Value.(State)
		stack.Remove(stack.Back())
		if here.i == N {
			if here.v < min {
				min = here.v
			}
			if here.v > max {
				max = here.v
			}
		}
		for i := range here.o {
			next := here
			if next.o[i] == 0 {
				continue
			}
			switch i {
			case 0:
				next.v += A[next.i]
			case 1:
				next.v -= A[next.i]
			case 2:
				next.v *= A[next.i]
			case 3:
				next.v /= A[next.i]
			}
			next.o[i]--
			next.i++
			stack.PushBack(next)
		}
	}
	fmt.Println(max)
	fmt.Println(min)
}
