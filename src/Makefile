# Makefile
# Author: Yuri David Santos - Aleva
# Since: 12/6/2011
# Version: 0.1

# Build the AGL library
release: imagefont.cpp
	g++ -fPIC -O3 -c imagefont.cpp
	g++ -shared -O3 -o ../lib/libagl-text.so imagefont.o -lSDL -lagl

# Build the AGL library for debugging
debug: imagefont.cpp
	g++ -fPIC -g -c imagefont.cpp
	g++ -shared -g -o ../lib/libagl-text.so imagefont.o -lSDL -lagl

# Build the test application
test: test.cpp
	g++ -g -o test test.cpp ../lib/libagl-text.so -lagl -lagl-graphics

# Install the AGL library (debug) on the system
install_debug:
	../install_debug.sh

# Install the AGL library on the system
install:
	../install.sh

# Uninstall the AGL library to the system
remove:
	../remove.sh

# Generates the AGL documentation
doc:
	doxygen doxyfile

# Cleans the directories, removing executables and objects
clean:
	rm *.o test ../lib/*.so
