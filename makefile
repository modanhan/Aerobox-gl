LIBS = -lGL -lGLU -lglut -L/usr/lib64
STD = -std=c++0x

a.out:	main.cpp objfile.cpp
	g++ main.cpp objfile.cpp $(STD) $(LIBS)