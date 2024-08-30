/**
 * Production compile command
 * clang++ -O3 -o CPP_program main.cpp
 * g++ -O3 -o CPP_program main.cpp
 */

#include <iostream>
#include <ctime>
#include <string>

// 팩토리얼을 계산하는 함수
unsigned long long int factorial(unsigned long long int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    unsigned long long int result = 1;
    for (int i = 2; i <= num; i++)
    {
        result *= i;
    }
    return result;
}

int main(int argc, char *argv[])
{

    unsigned long long int iteration;
    try
    {
        iteration = std::stoull(argv[1]);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Invalid argument: not a number" << std::endl;
        return 1;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Invalid argument: number out of range" << std::endl;
        return 1;
    }

    unsigned long long int factorial_input = 20;

    unsigned long long int final_value = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2);
    unsigned long long int count = 0;

    // count가 final_value에 도달할 때를 확인하기 위한 변수
    bool found = false;

    // 시간 측정을 시작
    std::clock_t start = std::clock();
    for (int i = 2; i < iteration; i++)
    {
        for (int j = 2; j < iteration; j++)
        {
            for (int k = 2; k < iteration; k++)
            {
                for (int m = 2; m < iteration; m++)
                {

                    // factorial 함수를 호출하여 결과를 계산
                    unsigned long long result = factorial(factorial_input);

                    count += 1;

                    // count가 final_value와 같은지 확인
                    if (count == final_value)
                    {
                        std::cout << "==================================================" << std::endl;
                        std::cout << "Expected count:" << count << std::endl;
                    }
                }
            }
        }
    }

    // 시간 측정을 끝냄
    std::clock_t end = std::clock();

    std::cout << "Expected count:" << final_value << std::endl;
    std::cout << "==================================================" << std::endl;

    // 계산 시간
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // 결과 출력
    printf("C++ Runtime: %f seconds\n", elapsed_time);
    std::cout << "==================================================" << std::endl;

    return 0;
}
