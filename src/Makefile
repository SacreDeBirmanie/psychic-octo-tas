# options de compilation
CFLAGS = -g -std=c++11 -pedantic -Wfatal-errors -Wconversion -Wredundant-decls -Wshadow -Wall -Wextra
# liste des fichiers implémentant une Table Associative
TA = mappe.hpp mappe.tpp
# liste des fichiers implémentant une File de Priorité
FP = filedePrioriteAVL.hpp filedePrioriteAVL.tpp filedePriorite.hpp filedePriorite.tpp

all : chariot_test.exe FP_test.exe

%.o : %.cpp %.hpp
	g++ $(CFLAGS) -c -o $@ $< 

FP_test.exe : FP_test.cpp $(FP)
	g++ $(CFLAGS) FP_test.cpp -o FP_test.exe

chariot_test.exe : chariot_test.cpp chariot.hpp chariot.tpp $(TA) $(FP) magasin.o produit.o
	g++ $(CFLAGS) chariot_test.cpp produit.o magasin.o -o chariot_test.exe

clean :
	@rm *.o *.exe

.PHONY: all clean
