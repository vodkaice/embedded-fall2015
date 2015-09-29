#include <stdio.h>

double compute_pi(size_t dt){
	size_t i;
	double pi =0.0;
	double delta = 1.0 / dt;
	for(i = 0; i < dt; i++){
		double x = (double) i / dt;
		pi += delta / (1.0+x*x);
	}
	return pi*4.0;
}

int main(){
	printf("%f\n",compute_pi(128*1000000));
}
