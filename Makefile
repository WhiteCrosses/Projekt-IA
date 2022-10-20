all:
	g++ -Isrc/include -Lsrc/lib -o Main main.cpp screen.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image