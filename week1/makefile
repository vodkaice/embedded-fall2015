CFLAGS = -Wall -mavx

.PHONY: clean default

default: avx_pi baseline

avx_pi: avx_pi.c
	gcc $(CFLAGS) $< -o $@
	
baseline:baseline.c
	gcc $(CFLAGS) $< -o $@
	
clean:
	rm avx_pi baseline
