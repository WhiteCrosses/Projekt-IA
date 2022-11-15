all:
	g++ -Isrc/include -Lsrc/lib main.cpp screen.cpp entity.cpp health.cpp -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image