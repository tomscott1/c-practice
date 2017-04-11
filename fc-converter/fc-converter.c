#include <stdio.h>


float fahr, celcius;
float start, stop, step;

int main() {

  start = 0;
  stop = 300;
  step = 20;

  fahr = start;

  while (fahr <= stop) {
    celcius = (5.0/9.0) * (fahr - 32.0);  // calculate celcius
    printf("Fahr: %3.0f\tCelcius: %3.1f\n", fahr, celcius);  // print current line of table
    fahr = fahr + step;  // increase fahrenheit
  }

  return 0;
}
