#include "combinatorics.h"

int P(int n, int k) {
  int p = 1;

  for (int i = n; i > n - k; i--) {
    p *= i;
  }

  return p;
}

int C(int n, int k) {
  int p = 1;

  int largerFactor = (k > n - k) ? k : n - k;
  int smallerFactor = (largerFactor == k) ? n - k : k;

  for (int i = n; i > largerFactor; i--) {
    p *= i;
  }
  for (int i = smallerFactor; i > 1; i--) {
    p /= i;
  }

  return p;
}