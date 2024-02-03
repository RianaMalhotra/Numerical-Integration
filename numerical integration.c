#include <math.h>
#include <stdio.h>

double func(double x) { return exp(-x * x); }

int main() {
  int n;
  double a, b;

  while (1) {
    printf("Please enter the number of rectangles (n): ");
    scanf("%d", &n);

    if (n < 1) {
      printf("Exiting.\n");
      break;
    }

    while (1) {
      printf("Please enter the interval of integration (a b): ");
      scanf("%lf %lf", &a, &b);

      if (a < b) {
        break;
      } else {
        printf("Invalid interval! \n");
      }
    }
    double width = (b - a) / n;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
      double x_midpoint = a + (i + 0.5) * width;
      double height = func(x_midpoint);
      double area = width * height;
      sum += area;
    }

    printf("The integral of e^-x^2 on [%.5f, %.5f] with n = %d is: %.5f\n", a,
           b, n, sum);
  }

  return 0;
}
