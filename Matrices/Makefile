all: example arith_mean median mode

example: example.cc
	g++ -I/usr/include/eigen3 -o example example.cc

arith_mean: arith_mean.cc utils.o
	g++ -I/usr/include/eigen3 -o arith_mean arith_mean.cc utils.o

median: median.cc utils.o
	g++ -I/usr/include/eigen3 -o median median.cc utils.o

mode: mode.cc utils.o
	g++ -I/usr/include/eigen3 -o mode mode.cc utils.o

utils.o: utils.cc utils.hpp
	g++ -c utils.cc