#include <iostream>
#include <vector>
#include<set>
#include<ctime>
#include<random>
using namespace std;

void nearby_nodes(vector<vector<int>> adjm, int n){
  int x;
  cout<<"\nEnter node to find it's nearby nodes: ";
  cin>>x;
  for(int i=0; i<n; i++){
    if(adjm[x][i]==1){
      cout<<i<<" ,";
    }
  }
}


int degree_of_node(vector<vector<int>> adjm, int n){
  int x;
  int d=0;
  cout<<"\nEnter node to find it's degree: ";
  cin>>x;
  for(int i=0; i<n+1; i++){
    if(adjm[x][i]==1){
      d++;
    }
  }
  return d;
}



int maximum_degree(vector<vector<int>> adjm, int n){
  set<int> nodes;
  int max = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(adjm[i][j] == 1){
        nodes.insert(i);  
        nodes.insert(j);
      }
    }
  }
  int i=0;
  for(int node : nodes){
    int d = 0; 
    for(int j = 0; j < n; j++){
      if(adjm[node][j] == 1){
        d++;
      }
    }
    if(i==0){
      d=max;
    }
   if(d > max){
      max = d;
    }
    i++;
  }
  return max;
}


int minimum_degree(vector<vector<int>> adjm, int n){
  set<int> nodes;
  int min=0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(adjm[i][j] == 1){
        nodes.insert(i);  
        nodes.insert(j);
      }
    }
  }

int i=0;
  for(int node : nodes){
    
    int d = 0; 
    for(int j = 0; j < n; j++){
      if(adjm[node][j] == 1){
        d++;
        cout<<"("<<node<<","<<j<<")"<<endl;
      }
    }
    if(i==0){
      min=d;
    }
    if(d <min){
      min = d;
    }
    i++;
  }
  return min;
}
  
  



int main()
{
  int n;
  int x, y;
  float density;
  int degree=0;
  cout << "\nEnter number of nodes: ";
  cin >> n;
  cout<<"\nEnter density of graph: ";
  cin>>density;



  vector<vector<int>> adjM(n+1, vector<int>(n+1, 0));


    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (rand() / static_cast<double>(RAND_MAX) < density) {
                adjM[i][j] = 1;
                adjM[j][i] = 1;
            }
        }
    }

  
  cout<<degree_of_node(adjM,n);
  cout<<endl<<maximum_degree(adjM,n);
  cout<<endl<<minimum_degree(adjM,n);
  
  
  cout<<"\nAdjaceny matrix is: ";
  for(int i=1; i<n+1; i++){
    cout<<endl;
    for(int j=1; j<n+1; j++){
      cout<<adjM[i][j]<<" ";
    }
  }

  return 0;
}