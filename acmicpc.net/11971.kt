import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.math.*

fun main() = with(Scanner(System.`in`)) {
    val (n, m) = nextLine().split(' ').map { it.toInt() }
    var a = 0 to 0
    var b = 0 to 0
    var q1 = ArrayDeque<Pair<Int,Int>>()
    var q2 = ArrayDeque<Pair<Int,Int>>()
    for (i in 0..<n) {
        val l = nextLine().split(' ').map { it.toInt() }
        q1.add(l[0] to l[1])
    }
    for (j in 0..<m) {
        val l = nextLine().split(' ').map { it.toInt() }
        q2.add(l[0] to l[1])
    }
    var res = 0
    while (!q1.isEmpty() || !q2.isEmpty()) {
        if(a.first == 0) {
            a = q1.removeFirst()
        }
        if(b.first == 0) {
            b = q2.removeFirst()
        }

        res=max(res, max(0, b.second - a.second));
        // println("b : ${b}, a : ${a}")
        if(a.first < b.first) {
            b = b.first - a.first to b.second
            a = 0 to 0
        }
        else {
            a = a.first - b.first to a.second
            b = 0 to 0
        }
    }
    println(res)
}