import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val N = readln().toInt()
    if(N<=100000 && N%2024==0){
        println("Yes")
    }
    else {
        println("No")
    }
}