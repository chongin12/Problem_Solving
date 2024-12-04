import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val (a,b,c) = readln().split(" ").map { it.toInt() }
    val (d,e,f) = readln().split(" ").map { it.toInt() }
    val A=a+b*2+c*3
    val B=d+e*2+f*3
    if(A>B){
        println(1)
    }
    else if(A<B){
        println(2)
    }
    else{
        println(0)
    }
}