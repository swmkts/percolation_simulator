#include <iostream>
#include <random>
#include <stdlib.h>
#include <time.h>
#include <set>
#include <iomanip>
#include <ios>
#include "percolation.h"

Percolation::Percolation(){
    std::cout << "Input the size of percolation matrix." << std::endl;
}
Percolation::Percolation(int n):
    mt((unsigned)time(NULL))//メンバ初期化子
{
    size = n;
    uf = new UnionFind(size*size);
}

void Percolation::Simulation(double probability){
    percolation_matrix.erase(percolation_matrix.begin(), percolation_matrix.end());
    this->uf->reset();
    //std::cout << "mt: " << mt() << std::endl;
    std::bernoulli_distribution bern(probability);
    for(int i = 0; i < size; ++i){
        std::vector<bool> row;
        for(int j = 0; j < size; ++j){
            row.push_back(bern(mt));
            //std::cout << row[j] << " ";
        }
        percolation_matrix.push_back(row);
        //std::cout << std::endl;
    }
}
void Percolation::DetectConnectedComponents(){
    for(int i = 0; i < size; ++i){
        for(int j = 0; j < size; ++j){
            if(percolation_matrix[i][j]){
                if(i == 0){
                    if(j == 0){
                        continue;
                    }else{
                        if(percolation_matrix[i][j-1]){
                            this->uf->unite(size*i + j, size*i + j - 1);
                        }
                    }
                }else if(j == 0){
                    if(percolation_matrix[i-1][j]){//上と比較
                        this->uf->unite(size*i + j, size*(i-1) + j);
                    }
                }else{
                    if(percolation_matrix[i][j-1]){//左と比較
                            this->uf->unite(size*i + j, size*i + j - 1);
                            if(percolation_matrix[i-1][j]){
                                this->uf->unite(size*i + j, size*(i-1) + j);
                            }
                    }else if(percolation_matrix[i-1][j]){
                        this->uf->unite(size*i + j, size*(i-1) + j);
                        if(percolation_matrix[i][j-1]){
                            this->uf->unite(size*i + j, size*i + j - 1);
                        }
                    }
                }
            }
        }
    }
}
int Percolation::CheckPercolation(){
    int judge = 0;
    std::set<int> per_for;
    std::set<int> per_back;
    for(int i = 0; i < size; ++i){
        per_for.insert(this->uf->find(i));
    }
    for(int i = size*size - 1; i >= size*size - size; --i){
        per_back.insert(this->uf->find(i));
    }
    for(std::set<int>::const_iterator i = per_for.begin(); i!= per_for.end(); ++i){
        if(per_back.count(*i) == 1){
            judge = 1;
        }
    }
    // for(std::set<int>::const_iterator i = per_for.begin(); i != per_for.end(); ++i){
    //     std::cout << *i << " ";
    // }
    // std::cout << std::endl;
    // for(std::set<int>::const_iterator j = per_back.begin(); j != per_back.end(); ++j){
    //     std::cout << *j << " ";
    // }
    // std::cout << std::endl;
    return judge;
}
void Percolation::output_groups(){
    int count = 0;
    for(int i = 0; i < size * size; i++){
        std::cout << std::setw(3) << std::right << this->uf->find(i);
        count++;
        if(count%size == 0){
            std::cout << "\n";
        }
    }
}