debug:
	cmake --build build

init: clean
	cmake -Bbuild -S. -DCMAKE_BUILD_TYPE=ReleaseWithDebInfo
	ln -s ./build/compile_commands.json ./compile_commands.json

install.debug:
	cmake --install build --prefix ./install

.PHONY: clean all run

all: debug

clean:
	rm -rf build out .cache install compile_commands.json
