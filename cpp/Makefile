.PHONY: build
build:
	mkdir -p ./build
	CC=/usr/bin/clang CXX=/usr/bin/clang++ cmake -B ./build -S . -G Ninja
	# CC=/usr/bin/gcc CXX=/usr/bin/g++ cmake -B ./build -S . -G Ninja
	ninja -C ./build

clean:
	rm -rf ./build

run: build
	./build/main
	./build/src/datastructures/datastructures
	./build/src/hellofradixsort/radixhell
