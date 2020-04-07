#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "rk.h"

#define om_0 0.3
#define w0 1.1
#define wa 0.1


double der1(double d , double v , double z) 
{
	return v ;
}

double lambda_cdm_der2 (double d, double v, double z)
{
	double omega_m = om_0 * pow((1+z),3) ;
	return (-1.0/(2*(1+z))*(1-3*(1-omega_m))*v + (3.0/(2*(pow(1+z,2))))*omega_m*d) ;
}
	
double w_sev_cpl (double z , double w_not, double w_aye)
{
	return (w_not + w_aye * pow(z/(1+z) , 7)) ;
}

double sev_cpl_der2(double d, double v , double z) 
{
	double omega_m = om_0 * pow((1+z),3) ;
	return (-1.0/(2*(1+z))*(1+3*w_sev_cpl(z, w0, wa)*(1-omega_m))*v + (3.0/(2*(pow(1+z,2))))*omega_m*d) ;
}

int main (int argc, char *argv[])
{
	//printf ("%d" , argc) ;
	if (argc != 7)
	{
		printf ("Please enter command line variables correctly!\n") ;
		return 1 ;
	}
	
	char h_path[100] = "Output\\" ;
	
	int j ;
	double **sol_lambda_cdm, **sol_sev_cpl ;
	double start, end, init_func, init_der, intervals ;
	start = atof(argv[1]) ;
	end = atof(argv[2]) ;
	init_func = atof(argv[3]) ;
	init_der = atof(argv[4]) ;
	intervals = atof(argv[5]) ;
	
	sol_sev_cpl = rk4 (der1, sev_cpl_der2, start, end, init_func, init_der, intervals) ;
	sol_lambda_cdm = rk4 (der1, lambda_cdm_der2, start, end, init_func, init_der, intervals) ;
	
	FILE *fp ;
	strcat (h_path , argv[6]) ;
	fp = fopen (h_path , "w") ;
	
	for (j = 0 ; j <= intervals ; j++)
		fprintf (fp , "%f %f\n", sol_lambda_cdm[j][0], sol_lambda_cdm[j][1]) ;
	
	fclose (fp) ;
	
	return 0 ;
}
