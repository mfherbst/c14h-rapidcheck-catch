#!/bin/bash

# init submodule if not yet done
git submodule update --init --recursive

# build submodule:
mkdir -p rapidcheck/build || exit 1
( 
	cd rapidcheck/build
	NOPROC="$(< /proc/cpuinfo awk '/^processor/ { id = $3 }; END {print id+1}')"
	cmake -DRC_ENABLE_CATCH=ON -DBUILD_SHARED_LIBS=ON .. && make -j $NOPROC
	[ "$?" != "0" ] && exit 1
)

INNERCC="${CXX:-g++} -Isrc -Irapidcheck/include -Irapidcheck/ext/catch/include -std=c++11"
$INNERCC ./src/factorial.cc -c -o src/factorial.o && \
$INNERCC ./src/Counter.cc -c -o src/Counter.o && \
$INNERCC ./tests/FactorialTests.cc -c -o tests/FactorialTests.o && \
$INNERCC ./tests/CounterTests.cc -c -o tests/CounterTests.o && \
$INNERCC ./tests/VectorTests.cc -c -o tests/VectorTests.o && \
$INNERCC ./tests/main.cc -c -o tests/main.o && \
$INNERCC -L./rapidcheck/build -lrapidcheck   src/factorial.o src/Counter.o tests/FactorialTests.o tests/CounterTests.o tests/VectorTests.o tests/main.o -o tests/tests
