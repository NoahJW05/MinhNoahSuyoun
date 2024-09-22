all:
	g++ -Isrc/Include -Lsrc/lib -Iheaders src/*.cpp -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image