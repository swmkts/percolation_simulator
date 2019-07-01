#ifndef PERCOLATION_H
#define PERCOLATION_H

#include <vector>
#include "unionfind.h"

class UnionFind;

class Percolation{
    int size;
    std::vector<std::vector<bool> > percolation_matrix;
    UnionFind* uf;
    public:
    std::random_device rd;
    std::mt19937 mt;
    
    Percolation();
    Percolation(int n);
    ~Percolation(){
        std::cout << "オブジェクトが破棄されました" << std::endl;
        delete uf;
    };
    void Simulation(double probability);
    void DetectConnectedComponents();
    int CheckPercolation();
    UnionFind* get_uf(){
        return(uf);
    }
    void output_groups();
};

#endif