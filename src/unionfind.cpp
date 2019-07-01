#include <iostream>
#include "unionfind.h"
using namespace std;

UnionFind::UnionFind(int n){
    factor_num = n;
    for (int i = 0; i < factor_num; ++i){//initialize rank sequence.
        parent.push_back(i);//自身のインデックスを根とする
        rank.push_back(1);
    }
}//constructor
void UnionFind::unite(int m, int n){//Unite 2groups which include arguments
    int m_rt = find(m);//根の値を格納しておく
    int n_rt = find(n);
    if(rank[m_rt] > rank[n_rt]){//rankの大小関係で貼る方向を決める
        parent[n_rt] = m_rt;
        
    }else{
        parent[m_rt] = n_rt;
        if(rank[m_rt] == rank[n_rt]){
            rank[n_rt]++;
        }
    }
}

int UnionFind::find(int x){//Return root of the group which include argument
    if(x == parent[x]){
        return(x);
    }else{
        parent[x] = find(parent[x]);//経路縮約
        return(parent[x]);
    }
}
bool UnionFind::same(int m, int n){//Judge whether two arguments belong to the same group
    return(find(m) == find(n));
}
void UnionFind::reset(){
    for(int i = 0; i < factor_num; ++i){
        this->parent[i] = i;
    }
}