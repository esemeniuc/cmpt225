all: fb

fb: FriendsBook.o Profile.o
	g++ -Wall -o fb FriendsBook.o Profile.o

FriendsBook.o: FriendsBook.cpp Profile.h
	g++ -Wall -c FriendsBook.cpp

Profile.o: Profile.h Profile.cpp
	g++ -Wall -c Profile.cpp

clean:
	rm -f fb *.o