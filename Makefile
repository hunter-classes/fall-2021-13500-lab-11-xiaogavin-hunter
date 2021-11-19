CC= -std=c++11

main: main.o profile.o network.o
	g++ -o main main.o profile.o network.o $(CC)

main.o: main.cpp profile.h network.h

profile.o: profile.cpp profile.h

network.o: network.cpp network.h

clean: 
	rm -rf main.o profile.o network.o