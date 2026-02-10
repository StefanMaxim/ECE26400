// ***
// *** You MUST modify this file
// ***
#include <stdio.h>
#include <stdbool.h>
#include "hw4.h"

// must enclose the function by #ifdef TEST_INTEGRATE and #endif
#ifdef TEST_INTEGRATE
void integrate(Integration* intrg)
{
  double upper = intrg->upperlimit;
  double lower = intrg->lowerlimit;
  int intervals = intrg->intervals;
  funcptr funct = intrg->func;
  double step = (upper - lower) / intervals;

  double integral = 0.0; //the cumulative integral

  for (double i = lower; i < upper; i += step)
  {
    integral += funct(i) * step;
  }
  intrg->answer = integral;
  
}
#endif // TEST_INTEGRATE

// must enclose the function by #ifdef RUN_INTEGRATE and #endif
#ifdef RUN_INTEGRATE
bool  runIntegrate(char * infilename, char * outfilename)
// return true if it can successfully open and read the input 
// and open and write the output
// return false when encountering any problem
{
  Integration intrg;
  // open the input file name for reading
  FILE* fp = fopen(infilename, "r");


  // if fopen fails, return false
  if (fp == NULL)
  {
    return false;
  }



  // read one double from the input file and store it in 
  // intrg's lowerlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false

  if (fscanf(fp,"%lf\n",&intrg.lowerlimit) != 1)
  {
    return false;
  }








  // read one double from the input file and store it in 
  // intrg's upperlimit
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
if (fscanf(fp,"%lf\n",&intrg.upperlimit) != 1)
  {
    return false;
  }










  // read one int from the input file and store it in 
  // intrg's intervals
  // use fscanf
  // check the return value. If the return value is not one
  // close the file and return false
if (fscanf(fp,"%d\n",&intrg.intervals) != 1)
  {
    return false;
  }







  // close the input file
  fclose(fp);







  // open the output file for writing
  // if fopen fails, return false

  FILE* output = fopen(outfilename, "w");
  if (output == NULL)
  {
  return false;
  }






  // create an array of funcptr called funcs with five elements:
  // func1, func2, ..., func5
  funcptr funcs[5] = {func1,func2,func3,func4,func5};



  // go through the elements in funcs 
  // for each element, call integrate for that function
  // write the result (stored in intrg's answer to 
  // the output file. each answer occupies one line (add "\n")
  // use fprintf
  for (int i = 0; i < sizeof(funcs)/sizeof(funcptr); i++)
  {
    intrg.func = funcs[i];
    integrate(&intrg);
    if(fprintf(output,"%lf\n", intrg.answer) < 1)
    {
      fclose(output);
      return false;
    }

  }





  // check the return value of fprintf. 
  // If it is less one one, close the output
  // file and return false







  // after going through all functions in funcs
  // close the output file
  fclose(output);






  // if the function reaches here, return true
  return true;




}
#endif // RUN_INTEGRATE
