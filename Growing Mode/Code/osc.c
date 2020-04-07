#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rk.h"

#define gamma 0
#define omega_sq 10

double f1(double x , double v , double t) 
{
	return v ;
}

double f2(double x, double v , double t) 
{
	return (-gamma * v - omega_sq * x) ;
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
	double **sol ;
	double start, end, init_func, init_der, intervals ;
	start = atof(argv[1]) ;
	end = atof(argv[2]) ;
	init_func = atof(argv[3]) ;
	init_der = atof(argv[4]) ;
	intervals = atof(argv[5]) ;
	
	sol = rk4 (f1, f2, start, end, init_func, init_der, intervals) ;
	
	FILE *fp ;
	strcat (h_path , argv[6]) ;
	fp = fopen (h_path , "w") ;
	
	for (j = 0 ; j <= intervals ; j++)
		fprintf (fp , "%f %f\n", sol[j][0], sol[j][1]) ;
	
	fclose (fp) ;
	
	return 0 ;
}
