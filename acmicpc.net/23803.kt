import java.util.*
fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    for (i in 0..<n*5) {
        if (i/n<4) {
            for (j in 0..<n) {
                print("@")
            }
        }
        else {
            for (j in 0..<n*5) {
                print("@")
            }
        }
        println()
    }
}