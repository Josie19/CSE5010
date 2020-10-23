Test: regularExpr.o
	g++ regularExpr.o -o test
regularExpr.o: regularExpr.cpp
	g++ -c regularExpr.cpp
clean:
	rm -f *.o
	rm -f *.exe
	rm -f answer.txt
