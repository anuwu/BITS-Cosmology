extern double **rk4 (double (*der1)(double , double , double) , double(*der2)(double, double, double) , double start, double end, double init_func , double init_der, int intervals) ;