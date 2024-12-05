import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n=readln().toInt()
    for(t in 0..n-1) {
        val (s1,s2)=readln().split(" ")
        var res="Case ${t+1}: "
        if(s1==s2){
            res+="Login successful."
        }
        else {
            res+="Wrong password."
            // s1에서 숫자 다 뺐더니 s2
            var t2=""
            for(i in s1){
                if(i>='a' && i<='z') {
                    t2+=i
                }
                else if(i>='A' && i<='Z') {
                    t2+=i
                }
            }
            if(t2==s2){
                res+=" Please, check your num lock key."
                println(res)
                continue
            }
            // s1에서 다 뒤집었더니 s2
            var t3=""
            for(i in s1){
                if(i>='a' && i<='z') {
                    val k: Int = i-'a'+'A'.code
                    t3+=k.toChar()
                }
                else if(i>='A' && i<='Z') {
                    val k: Int = i-'A'+'a'.code
                    t3+=k.toChar()
                }
                else {
                    t3+=i
                }
            }
            if(t3==s2){
                res+=" Please, check your caps lock key."
                println(res)
                continue
            }
            // s1에서 숫자 다 빼고 뒤집었더니 s2
            var t1=""
            for(i in s1){
                if(i>='a' && i<='z') {
                    val k: Int = i-'a'+'A'.code
                    t1+=k.toChar()
                }
                if(i>='A' && i<='Z') {
                    val k: Int = i-'A'+'a'.code
                    t1+=k.toChar()
                }
            }
            if(t1==s2){
                res+=" Please, check your caps lock and num lock keys."
                println(res)
                continue
            }
            

        }
        println(res)
    }
}