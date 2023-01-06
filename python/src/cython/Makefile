.PHONY: build

clean:
	rm -rf ./build
	rm -rf ./__pycache__
	rm -rf *.c
	rm -rf *.html
	rm -rf *.so

setup:
	python -m venv .
	echo "now active venv and run make install-deps"

install-deps:
	pip install cython numpy

build:
	python setup.py build_ext --inplace

test: build
	clear
	python main.py