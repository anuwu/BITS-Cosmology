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
    double res = 0, curr = ll ; 
    for (int i = 0; i <= n; i++) 
	{ 
        if (i == 0 || i == n) 
            res += func(curr) ; 
        else if (i % 2 != 0) 
            res += 4*func(curr) ; 
        else
            res += 2*func(curr) ; 
		
		curr += h ;
    } 
    res *= (h/3) ;
    return res; 
} 

/*
Question - Is it better to sum first and then multiply by h/3
or multiply by h/3 at each step and then sum?
*/