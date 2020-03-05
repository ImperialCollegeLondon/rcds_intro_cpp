all: program3 program4 program5

program3: exercise3.cc
	g++ -o program3 exercise3.cc `root-config --cflags` `root-config --libs`

program4: exercise4.cc
	g++ -o program4 exercise4.cc `root-config --cflags` `root-config --libs`

program5: exercise5.cc
	g++ -o program5 exercise5.cc `root-config --cflags` `root-config --libs`

clean:
	rm -rf program3
	rm -rf program4
	rm -rf program5
