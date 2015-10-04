#!/bin/bash

size="1 2 4 8 16 32 64 128 256 512 1024"
rm -f result_a.txt result_b.txt
rm -f result_time.png result_error.png
for N in $size
do 
	#c=$(( $N * 2 ))
	#echo "N = $N"
	./avx_pi $N >> result_a.txt
done	

for N in $size
do 
	./baseline $N >> result_b.txt
done	
gnuplot -e "load './plot.txt'"
