CC= -std=c++11

main: main.o profile.o
	g++ -o main main.o profile.o $(CC)

main.o: main.cpp profile.h

profile.o: profile.cpp profile.h