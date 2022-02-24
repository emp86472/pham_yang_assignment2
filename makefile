compile:
	g++ -c -Wall -pedantic-errors ItemType.cpp
	g++ -c -Wall -pedantic-errors SortedLinkedList.cpp
	g++ -c -Wall -pedantic-errors main.cpp
	g++ -c -Wall -pedantic-errors ListNode.cpp

link: compile
	g++ -o main ItemType.o SortedLinkedList.o main.o ListNode.o

run: link
	./main input.txt

clean:
	rm -f main ItemType.o SortedLinkedList.o main.o ListNode.o
