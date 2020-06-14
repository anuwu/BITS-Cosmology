#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "rk.h"

#define wcdm -1
#define om_0 0.3
#define w0 -1.1
#define wa 0.1


double der1(double d , double v , double N) 
{
	return v ;
}

double lambda_cdm_der2 (double d, double v, double N)
{
	double omega_m = om_0 * exp(-3*N);
	return ((-1.0/2)*(1+ 3*wcdm*omega_m-3*wcdm)*v + (3.0/2)*omega_m*d) ;
}
	
double w_sev_cpl (double N , double w_not, double w_aye)
{
	return (w_not + w_aye *exp(7*N)*pow((exp(-N)-1),7)) ;
}

double sev_cpl_der2(double d, double v , double N) 
{
	double omega_m = om_0 * exp(-3*N) ;
	return ((-1.0/2)*(1+3*w_sev_cpl(N, w0, wa)*(omega_m-1))*v + (3.0/2)*omega_m*d) ;
}

int main (int argc, char *argv[])
{
	//printf ("%d" , argc) ;
	if (argc != 9)
	{
		printf ("Please enter command line variables correctly!\n") ;
		return 1 ;
	}
	
	char path_lambda[100] = "Output\\" ;
	char path_sev[100] = "Output\\" ;
	char path_divide[100] = "Output\\" ;
	
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
		
	FILE *fp_lambda, *fp_sev, *fp_divide  ;
	
	strcat (path_lambda , argv[6]) ;
	fp_lambda = fopen (path_lambda , "w") ;
	
	strcat (path_sev , argv[7]) ;
	fp_sev = fopen (path_sev , "w") ;
	
	strcat (path_divide , argv[8]) ;
	fp_divide = fopen (path_divide , "w") ;
	
	for (j = 0 ; j <= intervals ; j++)
	{
		fprintf (fp_lambda , "%f %f\n", sol_lambda_cdm[j][0], sol_lambda_cdm[j][1]) ;
		fprintf (fp_sev, "%f %f\n", sol_sev_cpl[j][0], sol_sev_cpl[j][1]) ;
		
		fprintf (fp_divide ,"%f %f\n" , exp(-sol_sev_cpl[j][0])-1 , sol_sev_cpl[j][1]/sol_lambda_cdm[j][1]) ;
	}
	
	
	fclose (fp_lambda) ;
	fclose (fp_sev) ;
	fclose (fp_divide) ;
	
	return 0 ;
}
