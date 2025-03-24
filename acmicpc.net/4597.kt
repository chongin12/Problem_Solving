import java.util.*
fun main() = with(Scanner(System.`in`)) {
    while (true) {
        val n = nextLine()
        if (n == "#") break
        var a = 0
        for (i in 0..<n.length - 1) {
            if (n[i] == '1') a+=1
            print(n[i])
        }
        if (n.last() == 'e') a+=1
        if (a%2==0) println(1)
        else println(0)
    }
}