main:
	clang -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL ../libraylib.a ./src/main.c ./src/yass.c -o snake 

clean:
	rm snake 
