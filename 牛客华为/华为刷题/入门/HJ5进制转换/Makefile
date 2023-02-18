all: main.o
	g++ -o a.out  main.o
main.o:
	clang-format -style=google -i main.cpp
	g++ -c main.cpp
.PHONY:clean
clean:
	rm ./*.o
