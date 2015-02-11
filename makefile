LIBS = -lGL -lGLU -lglut -L/usr/lib64
STD = -std=c++0x

a.out:	main.cpp 
	g++ main.cpp $(STD) $(LIBS)
