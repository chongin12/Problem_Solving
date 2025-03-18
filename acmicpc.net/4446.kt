import java.util.*
val smallVowels = listOf('a', 'i', 'y', 'e', 'o', 'u')
val smallConsonants = listOf('b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f')
fun f(a: Char): Char {
    for (i in 0..<smallVowels.size) {
        if (smallVowels[i] == a) {
            return smallVowels[(i+3)%smallVowels.size]
        }
    }

    for (i in 0..<smallConsonants.size) {
        if (smallConsonants[i] == a) {
            return smallConsonants[(i+10)%smallConsonants.size]
        }
    }
    return 'a'
}
fun main() = with(Scanner(System.`in`)) {
    try {
        while (true) {
            val a = nextLine()
            for (i in a) {
                if (i.isUpperCase()) {
                    var a = i.lowercaseChar()
                    a = f(a)
                    a = a.uppercaseChar()
                    print(a)
                } else if (i.isLowerCase())  {
                    print(f(i))
                } else {
                    print(i)
                }
            }
            println()
        }
    } catch (e: Exception) {
        
    }
}