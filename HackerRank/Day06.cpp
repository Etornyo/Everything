#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T,i,j;
    cin >> T;
    
    for(i=0; i < T ; i++){
        string S;
        cin >> S;
        string even_chars, odd_chars;
         
    for(j = 0; j < S.length(); j++){
        if(j%2 == 0){
            even_chars += S[j];}
        else{
            odd_chars += S[j];
        }
    }
    
    cout << even_chars << " " << odd_chars << endl;

    }   
    return 0;
}

