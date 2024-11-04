# Define a variable to hold all .cpp files except TestingMain.cpp
CPP_FILES := $(shell find . -name '*.cpp' ! -name 'main.cpp')

run: main
	./main
	make c

main: $(CPP_FILES:.cpp=.o)
	g++ -std=c++11 -fprofile-arcs -ftest-coverage -o main $(CPP_FILES:.cpp=.o)

%.o: %.cpp
	g++ -std=c++11 -fprofile-arcs -ftest-coverage -c -w $< -o $@

debugcpp: debugo
	g++ -std=c++11 -ggdb3 -fprofile-arcs -ftest-coverage -o main $(CPP_FILES:.cpp=.o)

debugo: $(CPP_FILES)
	g++ -std=c++11 -ggdb3 -fprofile-arcs -ftest-coverage -c -w $< -o $@

cov: 
	make main
	./main
	gcov $(CPP_FILES)

doxygenCreate:
	mkdir -p docs
	cd docs/
	doxygen -g

doxygenFiles:
	doxygen ./docs/Doxyfile

v: 
	make debugcpp
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file=valg.txt ./main
	make c

c:
	rm *.o main *.gcda *.gcno *.gcov