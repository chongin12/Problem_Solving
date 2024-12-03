import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val N = nextInt()
    nextLine()
    repeat(N) {
        val s = nextLine()
        val k = s.split(" ")
        var r="god"
        for(i in 1..k.size-1){
            r+=k[i]
        }
        println(r)
    }
}