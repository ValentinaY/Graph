/**
@author Valentina Yate
*/

#ifndef __GRAPH__HXX__
#define __GRAPH__HXX__

#include <map>
#include <queue>
using namespace std;

template<class T >
Graph<T>::Graph()
{
}

template<class T >
Graph<T>::~Graph()
{
}

/*
 *	Se agrega un vértice considerando el tipo de dato que se ingresa por parámetro.
 *	El vértice se agrega a la lista de vértices y además a la matriz que representa el grafo. Se agrega como fila 
 * 	y en sus columnas le suceden un vector vacío.
*/
template<class T >
void Graph<T>::addvertex(T v){
	this->vertex.push_back(v);
	vector< vrt<T> > list;
	list.clear();
	this->edges.insert( pair<T,vector < vrt<T> > >(v, list) );
	printf("El vertice se agrego. \n");
}

/*
 *	Se conectan dos vértices considerando un peso en la arista. 
 *	Se verifica la existencia de los vértices y se procede a la agregación del vértice b en el vector correspondiente 
 *	a su adyacencia (vector correspondiente a la clave a en el map) y viceversa. 
*/
template<class T>
void Graph<T>::connectvertex(T a, T b, int w){
int exists=0;

for(int i=0;i<Graph::vertex.size();i++){
	if(vertex[i]==a || vertex[i]==b){
		exists++;
	}
}

if(exists==2){
	vrt<T> newva, newvb;
	newva.data=a;	newvb.data=b;
	//Para ambos vértices se considera el mismo peso, pues es el peso de la arista.
	newva.weight=w;	newvb.weight=w;
	this->edges[a].push_back(newvb);
	this->edges[b].push_back(newva);	
	printf("Se han conectado los vertices. \n");
}
else{
	printf("Alguno de los vertices no se encuentra.\n");
}
}

/*
 *	Se cuentan los vértices.
 *	Ya que al agregarse los vértices, los mismos se agregan en el vector. Es más eficiente preguntar el tamaño
 *	de este.
*/
template<class TEdge >
long Graph<TEdge>::getnvertex(){
	long n=this->vertex.size();
	return n;
}

/*
 *	Se eliminan los vértices.
 *	Cíclicamente se consulta el vector de adyacencia del vertice a eliminar. Este entregara todos los vértices que en sus
 *	vectores contienen al buscado. Se elimina el vértice de los vectores para después eliminar la pareja en el map.
*/
template<class T >
void Graph<T>::deletevertex( T v){
	
	vector< vrt<T> > temp=this->edges[v];
	int cont=0;
	vrt<T> vertextemp;
	while(cont<temp.size()){
		vertextemp=temp.at(cont);
		vector< vrt<T> > temp2=this->edges[vertextemp.data];
		int j=0;
		for(j=0;j<temp2.size();j++){
			if(v==temp2.at(j).data){
				break;
			}
		}
		//El iterador indica la posición en la que se encuentra el vértice a eliminar.
		this->edges[vertextemp.data].erase(this->edges[vertextemp.data].begin()+j);	
		cont++;
	}

	int i=0;
	for(i=0;i<Graph::vertex.size();i++){
		if(vertex[i]==v){
			break;
		}
	}
	this->vertex.erase( (this->vertex.begin() )+i);

	printf("Se ha eliminado el vertice.\n");	
}

/*
 *	Se elimina la arista, se indica el peso ya que los vértices pueden tener varias aristas entre ellos.
 *	Se busca en el vértice a el vector de adyacencia y se elimina el vertice b que representa la arista.
 *	El mismo paso procede, esta vez se invierten los vértices.
*/
template<class T >
void Graph<T>::deleteedge(T a, T b, int w){

	vector< vrt<T> > temp=this->edges[a];
	
	int j=0;
	for(j=0;j<temp.size();j++){
		if(b==temp.at(j).data && w==temp.at(j).weight){
			break;
		}
	}	
	this->edges[a].erase(this->edges[a].begin()+j);		

	temp=this->edges[b];
	j=0;
	for(j=0;j<temp.size();j++){
		if(a==temp.at(j).data && w==temp.at(j).weight){
			break;
		}
	}	
	this->edges[b].erase(this->edges[b].begin()+j);
	printf("Se ha eliminado la arista.\n");			
}

