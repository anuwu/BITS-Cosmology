
double func (double k)
{
    
}

double integrate (double ll, double ul, int n, ) 
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