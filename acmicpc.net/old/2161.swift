struct Queue<T> {
    private var elements: [T?]
    private var headIndex = 0
    private var count = 0
    
    var isEmpty: Bool {
        return count == 0
    }
    
    init(_ capacity: Int) {
        elements = Array<T?>(repeating: nil, count: capacity)
    }
    
    mutating func push(_ element: T) {
        let nextIndex = (headIndex + count) % elements.count
        elements[nextIndex] = element
        count += 1
    }
    
    mutating func pop() -> T {
        let element = elements[headIndex]!
        headIndex = (headIndex + 1) % elements.count
        count -= 1
        return element
    }
    func front() -> T {
        return elements[headIndex]!
    }
}

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
    @inline(__always) func readStringWithSpace() -> String {
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

var N = fastio.readInt()
var queue = Queue<Int>(1000000)
for i in 1...N {
    queue.push(i)
}

while !queue.isEmpty {
    var a = queue.pop()
    fastio.print("\(a) ")
    if !queue.isEmpty {
        queue.push(queue.pop())
    }
}
if !queue.isEmpty {
    fastio.print("\(queue.pop())")
}