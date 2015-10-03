#include <immintrin.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#define SEC 1000000000.0

const double pi = 3.1415926535;
double compute_pi(size_t dt)
{
	int i;
	double pi = 0.0;
	double delta = 1.0 / dt;
	register __m256d ymm0, ymm1, ymm2, ymm3, ymm4;                                                                          
	ymm0 = _mm256_set1_pd(1.0);
	ymm1 = _mm256_set1_pd(delta);
	ymm2 = _mm256_set_pd(delta * 3, delta * 2, delta * 1, 0.0);
	ymm4 = _mm256_setzero_pd();

	for (i = 0; i <= dt - 4; i += 4) {
		ymm3 = _mm256_set1_pd(i * delta);
		ymm3 = _mm256_add_pd(ymm3, ymm2);
		ymm3 = _mm256_mul_pd(ymm3, ymm3);
		ymm3 = _mm256_add_pd(ymm0, ymm3);
		ymm3 = _mm256_div_pd(ymm1, ymm3);
		ymm4 = _mm256_add_pd(ymm4, ymm3);
	}
	double tmp[4] __attribute__((aligned(32)));
	_mm256_store_pd(tmp, ymm4);
	pi += tmp[0] + tmp[1] + tmp[2] + tmp[3];

	return pi * 4.0;
}


int main(int argc, char* argv[]){

	int N = atoi(argv[1]);
	struct timespec start,end;
	clock_gettime(CLOCK_MONOTONIC_RAW,&start);	//start time
	double my_pi = compute_pi(N*1024*1024);
	clock_gettime(CLOCK_MONOTONIC_RAW,&end);	//end time
	//printf("pi:%.10lf\nerror: %.10lf\n",my_pi,pi-my_pi);
	//printf("time: %lf second\n\n",(double)((end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/SEC));
	printf("%lf %.10lf\n\n",(double)((end.tv_sec - start.tv_sec)+(end.tv_nsec - start.tv_nsec)/SEC),pi-my_pi);
	return 0;
}
