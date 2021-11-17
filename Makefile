CPP=g++ --std=c++11
CFLAGS= -Wall

all : projet

projet : main.o ObjetCompose.o ObjetAtomique.o ObjetAbs.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

ObjetCompose.o : ObjetCompose.cpp ObjetCompose.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAtomique.o : ObjetAtomique.cpp ObjetAtomique.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAbs.o : ObjetAbs.cpp ObjetAbs.hpp
	$(CPP) $(CFLAGS) -c $<



clean :
	rm *.o