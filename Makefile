CC_WEB = emcc
CFLAGS_WEB = -I/home/chase/dev/libs/raylib/include -L/home/chase/dev/libs/raylib/lib -s USE_GLFW=3 -s WASM=1 -s ASYNCIFY -s FORCE_FILESYSTEM=1 -lraylib
OUT_WEB = build/main.html
CC_LINUX = g++
CFLAGS_LINUX = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
OUT_LINUX = main
SRC = src/lib/main.cpp

all:
	$(CC_LINUX) -o $(OUT_LINUX) $(SRC) $(CFLAGS_LINUX)

web:
	$(CC_WEB) $(SRC) -o $(OUT_WEB) $(CFLAGS_WEB)

clean:
	rm -f main build/main.html build/main.js build/main.wasm
