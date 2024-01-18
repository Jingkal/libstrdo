debug:
	cmake --build build/debug

init: clean
	cmake -Bbuild/debug -S. -DCMAKE_BUILD_TYPE=Debug

release:
	cmake --build build/release

init.release: 
	cmake -Bbuild/release -S. -DCMAKE_BUILD_TYPE=Release

.PHONY: clean all run

all: debug release


clean:
	rm -rf build out .cache install
