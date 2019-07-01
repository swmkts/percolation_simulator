#include <iostream>
#include <random>
#include "unionfind.h"
#include "percolation.h"
#include <fstream>

int main(void){
    int size = 10;
    Percolation percolation(size);
    double probability = 0.1;
    int number_of_iterations = 100;
    int percolation_count = 0;
    //Try Simyulation
    for(int i = 0; i < number_of_iterations; ++i){
        percolation.Simulation(probability);
        percolation.DetectConnectedComponents();
        percolation.CheckPercolation();
        percolation_count += percolation.CheckPercolation();
        percolation.output_groups();
    }
    //percolation.output_groups();
    //Prob-Perc_Prob Simulation
    std::cout << "パーコレーション有無: " << percolation_count << std::endl; 
    std::cout << probability << " :　" << (double)percolation_count / number_of_iterations << std::endl;
    std::ofstream ost("./percolation_0.5_1000.txt");
    if(!ost){
        std::cerr << "Cannot open percolation.txt" << std::endl;
        exit(1);
    }
    int n = 1000;
    for(int i = 0; i < 100; ++i){
        double prob = i * 0.01;
        Percolation percolation(n);
        int perc_count = 0;
        for(int i = 0; i < number_of_iterations; ++i){
            percolation.Simulation(prob);
            percolation.DetectConnectedComponents();
            percolation.CheckPercolation();
            perc_count += percolation.CheckPercolation();
        }
        //percolation.output_groups();
        ost << prob << ", " << (double) perc_count / number_of_iterations << std::endl;
    }
    ost.close();
    //Size-Perc_Prob Simulation
    std::ofstream ost1("./percolation_size_0.1.txt");
    if(!ost1){
        std::cerr << "Cannot open percolation_size.txt" << std::endl;
        exit(1);
    }
    for(int i = 1; i <= 100; ++i){
        int sz = i;
        Percolation perc(sz);
        int perc_count = 0;
        for(int i = 0; i < number_of_iterations; ++i){
            perc.Simulation(probability);
            perc.DetectConnectedComponents();
            perc.CheckPercolation();
            perc_count += perc.CheckPercolation();
        }
        std::cout << "\r" << "Now " << (i / 100) * 100 << "% Done." << "\n";
        ost1 << sz << ", " << (double)perc_count / number_of_iterations << std::endl;
    }
    std::cout << "\n";
    ost1.close();
    
    return 0;
}