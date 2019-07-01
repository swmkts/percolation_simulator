#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <vector>

class UnionFind{
    public:
    int factor_num;
    std::vector<int> parent;
    std::vector<int> rank;//根のインデックス
    UnionFind(){
        factor_num = 0;
    }//default constructor
    UnionFind(int n);//constructor
    void unite(int m, int n);//Unite 2groups which include arguments
    int find(int x);//Return root of the group which include argument
    bool same(int m, int n);//Judge whether two arguments belong to the same group
    void reset();
};

#endif