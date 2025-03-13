import java.util.*
fun main() = with(Scanner(System.`in`)) {
    /* val (a, b) = nextLine().split(' ').map { it.toInt() }
    println(a + b) */
    val a = nextLine().toInt()
    for (i in 0..<a) {
        var (y,m) = nextLine().split(' ').map { it.toInt() }
        if (m==1) {
            y-=1
            m=13
        }
        m-=1
        var k = 0
        if (m==2){
            if (y%400==0 || (y%4==0) && (y%100!=0)){
                k=29
            }
            else {
                k=28
            }
        }
        else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) {
            k=31
        }
        else {
            k=30
        }
        println("$y $m $k")
    }
}