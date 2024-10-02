#ifndef EXTERN_UTILS_H
#define EXTERN_UTILS_H

inline int find_largest (int x[], int n) {
  int max = x[0];
  for (int i = 1; i < n; i++) {
    if (x[i] > max) {
      max = x[i];
    }
  }

  return max;
}

int convert_double (double num);

float convert_long (long num);

int (*f(float (*)(long), char *))(double);

#endif
