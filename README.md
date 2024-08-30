# Programming Language Benchmark
- Tester: Yeongu Choe
- Enviroment


| Programming Language | Environment |
| -------------------- | ----------- |
| C                    | clang       |
| C++                  | clang++     |
| Java                 | openjdk     |
| Go                   | go          |
| Rust                 | rustc       |
| Zig                  | zig         |

- Algorithm used.
  - Time compleixty: $O(n^4 \cdot n!)$

  ```python
  def main(n):
      for i in range(n):
          for j in range(n):
              for k in range(n):
                  for m in range(n):
                      factorial(n)
  ```

## Result
- Runtime speed: C > C++ > Zig > Rust > Swift >> Kotlin > Java > C# > Go
