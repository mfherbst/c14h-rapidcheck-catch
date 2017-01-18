# c14h-rapidcheck-catch

Some example code to try out the testing frameworks [rapidcheck](https://github.com/emil-e/rapidcheck)
and [Catch](https://github.com/philsquared/Catch).

The code contains some bugs on purpose. It should be easy to find those using the test
suite in the subfolder ``tests``.

# Howto compile and run
Compile by running (in the root of the repository):
```
./compile.sh
```
Then run the compiled test program (in ``tests/tests``) via
```
./run.sh
```
For the list of option the ``Catch``-based test application accepts, run
```
./run.sh -h
```

## History
This project was originally designed for the c¼h I presented at the
[Heidelberg Chaostreff in March 2016](http://blog.mfhs.eu/2016/03/14/c%c2%bch-testen-mit-rapidcheck-und-catch/).
Some extensions towards numerical testing and numerical comparsion have been added
for my talk at the [Scientific Computing seminar](http://simweb.iwr.uni-heidelberg.de/scs.html) at the IWR in Heidelberg.
