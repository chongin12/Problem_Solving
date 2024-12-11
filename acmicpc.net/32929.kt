import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = readln().toLong()
    if(n%3L==1L) {
        println("U")
    }
    else if(n%3L==2L){
        println("O")
    }
    else {
        println("S")
    }
}