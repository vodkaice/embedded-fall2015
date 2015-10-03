#!/bin/bash

size="1 2 4 8 16 32 64 128 256 512 1024"
rm -f result.txt
for N in $size
do 
	#c=$(( $N * 2 ))
	#echo "N = $N"
	./avx_pi $N >> result.txt
done	

