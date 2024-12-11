import java.util.*

fun main() = with(System.`in`.bufferedReader()) {
    val T = readln().toInt()
    var l=-2
    var r=-2
    var res = 0
    repeat(T){
        val st = StringTokenizer(readln(), " ")
        var a =-9
        var b=-9
        while (st.hasMoreTokens()) {
            if(a==-9) a=st.nextToken().toInt()
            else b=st.nextToken().toInt()
        }
        if(a==b && a!=0) res++
        if(l==a && a!=0) res++
        if(r==b && b!=0) res++
        l=a
        r=b
    }
    println(res)
}