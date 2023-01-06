.PHONY: build

clean:
	rm -rf ./*.so
	rm -rf ./*.o

build:
	clang++ -c -fPIC -O3 -march=native fib.cpp quicksort.cpp
	clang++ -shared -O3 -march=native -o libquick.so fib.o quicksort.o

test: build
	python main.py