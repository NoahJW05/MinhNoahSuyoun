all:
	g++ -Isrc/Include -Lsrc/lib -Iheaders main.cpp Game.cpp  -o main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image