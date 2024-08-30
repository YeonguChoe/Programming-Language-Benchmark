/**
 * Production compile command
 * swift build -c release
 * ./.build/release/Programming-Language-Benchmark 100
 */


import Foundation

func factorial(_ num: UInt64) -> UInt64 {
    if num == 0 || num == 1 {
        return 1
    }
    var result: UInt64 = 1
    for i in 2...num {
        result *= i
    }
    return result
}

if CommandLine.argc < 2 {
    print("Usage: \(CommandLine.arguments[0]) <iteration>")
    exit(1)
}

guard let iteration = UInt64(CommandLine.arguments[1]) else {
    print("Invalid iteration value.")
    exit(1)
}

let factorialInput: UInt64 = 20
var count: UInt64 = 0
let finalValue = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2)

// Start timer
let start = CFAbsoluteTimeGetCurrent()

for _ in 2..<iteration {
    for _ in 2..<iteration {
        for _ in 2..<iteration {
            for _ in 2..<iteration {
                let _ = factorial(factorialInput)
                count += 1
                if count == finalValue {
                    print("==================================================")
                    print("Result count: \(count)")
                }
            }
        }
    }
}

// End timer
let end = CFAbsoluteTimeGetCurrent()

let elapsedTime = end - start

print("Expected count: \(finalValue)")
print("==================================================")
print("Swift Runtime: \(elapsedTime) seconds")
print("==================================================")
