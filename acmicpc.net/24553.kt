import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val T = readln().toInt()
    repeat(T) {
        val N = readln().toLong()
        if(N%10L==0L) println(1)
        else println(0)
    }
}