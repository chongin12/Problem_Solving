import java.util.*
fun main() = with(Scanner(System.`in`)) {
    val n = nextLine().toInt()
    val a = nextLine()
    var arr: Array<Array<Char>> = Array(26,{Array(n,{'a'})})
    for (i in 0..<a.length) {
        val row = i/n
        var col = i%n
        if (row%2==1) col = n-col-1
        arr[row][col] = a[i]
    }
    for (j in 0..<n) {
        for(i in 0..<a.length/n) {
            print(arr[i][j])
        }
    }
    println()
}