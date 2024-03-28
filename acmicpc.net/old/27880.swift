import Foundation
var count: Int = 0
for _ in 0..<4 {
    let l = readLine()!.split(separator: " ")
    if l[0]=="Es"{
        count+=Int(l[1])!*21
    } else {
        count += Int(l[1])!*17
    }
}
print(count)