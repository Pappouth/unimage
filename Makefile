arbre = arbre
zpixel = zpixel
glib = `pkg-config --cflags --libs glib-2.0`

prog: main.o $(zpixel)/zpixel.o $(zpixel)/pixelTab.o $(arbre)/arbre.o
	gcc -g main.o $(zpixel)/zpixel.o $(zpixel)/pixelTab.o $(arbre)/arbre.o -o main -lm

main.o: main.c $(zpixel)/zpixel.h $(arbre)/arbre.h
	# gcc -c -g main.c -o main.o
	gcc -c -g main.c $(glib) -o main.o

$(zpixel)/zpixel.o: $(zpixel)/zpixel.c $(zpixel)/zpixel.h
	gcc -c -g $(zpixel)/zpixel.c -o $(zpixel)/zpixel.o

$(zpixel)/pixelTab.o: $(zpixel)/pixelTab.c $(zpixel)/pixelTab.h
	gcc -c -g $(zpixel)/pixelTab.c -o $(zpixel)/pixelTab.o

$(arbre)/arbre.o: $(arbre)/arbre.c $(arbre)/arbre.h
	gcc -c -g $(arbre)/arbre.c $(glib) -o $(arbre)/arbre.o


clean:
	rm *o */*o
