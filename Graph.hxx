#ifndef __GRAPH__HXX__
#define __GRAPH__HXX__

#include <map>
using namespace std;

template<class T >
Graph<T>::Graph()
{
}

template<class T >
Graph<T>::~Graph()
{
}

template<class T >
void Graph<T>::addvertex(T v){
	this->vertex.push_back(v);
	vector< vrt<T> > list;
	list.clear();
	this->edges.insert( pair<T,vector < vrt<T> > >(v, list) );
	printf("El vertice se agrego. \n");
}

template<class T>
void Graph<T>::connectvertex(T a, T b, float w){
int exists=0;

for(int i=0;i<Graph::vertex.size();i++){
	if(vertex[i]==a || vertex[i]==b){
		exists++;
	}
}

if(exists==2){
	vrt<T> newva, newvb;
	newva.data=a;	newvb.data=b;
	newva.weight=w;	newvb.weight=w;
	this->edges[a].push_back(newvb);
	this->edges[b].push_back(newva);	
	printf("Se han conectado los vertices. \n");
}
else{
	printf("Alguno de los vertices no se encuentra.\n");
}
}

template<class TEdge >
long Graph<TEdge>::getnvertex(){
	long n=this->vertex.size();
	return n;
}

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

template<class T >
void Graph<T>::deleteedge(T a, T b, float w){

}

template<class T >
int Graph<T>::hasedge(T a, T b){
	bool t=true;
	return t;
}

template<class T >
void Graph<T>::draw(std::string filename){
	T datus;
	vector< vrt<T> > temp;
	for(int i=0;i< this->vertex.size();i++){
		datus=this->vertex.at(i);
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