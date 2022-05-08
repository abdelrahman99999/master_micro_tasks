/**
 * @file t1.cpp
 * @author abdelrahman elsayed
 * @brief task3
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<iostream>
#include<vector>

using namespace std;
/**
 * @brief Create a 1D vector suitable in size for 3D matrix
 * 
 * @param v_3d 3d matrix
 * @return vector<int> 
 */
vector<int> create_1D_suitable_for_3D(vector< vector< vector<int> > > v_3d ){
    int n,m,p;
    n = v_3d.size();
    m = v_3d[0].size();
    p = v_3d[0][0].size();

    vector<int>v_1d(m*n*p);
    return v_1d;
}

/**
 * @brief convert 3d indeces to 1d vector index
 * 
 * @param v_3d  3d matrix
 * @param i 1st index for 3d matrix
 * @param j 2nd index for 3d matrix
 * @param k 3rd index for 3d matrix
 * @return int - index of 1d vector
 */
int convert_index_from_3D_to_1D(vector< vector< vector<int> > > v_3d,int i,int j,int k){
    int n,m,p;
    n = v_3d.size();
    m = v_3d[0].size();
    p = v_3d[0][0].size();

    int y_index = i*m*p + j*p + k;  //O(1)
    return y_index;
}

/**
 * @brief move elements of 3d matrix to 1d vector
 * 
 * @param v_1d 1d vector
 * @param v_3d 3d matrix
 */
void fill_1D_with_3D_elements(  vector<int>&v_1d , vector< vector< vector<int> > > v_3d){
    int n,m,p;
    int y;
    n = v_3d.size();
    m = v_3d[0].size();
    p = v_3d[0][0].size();

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<p;++k){
                y=convert_index_from_3D_to_1D(v_3d,i,j,k);
                v_1d[y] =v_3d[i][j][k];
            }
        }    
    }
}

/**
 * @brief print elements of 3d matrix
 * 
 * @param v_3d 
 */
void print_3D(vector< vector< vector<int> > > v_3d){
    int n,m,p;
    n = v_3d.size();
    m = v_3d[0].size();
    p = v_3d[0][0].size();

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<p;++k){
                cout<<v_3d[i][j][k]<<" "; 
            }
            cout<<'\n';
        }    
        cout<<'\n';
    }
}

/**
 * @brief print elements of 1d matrix
 * 
 * @param v_1D 
 */
void print_1D(vector<int> v_1D){
    int q=v_1D.size();
    for(int y=0;y<q;y++){
        cout<<v_1D[y]<<" ";
    }
    cout<<'\n';
}

/**
 * @brief main function
 * 
 * @return int 
 */
int main(){
    //3d matrix of size 2*3*4
    vector< vector< vector<int> > > v_3d = { { {1,2,3,4}, {5,6,7,8},{9,10,11,12} },{ {13,14,15,16},{17,18,19,20},{21,22,23,24} } };;
    
    print_3D(v_3d);

    auto v_1d=create_1D_suitable_for_3D(v_3d);
    fill_1D_with_3D_elements(v_1d,v_3d);
    print_1D(v_1d);
    return 0;
}
