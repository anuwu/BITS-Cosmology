//7 CPL H(z)

#include <stdio.h>
#include <math.h>

#define H0 73.8 
#define om_m0 0.5 
#define om_r0 0.00006 
#define w0 -3.0 
#define wa -1.0 


double hub (double z)
{
	return H0 *sqrt(
	om_m0*pow((1+z),3)
	+
	om_r0*pow((1+z),4)
	+
	(1 - om_m0 - om_r0)*exp(3*(w0+wa+1)*log(z+1) - wa*z*(1089*pow(z,6) + 4683*pow(z,5) + 96939*pow(z,4) + 11165*pow(z,3) + 7490*pow(z,2) + 2730*z + 420)/(140 * pow((z+1),7)))
	) ;
}