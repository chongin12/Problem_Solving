import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)) {
    val N = nextInt()
    nextLine()
    val str:String = nextLine()
    var res=0
    for(i in 0..N/2-1) {
        if(str.get(i)!=str.get(N-1-i)) res+=1
    }
    println(res)
}