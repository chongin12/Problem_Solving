import kotlin.math.*
import java.util.*
fun main() = with(Scanner(System.`in`)) {
    val a = min(9, nextInt())
    val b = min(9, nextInt())
    val res = max(0, a + b - 9)
    
    if (res == 1) {
        println("There is 1 way to get the sum 10.")
    }
    else {
        println("There are $res ways to get the sum 10.")
    }
}