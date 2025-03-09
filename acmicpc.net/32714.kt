import java.util.*
fun main() = with(Scanner(System.`in`)) {
    val a = nextInt()
    val r: Int
    if (a==2) {
        r=1
    }
    else if (a==3) {
        r=3
    }
    else {
        r=a+a+a-4
    }
    println(r)
}