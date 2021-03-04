#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a -Werror

HEADERS=snowman.hpp
OBJECTS=snowman.o

run: demo
	./$^

demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

run_test: test
	./test

test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test
curl -SL http://releases.llvm.org/9.0.0/clang+llvm-9.0.0-x86_64-linux-gnu-ubuntu-18.04.tar.xz | tar -xJC .
tidy:
	clang-tidy snowman.cpp -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,hicpp-*,performance-*,portability-*,readability-* --warnings-as-errors=-* --

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

Test2.cpp:
	curl https://raw.githubusercontent.com/cpp-exercises/snowman-a/master/TestExample.cpp > Test2.cpp

clean:
	rm -f *.o demo test
	rm -f Test2.cpp
