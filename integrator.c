/* YOU MUST MODIFY THIS FILE */
// Read "hw3.h" to learn about the two data types: `Range` and `RangeAnswer`

#include "hw3.h"

double integrate1(Range rng)
{
  
  /* Fill in for Part 1 */
  // calculate the numerical integration of the function func
  // based on the three attributes (`lowerlimit`, `upperlimit`, and `intervals`) of the type `Range`.
  // the return value of function `integrate1` should be the numerical integration (return type is double)
  double step; //the step size to incriment each step
  double integral; //the step-wise integral total
  step = (rng.upperlimit - rng.lowerlimit) / rng.intervals; //how much to step per int
  integral = 0;
  for (int i = 0; i < rng.intervals; i++)
  {
    integral += step * func(rng.lowerlimit + ((i * step)));
  }
  return integral;
}

void integrate2(RangeAnswer * rngans)
{
  /* Fill in for Part 2 */
  // run `integrate1` function
  // take the return value from `integrate1` function 
  // and assign it to attribute `answer` of the type `RangeAnswer`
  rngans->answer = integrate1(rngans->rng);

}
