CMAKE = cmake
PYTHON = python3
PROG_BIN_NAME = difference-schemes

all: build calc graphics

build:
	$(CMAKE) -DCMAKE_BUILD_TYPE=Release -S./ -B./build
	$(CMAKE) --build ./build --target $(PROG_BIN_NAME)

calc:
	./build/$(PROG_BIN_NAME)

graphics:
	$(PYTHON) script/graphics.py $(wildcard *.csv)
