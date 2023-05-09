# compiler
GCC= g++
CLANG=clang

# compiler flags
Flags= -std=c++14 -O2

Link= -lsfml-graphics -lsfml-window -lsfml-system -lstdc++

Src_Dir=./src/
Exec_Dir=./bin/

g++: main Fruit Snake Background
	$(GCC) -o Snake-Game $(Flags) \
	$(Exec_Dir)main.o \
	$(Exec_Dir)Background.o \
	$(Exec_Dir)Fruit.o \
	$(Exec_Dir)Snake.o \
	$(Link)

# generate main.o obj file
main: $(Src_Dir)main.cpp
	$(GCC) -c $(Src_Dir)main.cpp -o $(Exec_Dir)main.o

# generate Background.o obj file
Background: $(Src_Dir)Background.cpp
	$(GCC) -c $(Src_Dir)Background.cpp -o $(Exec_Dir)Background.o

# generate Fruit.o obj file
Fruit: $(Src_Dir)Fruit.cpp
	$(GCC) -c $(Src_Dir)Fruit.cpp -o $(Exec_Dir)Fruit.o

# generate Snake.o obj file
Snake: $(Src_Dir)Snake.cpp
	$(GCC) -c $(Src_Dir)Snake.cpp -o $(Exec_Dir)Snake.o

run: 
	./Snake-Game

# remove all the object file and executables generated
clean:
	@rm -rf Snake-Game
	@rm -rf $(Exec_Dir)*.o