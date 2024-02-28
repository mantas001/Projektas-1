main: functions.o
	g++ -o vector_main vector_main.cpp functions.o
funkctions:
	g++ -c functions.cpp
clean:
	del *.o vector_main.exe