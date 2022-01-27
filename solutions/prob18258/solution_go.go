/*
 * Baekjoon Online Judge #18258
 * https://www.acmicpc.net/problem/18258
 */

package main

import (
	"bufio"
	"container/list"
	"fmt"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var N int
	fmt.Fscan(reader, &N)
	queue := list.New()
	for i := 0; i < N; i++ {
		var C string
		fmt.Fscan(reader, &C)
		switch C {
		case "push":
			var X int
			fmt.Fscan(reader, &X)
			queue.PushBack(X)
		case "pop":
			front := queue.Front()
			if front == nil {
				fmt.Fprintln(writer, -1)
				continue
			}
			fmt.Fprintln(writer, front.Value)
			queue.Remove(front)
		case "size":
			fmt.Fprintln(writer, queue.Len())
		case "empty":
			if queue.Len() == 0 {
				fmt.Fprintln(writer, 1)
			} else {
				fmt.Fprintln(writer, 0)
			}
		case "front":
			front := queue.Front()
			if front == nil {
				fmt.Fprintln(writer, -1)
				continue
			}
			fmt.Fprintln(writer, front.Value)
		case "back":
			back := queue.Back()
			if back == nil {
				fmt.Fprintln(writer, -1)
				continue
			}
			fmt.Fprintln(writer, back.Value)
		}
	}
}
