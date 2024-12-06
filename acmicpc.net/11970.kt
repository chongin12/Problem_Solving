import java.util.*

fun main() = with(Scanner(System.`in`)) {
    var arr = Array(101) { 0 }
    val (a,b) = readln().split(" ").map { it.toInt() }
    val (c,d) = readln().split(" ").map { it.toInt() }
    for(i in a..b-1){
        arr[i]=1
    }
    for(i in c..d-1){
        arr[i]=1
    }
    var res=0
    for(i in 0..100) {
        if(arr[i]==1) res++
    }
    println(res)
}