#include <iostream>
#include <chrono>

using namespace std;


long long cache[1000000] = {0};
long long fib(int n) {
  if (n < 2)
    return n;
  if (cache[n])
    return cache[n];
  return cache[n] = fib(n - 1) + fib(n - 2);
}


int main() {
  int n = 100000;
  const auto start = chrono::steady_clock::now();
  fib(n);
  const auto end = std::chrono::steady_clock::now();
  const auto elapsed = chrono::duration<double>(end - start).count();
  cout << "Fibonacci of " << n << ", ";
  cout << "Time: " << elapsed << " seconds" << endl;
  return 0;
}