/*
 *	Se devuelve el número de aristas que relacionan los dos vértices. 
 *	Cuando se encuentra el vértice b en el vector de adyacencia del vector a. Un contador aumenta. 
 *	Se retorna el contador.
*/
template<class T >
int Graph<T>::hasedge(T a, T b){
	int t=0;

	vector< vrt<T> > temp=this->edges[a];
	int i=0;
	for(i=0; i<temp.size(); i++){
		if(temp.at(i).data == b ){
			t++;
		}
	}

	return t;
}

/*
 *	La implementación del algoritmo Dikstra concluye en la obtención del camino más corto considerando el peso de las 
 *	aristas.
 *	Aunque se sigan los pasos del Dikstra, el vertice que precede el camino no se presenta por pantalla. Sin embargo es
 *	considerado dentro del algoritmo.	
*/
template<class T>
void Graph<T>::dikstra(T a, T b){
	//En un map se agregan los vértices que ya se usaron, con el fin de no consumar un ciclo infinito.
	std::map<T, bool> used;
	//En un map se almacena el camino más corto encontrado hasta el momento.
	std::map<T, int > way;
	//En un vector se ubican los vertices adyacentes al vértice que se evalua.
	vector < vrt<T> > temp;

	//Se almacena el dato del vertice actual, para identificar maps.
	T actual=a;
	temp=this->edges[actual];

	bool end=false;
	int cont=0;
	while(!end){
		//El camino actual es el valor que esté en el mapa de caminos según la 'key'.
		int wayactual=way[actual];
		int wayoni;
		//Se recorre el vector de adyacencia, el peso de la arista al vertice es sumado a el camino hasta el vertice actual.
		//Se supone que el vértice actual representa el camino más corto, consecuentemente la suma será el camino más corto hasta el momento.
		//Si otro vertice encuentra un camino más corto, el valor en el mapa será reemplazado.
		for(int i=0; i<temp.size(); i++){
			wayoni=way[temp.at(i).data];
			if( (wayoni > temp.at(i).weight+way[actual]) || (way[temp.at(i).data] == 0) ) {
				way[temp.at(i).data]=temp.at(i).weight+way[actual];
				
			}
		}
		used[actual]=true;
		typename std::map<T, int >::iterator it;
		int i= 0xFFFFF;
		T datatemp;
		for(it= way.begin();	it!=way.end();	++it){
			if(it->second != 0 && it->second<i && !used[it->first]){
				i=it->second;
				datatemp=it->first;
			}
		}
		actual=datatemp;
		temp=this->edges[actual];
		//El programa puede caer en un ciclo infinito si no se encuentra el vértice.
		//Se limita finalizano cuando todos los vértices hayan sido evaluados.
		if(cont== this->vertex.size()+1){
			if ( way[b] == 0)
				printf("No se encuentra el vertice\n");
			
			end=true;
		}
		cont++;
	}
	printf("Camino encontrado con longitud: %d\n", way[b]);
}

/*
 *	El grafo es representado de la forma más cercana a la representación en código.
 *	En la primera columna se imprime la 'key' del map y proceden en la misma fila los vértices adyacentes y sus pesos, los
 *	cuales representan las aristas.
*/
template<class T >
void Graph<T>::draw(std::string filename){
	T datus;
	vector< vrt<T> > temp;
	for(int i=0;i< this->vertex.size();i++){
		//Se almacena la 'key' (el dato del vértice) en una variable para facilitar los accesos.
		datus=this->vertex.at(i);
		//El vector toma los valores del vector de adyacencia según la 'key' actual.
		temp = this->edges[datus];
		cout<<datus;
		cout<<"\t";
		for(int j=0;j<temp.size();j++){
			cout<<temp.at(j).data;
			cout<<" ";
			cout<<temp.at(j).weight;
			cout<<" \t";
		}
		cout<<endl;
	}
}


#endif