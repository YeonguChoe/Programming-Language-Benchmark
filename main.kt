// Production compile command
// kotlinc main.kt -include-runtime -d main.jar
// java -jar main.jar 100

import kotlin.system.measureTimeMillis

fun factorial(num: Long): Long {
    if (num == 0L || num == 1L) {
        return 1L
    }
    var result = 1L
    for (i in 2..num) {
        result *= i
    }
    return result
}

fun main(args: Array<String>) {
    if (args.isEmpty()) {
        println("Please provide an iteration count as a command-line argument.")
        return
    }

    val iteration =
            args[0].toLongOrNull()
                    ?: run {
                        println("Invalid iteration count.")
                        return
                    }

    val factorialInput = 20L
    var count = 0L
    val finalValue = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2)

    // Start timer
    val elapsedTime = measureTimeMillis {
        for (i in 2 until iteration) {
            for (j in 2 until iteration) {
                for (k in 2 until iteration) {
                    for (m in 2 until iteration) {
                        val result = factorial(factorialInput)

                        count += 1
                        if (count == finalValue) {
                            println("==================================================")
                            println("Result count: $count")
                        }
                    }
                }
            }
        }
    }

    println("Expected count: $finalValue")
    println("==================================================")
    println("Kotlin Runtime: ${elapsedTime / 1000.0} seconds")
    println("==================================================")
}
