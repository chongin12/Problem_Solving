import java.util.*
import kotlin.math.*
fun main() = with(Scanner(System.`in`)) {
    /* val (a, b) = nextLine().split(' ').map { it.toInt() }
    println(a + b) */
    val n = nextLine().toInt()
    val arr = nextLine().split(' ').map { it.toInt() }
    var acc=0
    var res=0
    for (i in 1..<arr.size) {
        if (arr[i]>arr[i-1]) {
            acc=max(acc+1, 1)
        }
        if (arr[i]<arr[i-1]) {
            acc=min(acc-1, -1)
        }
        res=max(res,abs(acc))
    }
    println(res+1)
}