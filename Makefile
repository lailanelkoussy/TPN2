CPP=g++ --std=c++11
CFLAGS= -Wall -MD

all : projet

OBJS =  main.o ObjetCompose.o ObjetAbst.o ObjetAtomique.o

projet : main.o ObjetCompose.o ObjetAbst.o ObjetAtomique.o
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $<

ObjetAbst.o : ObjetAbst.cpp ObjetAbst.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAtomique.o : ObjetAtomique.cpp ObjetAtomique.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetCompose.o : ObjetCompose.cpp ObjetCompose.hpp
	$(CPP) $(CFLAGS) -c $<

ObjetAtomique.o : ObjetAtomique.cpp ObjetAtomique.hpp
	$(CPP) $(CFLAGS) -c $<

clean :
	rm *.o
	rm -f *.d

test: all
	./projet

-include $(OBJS:.o=.d)