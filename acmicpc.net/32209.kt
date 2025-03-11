import java.util.*
fun main() = with(Scanner(System.`in`)) {
    /* val (a, b) = nextLine().split(' ').map { it.toInt() }
    println(a + b) */
    val a = nextLine().toInt()
    var k = 0
    for (i in 0..<a) {
        val (x,y) = nextLine().split(' ').map { it.toInt() }
        if (x==1) {
            k+=y
        }
        else {
            k-=y
            if (k < 0) {
                println("Adios")
                return
            }
        }
    }
    println("See you next month")
}