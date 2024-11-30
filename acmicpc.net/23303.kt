import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val s = readln()
    if(s.indexOf("D2")==-1 && s.indexOf("d2")==-1){
        println("unrated")
    } 
    else {
        println("D2")
    }
}