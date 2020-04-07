#include <stdio.h>
#include <math.h>
#include "hubble.h"

int main ()
{
	double H0 = 73.8 ;
	double om_m0 = 0.5 ;
	double om_r0 = 6 * pow(10 , -5) ;
	double w0 = -3.0 ;
	double wa = -1.0 ;

	printf ("This is = %f" , hub(1.0)) ;
	return 0 ;
}

/* For google graphing -

Term 1 - 
0.5 * (1+z)^3

Term 2 -
6*10^-5 * (1+z)^4

Term 3 - 
(1 - 0.5 - 6*10^-5) * exp(3*(-3+-1+1)*ln(z+1) - (-1)*z*(1089*z^6 + 4683*z^5 + 96939*z^4 + 11165*z^3 + 7490*z^2 + 2730*z + 420)/(140 * (z+1)^7))

Return - 
73.8 * sqrt (Term1 + Term2 + Term3) 
73.8 * sqrt (0.5 * (1+z)^3 + 6*10^-5 * (1+z)^4 + (1 - 0.5 - 6*10^-5) * exp(3*(-3+-1+1)*ln(z+1) - (-1)*z*(1089*z^6 + 4683*z^5 + 96939*z^4 + 11165*z^3 + 7490*z^2 + 2730*z + 420)/(140 * (z+1)^7)))
*/