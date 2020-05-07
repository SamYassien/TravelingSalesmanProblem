#include "TSP.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

TSP::~TSP() {
    delete graph;
}

bool TSP::readGraph( const std::string& FileName) {
    std::ifstream in(FileName);
    if (!in) {
        return 0;
    }
    int temp;
    in >> temp ;
    size = temp;
    graph = new Graph(size);
    for ( int i = 0 ; i < size*size ; i ++ ){
            in >> temp;
            graph->matrix[i] = temp ;
    }
    in.close();
    return 1;
}

int TSP::bruteForce(int s, std::vector<int>& minPath) {
        int source = s;
        std::vector <int> vertices;
        for (int i = 0; i < size; i++)
            if (i != source)
                vertices.push_back(i);

        int path = INT_MAX;
        std::vector<int> tempPath;
        do {
            int cost = 0;
            int current = source;
            for (int i = 0 ; i < vertices.size() ; i++) {
                tempPath.push_back(current);
                cost += graph->matrix[graph->index( current, vertices[i] )];
                current = vertices[i];
            }
            tempPath.push_back(current);
            cost += graph->matrix[graph->index(current, source)];
            if ( cost < path ){
                path = cost;
                minPath = tempPath;
            }

            tempPath.clear();
        } while (std::next_permutation(vertices.begin(), vertices.end()));

        minPath.push_back(source);
        return path;
}

int TSP::DP(int s) {
    std::vector<std::vector<int>> dp(size);
    for(auto& i : dp)
        i = std::vector<int>((1 << size) - 1, INT_MAX);

    return DP(s, 1, dp);
}

int TSP::DP(int ind, int visited, std::vector<std::vector<int>> & dp) {
    if(visited == ((1 << size) - 1))
        return graph->matrix[graph->index( ind, 0)];

    if(dp[ind][visited] != INT_MAX)
        return dp[ind][visited];

    for(int i = 0; i < size ; i++) {
        if (!(visited & (1 << i))) {

            int dist = graph->matrix[graph->index(ind, i)] + DP(i, visited | (1 << i), dp);

            dp[ind][visited] = std::min(dp[ind][visited], dist);
        }
    }
    return dp[ind][visited];
}

void TSP::print() {
    graph->print();
}
