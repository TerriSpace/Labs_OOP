#include "header.h"


int total(int a, int b) {

    int total = 0;
    
    for (int i = a; i <= b; i++){
        int num = i;
        while (num > 0){
            if(num % 2) total ++;
            num /= 2;
        }
    }  
    return total;
}