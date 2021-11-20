all: compile link run
compile:
	g++ -I "./include" -c ./src/Node.cpp -o ./lib/Node.o
	g++ -I "./include" -c ./src/DoublyLinkedList.cpp -o ./lib/DoublyLinkedList.o
	g++ -I "./include" -c ./src/main.cpp -o ./lib/main.o
link:
	g++ -o ./bin/program ./lib/DoublyLinkedList.o ./lib/Node.o  ./lib/main.o
run:
	./bin/program