all: program1 program2

program1: exercise1.cc
	g++ -o program1 exercise1.cc `root-config --cflags` `root-config --libs`

program2: exercise2.cc
	g++ -o program2 exercise2.cc `root-config --cflags` `root-config --libs`

clean:
	rm -rf program1
	rm -rf program2
