import java.util.*
fun main() = with(Scanner(System.`in`)) {
    var n = nextLine().toInt()
    var turn = 1
    for (i in 1..<10000) {
        if (turn == 1) {
            n-=i;
            if (n<0) {
                println(-n)
                break
            }
        } else {
            n-=i;
            if (n<0) {
                println(0)
                break
            }
        }
        turn *= -1;
    }
}