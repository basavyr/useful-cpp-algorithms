CC=g++-13

CXX_FLAGS := -std=c++14 -Wall -g

LDFLAGS := -ld_classic

target = main

$(target): $(target).cxx
	$(CC) $(CXX_FLAGS) -o $(target) $(target).cxx $(LDFLAGS)

clean:
	rm main
	rm -rf build/
