LIBS = -lcurl

exec: compile bin/spacenews src/main.o src/httplibapi.o
	echo "Linking..."
	g++ -o bin/spacenews src/main.o src/httplibapi.o $(LIBS)

compile:
	echo "Starting compilation..."

bin/spacenews: src/main.o src/httplibapi.o
	echo "Linking..."
	g++ -o bin/spacenews $^ $(LIBS)

src/main.o: src/main.cpp include/httplibapi.h
	echo "Compiling main.cpp"
	g++ -c src/main.cpp -o src/main.o -I./include -I./src

src/httplibapi.o: src/httplibapi.cc include/httplibapi.h
	echo "Compiling httplibapi.cc"
	g++ -c src/httplibapi.cc -o src/httplibapi.o -I./include -I./src

all: exec

