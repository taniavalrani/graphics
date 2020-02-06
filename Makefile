#Makefile for Assignment1 for mac 


build:
	clang++ `fltk-config --use-gl --ldflags` MyGLCanvas.cpp main.cpp Cube.cpp -o a1

clean:
	rm a1 

