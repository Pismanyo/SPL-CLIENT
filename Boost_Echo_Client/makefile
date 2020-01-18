CFLAGS:=-c -Wall -Weffc++ -g -std=c++11 -Iinclude
LDFLAGS:=-lboost_system
CFLAGS += -pthread
LDFLAGS += -pthread
all: SplServer
	g++ -o bin/connectionHandler.o bin/echoClient.o bin/echoClient.o UserCommands.o
	Book.o Books.o Frame.o StompConnectionProtocal.o User.o
	$(LDFLAGS) 

SplServer: bin/connectionHandler.o bin/echoClient.o bin/echoClient.o UserCommands.o Book.o Books.o Frame.o StompConnectionProtocal.o User.o
	
bin/connectionHandler.o: src/connectionHandler.cpp include/connectionHandler.h
	g++ $(CFLAGS)   -o bin/connectionHandler.o src/connectionHandler.cpp

bin/echoClient.o: src/echoClient.cpp 
	g++ $(CFLAGS)   -o bin/echoClient.o src/echoClient.cpp
	
bin/UserCommands.o: src/UserCommands.cpp include/UserCommands.h include/User.h
	g++ $(CFLAGS)   -o bin/UserCommands.o src/UserCommands.cpp 

bin/Book.o: src/Book.cpp Book.h
	g++ $(CFLAGS)  -o bin/Book.o src/Book.cpp 
	
bin/Books.o: src/Books.cpp Books.h Book.h
	g++ $(CFLAGS)   -o bin/Books.o src/Books.cpp 
	
bin/Frame.o: src/Frame.cpp include/Frame.h
	g++ $(CFLAGS) -o bin/Frame.o src/Frame.cpp 
	
bin/StompConnectionProtocal.o: src/StompConnectionProtocal.cpp include/StompConnectionProtocal.h include/User.h
g++ $(CFLAGS)  -o bin/StompConnectionProtocal.o src/StompConnectionProtocal.cpp 	

bin/User.o: src/User.cpp include/User.h include/connectionHandler.h include/Frame.h Books.h
	g++ $(CFLAGS)   -o bin/User.o src/User.cpp 
	
.PHONY: clean
clean:
	rm -f bin/*
