#include <iostream>
#include <string.h>
#include <vector>
#include <utility>

using namespace std;

int bSearch_rotated(vector<int> v,int p);
int bSearch_changing_direction(vector<int> v,int p,bool standart);
bool operation(bool op,int a,int b);

int main()
{

    vector<int> v = {15,16,19,20,25,1,3,4,5,7,10,14};
    //int l = sizeof(v)/sizeof(int);
    //int x = bSearch_changing_direction(v,5,true,l);
    int x = bSearch_rotated(v,20);
    printf("%d",x);


    return 0;
}

int bSearch_rotated(vector<int> v,int p){

    int idx = bSearch_changing_direction(v,p,true);
    if(idx == -1){
        idx = bSearch_changing_direction(v,p,false);
    }
    return idx;
}

int bSearch_changing_direction(vector<int> v,int p,bool standart){

    int low = 0;
    int high = v.size()-1;

    bool op = standart;
    int last_direction = -1;
    int last_mid;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(v[mid] == p){
            return mid;
        }
        //printf("%d\n",v[mid]);
        if(mid == high){
            break;
        }
        //*changing directions
        if(last_direction == 1){
            //mid should be greater than last_mid
            if(v[mid] < v[last_mid]){
                op = !op;
            }
        }
        if(last_direction == 0){
            //mid should be less than last_mid
            if(v[mid] > v[last_mid]){
                op = !op;
            }
        }
        //*
        if(operation(op,v[mid],p)){
            low = mid+1;
            last_direction = 1;
        }
        if(operation(!op,v[mid],p)){
            high = mid-1;
            last_direction = 0;
        }
        last_mid = mid;
    }
    return -1;
}

bool operation(bool op,int a,int b){
    if(op){
        if(a < b){
            return true;
        }
        return false;
    }
    if(b < a){
        return true;
    }
    return false;
}

