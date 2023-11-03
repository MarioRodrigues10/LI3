CFLAGS=-Wall -Iinclude

#exemplo
programa-principal: src/programa-principal.o
	gcc $(LDFLAGS) src/programa-principal.o -o programa-principal

src/programa-principal.o: src/programa-principal.c

clean:
	rm -f programa-principal programa-testes src/*.o
