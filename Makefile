main: src/main.cc
	 g++ src/main.cc -o fetch -lcurl -I /usr/local/Cellar/boost/1.64.0_1/include
# fetch: header.o response.o fetch.o main.o
# 	g++ header.o response.o fetch.o main.o -o fetch -lcurl

# header.o: src/header.cc
# 	g++ -c  src/header.cc
#
# response.o: src/response.cc
# 	g++ -c  src/response.cc
#
# fetch.o: src/fetch.cc
# 	g++ -c  src/fetch.cc
#
# main.o: src/main.cc
# 	g++ -c  src/main.cc

clean:
		rm *.o fetch
