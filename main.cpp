#include <iostream>
#include "Graph.h"

using namespace std;
int main(){

	Graph<char> grafo;
	grafo.addvertex('a');
	grafo.addvertex('b');
	grafo.addvertex('c');
	grafo.addvertex('d');
	grafo.addvertex('e');
	grafo.connectvertex('a','b',1);
	grafo.connectvertex('a','c',3);
	grafo.connectvertex('b','d',9);
	grafo.connectvertex('c','d',3);
	grafo.connectvertex('d','e',2);
	grafo.dikstra('a','e');

	printf("Hay %d vertices. \n", grafo.getnvertex() );
	
	grafo.dikstra('a','m');
	return 0;
}