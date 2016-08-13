all: fb

fb: FriendsBook.o Profile.o
	g++ -std=c++11 -ggdb -Wall FriendsBook.o MyADT.o Profile.o -o fb

FriendsBook.o: FriendsBook.cpp MyADT.o Profile.o
	g++ -std=c++11 -ggdb -Wall -c FriendsBook.cpp

MyADT.o: MyADT.cpp MyADT.h
	g++ -std=c++11 -ggdb -Wall -c MyADT.cpp

Profile.o: Profile.h Profile.cpp
	g++ -std=c++11 -ggdb -Wall -c Profile.cpp

clean:
	rm -f fb *.o
