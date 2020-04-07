#include <stdio.h>
#include <math.h>
#include <string.h>
#include "hubble.h"

int main (int argc, char *argv[])
{
	if (argc > 2)
		return 1 ;
	
	FILE *fp ;
	char h_path[100] = "Output\\" ;
	strcat (h_path , argv[1]) ;
	
	fp = fopen (h_path , "w") ;
	
	double low = 0, high = 10.0 , h, z;
	int cnt , div = 1000 ;
	h = (high - low)/div ;
		
	z = 0 ;
	for (cnt = 0 ; cnt <= div ; cnt++)
	{
		fprintf (fp , "%f %f\n", z, hub(z)) ;
		z += h ;
	}
	
	fclose (fp) ;
	
	return 0 ;
}