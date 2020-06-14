#include <stdio.h>
#include <stdlib.h>

int sign (short pos)
{
	if (pos)
		return +1 ;
	else
		return -1;
}

double **rk4 (double (*der1)(double , double , double) , double(*der2)(double, double, double) , double start, double end, double init_func , double init_der, int intervals)
{
	double t = start, x = init_func, v = init_der , dt ;
	double k11, k21, k12, k22, k13, k23, k14, k24 ;
	
	int j ;
	double **sol = (double **) malloc ((intervals + 1) * sizeof(double *)) ;
	
	for (j = 0 ; j <= intervals ; j++)
		sol[j] = (double *) malloc (3 * sizeof(double)) ;
	
	short pos ;
	
	if (end > start)
	{
		pos = 1 ;
		dt = (end - start)/intervals ;
	}
	else
	{
		pos = 0 ;
		dt = (start - end)/intervals ;
	}
		
	
	for (j = 0 ; j <= intervals ; j++)
	{
		//fprintf (fp , "%f %f\n" , t , x) ;
		sol[j][0] = t ;
		sol[j][1] = x ;
		sol[j][2] = v ;
		k11 = dt*der1(x,v,t);
		k21 = dt*der2(x,v,t);
		k12 = dt*der1(x+sign(pos)*0.5*k11,v+sign(pos)*0.5*k21,t+sign(pos)*0.5*dt);
		k22 = dt*der2(x+sign(pos)*0.5*k11,v+sign(pos)*0.5*k21,t+sign(pos)*0.5*dt);
		k13 = dt*der1(x+sign(pos)*0.5*k12,v+sign(pos)*0.5*k22,t+sign(pos)*0.5*dt);
		k23 = dt*der2(x+sign(pos)*0.5*k12,v+sign(pos)*0.5*k22,t+sign(pos)*0.5*dt);
		k14 = dt*der1(x+sign(pos)*k13,v+sign(pos)*k23,t+sign(pos)*dt);
		k24 = dt*der2(x+sign(pos)*k13,v+sign(pos)*k23,t+sign(pos)*dt);
		x += sign(pos)*(k11+2*k12+2*k13+k14)/6;
		v += sign(pos)*(k21+2*k22+2*k23+k24)/6;
		t += sign(pos)*dt;
	}
	
	return sol ;
}