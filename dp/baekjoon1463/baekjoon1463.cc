/**
 *   Problem: https://www.acmicpc.net/problem/1463
 *   Solver: Jongho Kim <jongho_kim3@tmax.co.kr>
 */

#include <cstdio>
#include <cstring>
#include <algorithm>   // min()

#define MAX_N   1000000
#define MIN_N         1

using namespace std;

int table[MAX_N + 1];

int solve(int n) {

  int solution;
  int tmp_min;

  if(n==1) return 0;
  if(table[n]) return table[n];

  switch(n % 6) {

  case 0:
    tmp_min = min(solve(n/3), solve(n/2));
    solution = 1 + min(tmp_min, solve(n-1));
    break;

  case 2:
  case 4:
    solution = 1 + min(solve(n/2), solve(n-1));
    break;

  case 3:
    solution = 1 + min(solve(n/3), solve(n-1));
    break;

  //
  case 1:
  case 5:
  default:
    solution = 1 + solve(n-1);
    break;
  }

  table[n] = solution;

  return solution;
}

int main(int argc, char *argv[]) {

  int n;
  int answer;

  scanf("%d", &n);

  // Init table
  memset(table, 0, sizeof(int) * (MAX_N + 1));

  // NOTE: We will not use table[0]
  table[1] = 0;   // If input is 1, the answer is 0
  table[2] = 1;
  table[3] = 1;

  answer = solve(n);

  printf("%d", answer);

  return 0;
}
