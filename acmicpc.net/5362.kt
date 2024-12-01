import java.util.*

fun main() = with(Scanner(System.`in`)) {
    while(true) {
        var str: String = readLine() ?: break
        str = str.replace("iiing", "th")
        println(str)
    }
}