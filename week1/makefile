CFLAGS = -Wall -mavx

.PHONY: clean default

default: avx_pi

avx_pi: avx_pi.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm avx_pi
