#include <stdio.h>
#include <math.h>
#include "hubble.h"

#define c 300000000

double func(double z)
{
	return c/hub(z) ;
}

double integrate (double ll, double ul, int n) 
{ 
    // Calculating the value of h 
    double h = (ul - ll) / n; 
  
    // Calculating result 
    double res = func(ll) + func(ul), curr ;
	curr = ll + h ;
    for (int i = 1; i < n; i++) 
	{ 
        if (i % 3 == 0) 
            res += 2*func(curr) ;
        else
			res += 3*func(curr) ;
		
		curr += h ;
    } 
    res *= (3*h/8) ; 
    return res; 
} 

/*
Question - Is it better to sum first and then multiply by h/3
or multiply by h/3 at each step and then sum?
*/