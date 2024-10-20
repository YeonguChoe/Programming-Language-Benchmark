# python3 main.py 100

import sys
import time

def factorial(num):
    if num == 0 or num == 1:
        return 1
    result = 1
    for i in range(2, num + 1):
        result *= i
    return result

def main():
    iteration = int(sys.argv[1])

    factorial_input = 20
    final_value = (iteration - 2) ** 4
    count = 0

    # Start timer
    start = time.time()
    
    for i in range(2, iteration):
        for j in range(2, iteration):
            for k in range(2, iteration):
                for m in range(2, iteration):
                    result = factorial(factorial_input)
                    count += 1

    # End timer
    end = time.time()

    print(f"Expected count: {final_value}")
    print("==================================================")
    
    elapsed_time = end - start
    print(f"Python Runtime: {elapsed_time:.6f} seconds")
    print("==================================================")
    
    return 0

if __name__ == "__main__":
    main()
