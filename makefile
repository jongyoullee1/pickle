all: run img

img: img.ppm
	convert img.ppm img.png

run: picmaker
	./a.out

picmaker: picmaker.c
	gcc picmaker.c

clear:
	rm a.out
	rm img.ppm
	rm img.jpg
	rm *~
