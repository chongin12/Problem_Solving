import java.util.*

val m = mapOf<String, String>(
    "000000" to "A",
    "100000" to "A",
    "010000" to "A",
    "001000" to "A",
    "000100" to "A",
    "000010" to "A",
    "000001" to "A",
    "001111" to "B",
    "101111" to "B",
    "011111" to "B",
    "000111" to "B",
    "001011" to "B",
    "001101" to "B",
    "001100" to "B",
    "010011" to "C",
    "110011" to "C",
    "000011" to "C",
    "011011" to "C",
    "010111" to "C",
    "010001" to "C",
    "010010" to "C",
    "011100" to "D",
    "111100" to "D",
    "001100" to "D",
    "010100" to "D",
    "011000" to "D",
    "011110" to "D",
    "011101" to "D",
    "100110" to "E",
    "000110" to "E",
    "110110" to "E",
    "101110" to "E",
    "100010" to "E",
    "100100" to "E",
    "100111" to "E",
    "101001" to "F",
    "001001" to "F",
    "111001" to "F",
    "100001" to "F",
    "101101" to "F",
    "101011" to "F",
    "101000" to "F",
    "110101" to "G",
    "010101" to "G",
    "100101" to "G",
    "111101" to "G",
    "110001" to "G",
    "110111" to "G",
    "110100" to "G",
    "111010" to "H",
    "011010" to "H",
    "101010" to "H",
    "110010" to "H",
    "111110" to "H",
    "111000" to "H",
    "111011" to "H",
)

fun main() = with(Scanner(System.`in`)) {
    val n = readln().toInt()
    val s: String = readln()
    var res=""
    for(i in 0 until n) {
        val k = s.substring(6*i until 6*i+6)
        val value = m.get(k)
        if(value == null) {
            println(i+1)
            return
        }
        res+=value
    }
    println(res)

}