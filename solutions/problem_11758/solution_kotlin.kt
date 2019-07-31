/*
 * Baekjoon Online Judge #11758
 * https://www.acmicpc.net/problem/11758
 */

fun ccw(x1: Int, y1: Int, x2: Int, y2: Int, x3: Int, y3: Int): Int {
    val D = (x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)
    if (D > 0) {
        return 1
    } else if (D < 0) {
        return -1;
    } else {
        return 0;
    }
}

fun main() {
    var input = readLine()!!.split(" ")
    val x1 = input[0].toInt()
    val y1 = input[1].toInt()
    input = readLine()!!.split(" ")
    val x2 = input[0].toInt()
    val y2 = input[1].toInt()
    input = readLine()!!.split(" ")
    val x3 = input[0].toInt()
    val y3 = input[1].toInt()
    println(ccw(x1, y1, x2, y2, x3, y3))
}
