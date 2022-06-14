```c++
#include <iostream>
#include <complex>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;
typedef vector<int> vi;
const int mod = (int)1e9 + 7;
class Matrix{
    int n,m;
    vector<vi > mat;
    public:
    Matrix(int n,int m, int type)
    {
        this->n=n;
        this->m=m;
        mat.assign(n,vi(m,0));
        if(type==1)
        {
            for(int i = 0;i < n;i++)
                mat[i][i]=1;
        }
        if(type==2)
        {
            for(int i = 0;i < n;i++)
                for(int j = 0;j < i;j++)
                mat[i][j]=1;
        }
        if (type == 3)
        {
           for(int j = 0;j < n;j++)
                mat[0][j]=1;
            for(int i = 1;i < n;i++)
                mat[i][i-1]=1;
        }
    }
    Matrix(vector<vi> inp)
    {
        this->n = inp.size();
        this->m = inp[0].size();
        mat = inp;
    }
    Matrix operator + (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,this->m,0);
        for(int i = 0; i < this->n;i++)
            for(int j = 0;j < this->m; j++)
            out.mat[i][j] = (this->mat[i][j]+b.mat[i][j])%mod;
        return out;
    }
    Matrix operator - (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,this->m,0);
        for(int i = 0; i < this->n;i++)
            for(int j = 0;j < this->m; j++)
            out.mat[i][j] = (this->mat[i][j]-b.mat[i][j]+mod)%mod;
        return out;
    }
    Matrix operator * (const Matrix &b)
    {
        class Matrix out = Matrix(this->n,b.m,0);
       for(int i = 0; i < this->n;i++)
            for(int j = 0;j < this->m; j++)
                for(int x = 0;x < this->m;x++)
                {
                    out.mat[i][j] += (this->mat[i][x]*b.mat[x][j])%mod;
                    out.mat[i][j] %=mod;
                }
        return out;
    }
    Matrix operator ^ (const int &p)
    {
        return matbin(*this,p);
    }
    Matrix matbin(Matrix a, int b)
    {
        if (b==0)
            return (Matrix(a.n,a.n,1));
        Matrix res = matbin(a,b/2);
        if (b%2)
            return res*res*a;
        else
            return res*res;
    }
    int get(int x,int y)
    {
        return this->mat[x][y];
    }
};

int main()
{
    Matrix m(3,3,1),a(3,3,2);
    m = m + a;
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3; j++)
            cout << m.get(i,j) << " ";
        cout << endl;
    }
}
```