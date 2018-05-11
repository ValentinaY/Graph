/**
@author Valentina Yate
*/
#ifndef __GRAPH__H__
#define __GRAPH__H__

#include <map>
#include <vector>

template < class T>
struct vrt{
	T data;
	int weight;
};


template < class T>
class Graph
{
public: 
    typedef std::map<T, std::vector< vrt<T> > > TMatrix; 
public:
	Graph();
	~Graph();

	void addvertex(T v);
	void connectvertex(T a, T b, int w);
	long getnvertex();
	void deletevertex( T v);
	void deleteedge(T a, T b, int w);
	int hasedge(T a, T b);
	void draw(std::string filename);
	void dikstra(T a, T b);

protected:
	std::vector<T> vertex;
	TMatrix edges;
};

#include "Graph.hxx"

#endif