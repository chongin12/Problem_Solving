import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val s = nextLine()
    val k = s.split(" ")
    println(min(k[0], k[1]))
}