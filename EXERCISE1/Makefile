main: main_.o classes_.o
	g++ -std=c++11 main_.o classes_.o -o main

classes_.o: classes_.cpp
	g++ -std=c++11 -c classes_.cpp

main_.o: main_.cpp
	g++ -std=c++11 -c main_.cpp

clean:
	rm main_.o classes_.o main
