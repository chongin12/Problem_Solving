import java.util.*

fun cnt(s: String, c: Char): Int {
    var r=0
    for(i in s) {
        if(i==c) r++
    }
    return r
}

fun main() = with(Scanner(System.`in`)) {
    val t = nextInt()
    nextLine()
    repeat(t) {
        var s: String = nextLine()
        val gcnt = cnt(s,'g') + cnt(s,'G')
        val bcnt = cnt(s,'b') + cnt(s,'B')
        if(gcnt>bcnt){
            println(s+" is GOOD")
        }
        else if(gcnt<bcnt){
            println(s+" is A BADDY")
        }
        else {
            println(s+" is NEUTRAL")
        }
    }
}