#include <stdio.h>
#include <math.h>
#include <string.h>
#include "integrate.h"

int main (int argc, char *argv[])
{
	if (argc > 3)
		return 1 ;
	
	FILE *fp_ang, *fp_lum ;
	
	char ang_path[100] = "Output\\", lum_path[100] = "Output\\" ;
	strcat (ang_path , argv[1]) ;
	strcat (lum_path, argv[2]) ;
	
	fp_ang = fopen (ang_path , "w") ;
	fp_lum = fopen (lum_path , "w") ;
	
	double low = 0, high = 10.0 , h, z;
	int cnt , div = 1000 ;
	h = (high - low)/div ;
	
	double curr_comov , prev_comov ;
	
	fprintf (fp_ang , "%f %f\n", 0.0, 0.0) ;
	fprintf (fp_lum, "%f %f\n", 0.0, 0.0) ;
	
	cnt = 1 ;
	z = h ;
	prev_comov = 0 ;
	for (cnt = 1 ; cnt <= div ; cnt++)
	{
		curr_comov = prev_comov + integrate (z - h , z , 50) ;
		fprintf (fp_ang , "%f %f\n", z, curr_comov/(1+z)) ;
		fprintf (fp_lum, "%f %f\n", z, curr_comov*(1+z)) ;
		
		prev_comov = curr_comov ;
		z += h ;
	}
	
	fclose (fp_ang) ;
	fclose (fp_lum) ;
	
	return 0 ;
}