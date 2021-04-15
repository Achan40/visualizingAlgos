all: compile link

compile:
	g++ -I src/include -c main.cpp -D_WIN32_WINNT=0x0501
link:
	g++ main.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system