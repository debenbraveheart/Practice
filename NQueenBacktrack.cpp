#include <iostream>

#include <set>
using namespace std;
using namespace chrono;

bool isValid(int **arr, int n , int r, int c)
{
    bool res = true;
    
    for(int i = 0; i< r; ++i )
    {
        if((*arr)[i*n+c] == 1)
            res = false;
    }
    
    for(int i = 0; i< c; ++i )
    {
        if((*arr)[r*n+i] == 1)
            res = false;
    }
    
    for(int i= r-1, j=1; i>=0; --i, ++j)
    {
        int k = c-j;
        
        
        if(k>=0 && (*arr)[i*n+k] == 1)
            res = false;
        
        k = c+j;
        if(k<n && (*arr)[i*n+k] == 1)
            res = false;
        
    }
    
    return res;
    
}

bool bqueen(int **arr, int n,  int row)
{
    
    if(row == n)
        return false;
    
    for(int i=0; i<n; i++)
    {
        if(isValid(arr, n, row, i ))
        {
            (*arr)[row*n+i] = 1;
            
            if(n-1 == row)
                return true;
            
            auto r = bqueen(arr, n, row+1);
            
            if(r == true)
                return true;
            
            (*arr)[row*n+i] = 0;
        }
    }
    
    return false;
    
}

void rint(int **arr, int n)
{
    for(int i=0; i<n; ++i)
    {
        
        for(int j=0; j<n; ++j)
        {
            cout<<(*arr)[(i*n)+j]<< " ";
        }
        
        cout<<"\n";
    }
}

bool nqueen(int n)
{
    int *arr;
    
    arr = (int *)malloc(sizeof(int)*n*n);
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            arr[(i*n)+j] =0;
    
    
    if(bqueen(&arr, n, 0))
    {
        //rint arr
        rint(&arr,n);
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    
    nqueen(20);
    
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    
    cout<<"\n------ Time "<< time_span.count();
    return 0;
}
