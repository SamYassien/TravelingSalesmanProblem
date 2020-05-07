//
// Created by eslam on 5/6/2020.
//

#ifndef TRAVELINGSALESMAN_TSP_H
#define TRAVELINGSALESMAN_TSP_H

#include <iostream>
#include <string>
#include <vector>

struct Graph{
    int* matrix;
    int n;
    Graph(int n){
        this->n = n ;
        matrix = new int [n*n] ;
    }
    ~Graph(){
        delete [] matrix;
    }
    int index ( int x, int y ) const {
        return (x + n * y);
    }
    int getSize() const {
        return n;
    }
    void print(){
        for (int i = 0; i < n*n ; ++i) {
            if ( i % n == 0 )
                std::cout << std::endl ;

            std::cout << matrix[i] << " " ;
        }
        std::cout << std::endl;
    }
};

class TSP {
private:
    Graph* graph;
    int size;
public:
    TSP(){}
    ~TSP();
    bool readGraph( const std::string& );
    int bruteForce(int, std::vector<int>&);
    int DP(int);
    int DP( int, int ,  std::vector<std::vector<int>>& );
    void print();
};


#endif //TRAVELINGSALESMAN_TSP_H
