/* Exercise 1.15 */

#include <stdio.h>

float convert(float fahr);
float fahr, celcius;
float start, stop, step;

int main() {

  start = 0;
  stop = 300;
  step = 20;

  fahr = start;

  while (fahr <= stop) {
    celcius = convert(fahr); 
    printf("Fahr: %3.0f\tCelcius: %3.1f\n", fahr, celcius);  // print current line of table
    fahr = fahr + step;  // increase fahrenheit
  }

  return 0;
}

float convert(float fahr) {
	celcius = (5.0/9.0) * (fahr - 32.0);  // calculate celcius
	return celcius;
}
