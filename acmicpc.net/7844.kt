import java.util.*
fun f(arr: ArrayList<ArrayList<Int>>, n: Int): Boolean {
    for (i in 0..<n) {
        for (j in 0..<n) {
            var set = mutableSetOf<Int>()
            var cnt = 0
            for (k in 0..<n) {
                for (w in 0..<n){
                    if (arr[i*n+k][j*n+w] == 0) {
                        cnt+=1
                    }
                    else {
                        set.add(arr[i*n+k][j*n+w])
                    }
                }
            }
            // println("$i, $j, $cnt, ${set.size}")
            if (cnt + set.size != n*n) {
                return false
            }
        }
    }
    for (i in 0..<n*n) {
        var set = mutableSetOf<Int>()
        var cnt = 0
        for (j in 0..<n*n) {
            if (arr[i][j] == 0) {
                cnt+=1
            }
            else {
                set.add(arr[i][j])
            }
        }
        // println("$i, $cnt, ${set.size}")
        if (cnt + set.size != n*n) {
            return false
        }
    }
    for (i in 0..<n*n) {
        var set = mutableSetOf<Int>()
        var cnt = 0
        for (j in 0..<n*n) {
            if (arr[j][i] == 0) {
                cnt+=1
            }
            else {
                set.add(arr[j][i])
            }
        }
        // println("$i, $cnt, ${set.size}")
        if (cnt + set.size != n*n) {
            return false
        }
    }
    return true
}
fun main() = with(Scanner(System.`in`)) {
    /* val (a, b) = nextLine().split(' ').map { it.toInt() }
    println(a + b) */
    val n = nextLine().trim().toInt()

    var arr = ArrayList<ArrayList<Int>>()
    for (i in 0..<n*n) {
        arr.add(ArrayList(nextLine().trim().split(' ').map { it.toInt() }))
    }

    if (f(arr, n)) {
        println("CORRECT")
    }
    else {
        println("INCORRECT")
    }
}