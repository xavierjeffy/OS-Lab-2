#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream banker("banker.txt");
    int p = 5;             //Number of processes
    int r = 3;             //Number of resources
    int alloc[p][r];       //Allocation matrix
    int max[p][r];         //Max matrix
    int avail[r];          //Available resources
    int need[p][r];        //Needed resources

    for(int i = 0; i < p; i++){            //Filling in the allocation matrix
        for(int j = 0; j < r; j++){
            banker >> alloc[i][j];
        }
        for(int j = 0; j < r; j++){        //Filling in the max matrix
            banker >> max[i][j];
        }
        if(i == 0){                        
            for(int j = 0; j < r; j++){    //Filling in the available processes
                banker >> avail[j];
            }
        }
        for(int j = 0; j < r; j++){        //Filling in the needed resources
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    int f[p], ans[p], ind = 0;       //Initializing an array to keep track of processed elements
    for (int k = 0; k < p; k++) {
        f[k] = 0;
    }

    int y = 0;
    for (int k = 0; k < 5; k++) {         //Implementing Banker's Algorithm to find the safe sequence
        for (int i = 0; i < p; i++) {
            if (f[i] == 0) {
 
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]){
                        flag = 1;
                        break;
                    }
                }
 
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++){
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
             }
        }
    }
   
    int flag = 1;
   

    for(int i = 0;i < p; i++){            //Checking if sequence is safe or not
        if(f[i] == 0){
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }
 
    if(flag == 1){                        //Displaying the safe sequence if it exists
        cout << "Following is the SAFE Sequence" << endl;
        for (int i = 0; i < p - 1; i++){
            cout << " P" << ans[i] << " ->";
        }
      cout << " P" << ans[p - 1] <<endl;
    }
 
    return (0);
}
