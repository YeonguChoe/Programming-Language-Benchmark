/**
 * Production compile command
 * javac main.java
 * java main
 */

// There is no unsigned data type in Java

public class main {

    public static long factorial(long num) {
        if (num == 0 || num == 1) {
            return 1;
        }
        long result = 1;
        for (long i = 2; i <= num; i++) {
            result *= i;
        }
        return result;
    }

    public static void main(String[] args) {
        long iteration;
        try {
            iteration = Long.parseLong(args[0]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid argument: not a number");
            return;
        }
        long factorialInput = 20;

        long count = 0;
        long finalValue = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2);

        // Start timer
        long start = System.currentTimeMillis();

        for (long i = 2; i < iteration; i++) {
            for (long j = 2; j < iteration; j++) {
                for (long k = 2; k < iteration; k++) {
                    for (long m = 2; m < iteration; m++) {
                        long result = factorial(factorialInput);
                        count += 1;
                        if (count == finalValue) {
                            System.out.println("==================================================");
                            System.out.println("Result count:" + count);
                        }
                    }
                }
            }
        }

        // End timer
        long end = System.currentTimeMillis();

        // 계산 시간
        double elapsedTime = (end - start) / 1000.0;

        System.out.println("Expected count:" + finalValue);
        System.out.println("==================================================");

        System.out.printf("Java Runtime: %.3f seconds\n", elapsedTime);
        System.out.println("==================================================");
    }
}
