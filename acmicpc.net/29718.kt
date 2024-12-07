import java.util.*
import kotlin.math.*

fun main() = with(Scanner(System.`in`)) {
    val (n,m) = readln().split(" ").map { it.toInt() }
    var total = Array(2001) { Array(2001) { 0 } }
    var arr = Array(2001) { 0 }
    var acc=0
    for(i in 0 until n) {
        val temp = readln().split(" ").map { it.toInt() }
        for(j in 0 until temp.size){
            total[i][j]=temp[j]
        }
    }
    for(i in 0 until m){
        for(j in 0 until n){
            arr[i] += total[j][i]
        }
    }
    val A = readln().toInt()
    for(i in 0 until A) {
        acc+=arr[i]
    }
    var res=acc
    for(i in A until m) {
        acc=acc-arr[i-A]+arr[i]
        res=max(res,acc)
    }
    println(res)
}