//Lambda CDM H(z)

#include <stdio.h>
#include <math.h>

#define H0 73.8 
#define om_m0 0.3




double hub (double z)
{
	return H0 *sqrt(om_m0*pow((1+z),3)+(1-om_m0));
}