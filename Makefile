all: tckimlik.cpp tckimlik.h kimliksorgu.cpp Makefile
	g++ -c tckimlik.cpp -std=c++14 -DCPPHTTPLIB_OPENSSL_SUPPORT	
	g++  tckimlik.o kimliksorgu.cpp -std=c++14 -DCPPHTTPLIB_OPENSSL_SUPPORT -lssl -lcrypto -o kimliksorgu


clean:
	rm -f  *.o *~ kimliksorgu
