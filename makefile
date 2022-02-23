compile:
	g++ -c -Wall -pedantic-errors ItemType.cpp
	g++ -c -Wall -pedantic-errors SortedLinkedList.cpp
	g++ -c -Wall -pedantic-errors main.cpp

link: compile
	g++ -o main ItemType.o SortedLinkedList.o main.o

run: link
	./main input.txt

clean:
	rm -f main ItemType.o SortedLinkedList.o main.o
