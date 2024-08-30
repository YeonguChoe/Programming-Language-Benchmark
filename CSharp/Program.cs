/**
 * Production compile command
 * dotnet build -c Release
 * ./CSharp/bin/Release/net8.0/CSharp 100
 */

using System;
using System.Diagnostics;

class Program
{
    static void Main(string[] args)
    {
        if (args.Length < 1)
        {
            Console.WriteLine("Usage: <executable> <iteration>");
            return;
        }

        if (!ulong.TryParse(args[0], out ulong iteration))
        {
            Console.WriteLine("Invalid iteration value.");
            return;
        }

        const ulong factorialInput = 20;
        ulong count = 0;
        ulong finalValue = (iteration - 2) * (iteration - 2) * (iteration - 2) * (iteration - 2);

        // Start timer
        Stopwatch stopwatch = Stopwatch.StartNew();

        for (ulong i = 2; i < iteration; i++)
        {
            for (ulong j = 2; j < iteration; j++)
            {
                for (ulong k = 2; k < iteration; k++)
                {
                    for (ulong m = 2; m < iteration; m++)
                    {
                        ulong result = Factorial(factorialInput);

                        count += 1;
                        if (count == finalValue)
                        {
                            Console.WriteLine("==================================================");
                            Console.WriteLine($"Result count: {count}");
                        }
                    }
                }
            }
        }

        // End timer
        stopwatch.Stop();
        double elapsedTime = stopwatch.Elapsed.TotalSeconds;

        Console.WriteLine($"Expected count: {finalValue}");
        Console.WriteLine("==================================================");
        Console.WriteLine($"C# Runtime: {elapsedTime} seconds");
        Console.WriteLine("==================================================");
    }

    static ulong Factorial(ulong num)
    {
        if (num == 0 || num == 1)
        {
            return 1;
        }
        ulong result = 1;
        for (ulong i = 2; i <= num; i++)
        {
            result *= i;
        }
        return result;
    }
}

