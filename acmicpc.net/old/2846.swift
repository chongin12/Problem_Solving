import Foundation

final class FastIO {
    var output: String = ""
    private let buffer:[UInt8]
    private var index: Int = 0
    init(fileHandle: FileHandle = FileHandle.standardInput) {
        buffer = Array(try! fileHandle.readToEnd()!)+[UInt8(0)]
    }
    @inline(__always) private func read() -> UInt8 {
        defer { index += 1 }
        return buffer[index]
    }
    @inline(__always) func readInt() -> Int {
        var sum = 0
        var now = read()
        var isPositive = true
        while now == 10 || now == 32 { now = read() }
        if now == 45 { isPositive.toggle(); now = read() }
        while now >= 48, now <= 57 {
            sum = sum * 10 + Int(now-48)
            now = read()
        }
        return sum * (isPositive ? 1:-1)
    }
    @inline(__always) func readString() -> String {
        var now = read()
        while now == 10 || now == 32 { now = read() }
        let beginIndex = index - 1
        while now != 10,
              now != 32,
              now != 0 { now = read() }
        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }
    @inline(__always) func readLine() -> String {
        var now = read()
        while now == 10 || now == 32 { now = read() }
        let beginIndex = index - 1
        while now != 10,
              now != 0 { now = read() }
        return String(bytes: Array(buffer[beginIndex..<(index-1)]), encoding: .ascii)!
    }
    @inline(__always) func print(_ toPrint: String) {
        output.write(toPrint)
    }
}

let fastio = FastIO()
defer {
    print(fastio.output)
}

var n = fastio.readInt()
var prevFirst = fastio.readInt()
var prev = prevFirst
var res = 0
for _ in 1..<n {
    var a = fastio.readInt()
    if prev >= a {
        res = max(res, prev-prevFirst)
        prevFirst = a
    }
    prev = a
}
res = max(res, prev-prevFirst)
fastio.print("\(res)")
