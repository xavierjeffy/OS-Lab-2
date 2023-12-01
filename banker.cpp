#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream banker("banker.txt");
    int p = 5;             //number of processes
    int r = 3;             //number of resources
    int alloc[p][r];       //allocation matrix
    int max[p][r];         //max matrix
    int avail[r];          //available resources

    for(int i = 0; i < p; ++i){
        for(int j = 0; j < r; ++j){
            banker >> alloc[i][j];
        }
        for(int j = 0; j < r; ++j){
            banker >> max[i][j];
        }
        if(i == 0){
            for(int j = 0; j < r; ++j){
                banker >> avail[j];
            }
        }
    }
}
