#include<iostream>
#include<fstream>
using namespace std;

void InsNeed(int need[5][5], int maxAllot[5][5],
int rAllot[5][5],int p,int r){
    for (int i = 0 ; i < p ; i++){
        for (int j = 0 ; j < r ; j++){
            need[i][j] = maxAllot[i][j] - rAllot[i][j];
        }
    }
}

void isSafe(int process[],int rAvail[5],int maxAllot[][5],int rAllot[][5],int P,int R){
int need[5][5];

InsNeed(need, maxAllot, rAllot,P,R);
  
bool finish[P] = {0};
  
int safeSeq[P];     // store safe sequence
  

int cop[R];    // copy of available resources
for (int i = 0; i < R ; i++)
cop[i] = rAvail[i];
  
int count = 0;
while (count < P){
    bool found = false;
    for (int p = 0; p < P; p++){
        if (finish[p] == 0){
        int j;
            for (j = 0; j < R; j++) {
                if (need[p][j] > cop[j]){
                break;
            }
        }

        if (j == R){
            for (int k = 0 ; k < R ; k++){
            cop[k] += rAllot[p][k];
            }
        safeSeq[count++] = p;
        finish[p] = 1;
        found = true;
        }
    }
}
  
    if (found == false){
    cout << "System is not in safe state";
    return;
    }
}
  
cout << "System is in a safe state.\n"
"Safe sequence is: ";
for (int i = 0; i < P ; i++)
cout << safeSeq[i] << " ";
return;
}


int main(){

ifstream ifile;
int process[5]; //Process array of max size 5;
  
int rAvail[5]; // available instances of resources
int rAllot[5][5]; //alloted instances
int maxAllot[5][5]; // maximum required instances of resources
  
//read input file
ifile.open("input.txt");
if(!ifile)
{
cout<<"\nCan't open file";
return 0;
}
int p,r;
ifile>>p>>r; //read process and resources in input
  
int i,j;
  
for(i=0;i<p;i++)
process[i]=i;
  
ifile>>rAvail[0]>>rAvail[1]>>rAvail[2]; //available ins

for(i=0;i<p;i++){
    for(j=0;j<r;j++){
        ifile>>rAllot[i][j];
    }
    for(j=0;j<r;j++){
    ifile>>maxAllot[i][j];  
    }
}

isSafe(process,rAvail,maxAllot,rAllot,p,r);
  
return 0;
  
}