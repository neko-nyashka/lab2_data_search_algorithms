FLAGS = -Wall -Werror -Wextra -std=c++20
all: search 

search: search.o flight.o bstree.o rbtree.o hash_table.o
	g++ $(FLAGS) -o search search.o flight.o bstree.o rbtree.o hash_table.o

search.o: search.cpp
	g++ $(FLAGS) -c search.cpp

flight.o: flight.cpp
	g++ $(FLAGS) -c flight.cpp


bstree.o: bstree.cpp
	g++ $(FLAGS) -c bstree.cpp
rbtree.o: rbtree.cpp
	g++ $(FLAGS) -c rbtree.cpp

hash_table.o:
	g++ $(FLAGS) -c hash_table.cpp

clean:
	rm -rf *.o search 

rebuild: clean all