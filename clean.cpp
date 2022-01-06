#include<iostream>
using namespace std;

bool is_ValidX(int n,int i)
{
    if(i >= 0 && i < n)
        return true;
    else
        return false;    
}

bool is_ValidY(int m,int j)
{
    if(j >= 0 && j < m)
        return true;
    else
        return false;
}

bool is_Allowed(int n,int m, int i,int j){

    if( is_ValidY(m, j) == 1 && is_ValidX(n, i) == 1)
        return true;
    else
        return false;
}

void path(int n, int m,int t, int rb, int cb, int rd, int cd, int &min, int dr, int dc){

    if(rb == rd || cb == cd ){
        
        min = (t < min) ? t : min;
        return;
    }

    if(is_Allowed(n, m, rb + dr, cb + dc))
        path(n, m, t + 1, rb + dr, cb + dc, rd, cd, min, dr, dc);
    else{
        
        if(is_ValidX(n, rb + dr) == false && is_ValidY(m, cb + dc) == true){
                    
            dr = -dr;
            path(n, m,  t + 1, rb + dr, cb + dr, rd, cd, min, dr, dc);
        }

        if(is_ValidX(n, rb + dr) == true && is_ValidY(m, cb + dc) == false){

            dc = -dc;
            path(n, m, t + 1, rb + dr, cb + dc, rd, cd, min,dr, dc);
        }
    }
}

int main(){

    int m, n , rb, cb, rd, cd , t, min;

    cin>>t;
    for(int i = 0; i < t; i++)
    {
        cin>>n>>m>>rb>>cb>>rd>>cd;

        min = 10000; 
        path(n, m, 0, rb - 1, cb - 1, rd - 1, cd - 1, min, 1, 1);        
 
        cout<<min<<'\n';
    }

    cout<<"Alhamdulillah\n";
    return 0;
}