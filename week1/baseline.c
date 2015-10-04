#include <stdio.h>
#include <time.h>
#define SEC 1000000000.0
const double pi = 3.1415926535;
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

int main(int argc, char* argv[]){
	int N = atoi(argv[1]);
	struct timespec start,end;
	clock_gettime(CLOCK_MONOTONIC_RAW,&start);	//start time
	double my_pi = compute_pi(N*1024*1024);
	clock_gettime(CLOCK_MONOTONIC_RAW,&end);	//end time
	printf("%lf %.10lf\n",(double)((end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/SEC),pi-my_pi);
	return 0;
}
