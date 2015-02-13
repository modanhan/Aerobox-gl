LIBS = -lGL -lGLU -lglut -L/usr/lib64
STD = -std=c++0x

a.out:	*.cpp *.h
	g++ *.cpp $(STD) $(LIBS)
