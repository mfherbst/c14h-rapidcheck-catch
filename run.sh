#!/bin/sh
export LD_LIBRARY_PATH="rapidcheck/build"
tests/tests "$@"
