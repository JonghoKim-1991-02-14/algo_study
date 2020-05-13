/**
 *   Problem: https://www.acmicpc.net/problem/11726
 *   Solver:  Jongho Kim <jongho_kim3@tmax.co.kr>
 */
#include <cstdio>
#include <cstring>

#define MAX_N      1000
#define MIN_N         1
#define DIVISOR   10007

using namespace std;

int table[MAX_N + 1];

int fib(int n) {

  if(n == 1) return 1;
  if(n == 2) return 2;

  if(!table[n])
    table[n] = (fib(n-1) + fib(n-2)) % DIVISOR;

  return table[n];
}

int main(int argc, char *argv[]) {

  int n;
  int answer;

  scanf("%d", &n);

  memset(table, 0, sizeof(int) * (MAX_N + 1));
  answer = fib(n);

  printf("%d", answer);

  return 0;
}
