#include "ShadoqArray.h"
#include <vector>
#include <chrono>
#include <iostream>

//GabeAlme

int main()
{
    bool isVec = false;
    int clock = 0;
    int arrSize = 100000;
    ShadowArray<int>* arr = new ShadowArray<int>();
    std::vector<int>* vec = new std::vector<int>();

    for (int i = 0; i < arrSize; i++) {
        std::chrono::high_resolution_clock::time_point timer = std::chrono::high_resolution_clock::now();
        vec->push_back(i);
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();;
        std::chrono::duration<double, std::milli>elapsed = std::chrono::duration<double, std::milli>{ end - timer };
        if (elapsed.count() > .001) {
            clock++;
        }
        if (elapsed.count() > .25) {
            isVec = true;
        }
        timer = std::chrono::high_resolution_clock::now();
    }
    if (isVec) {
        std::cout << "this is a vector" << std::endl;
    }
    std::cout << "vector times above .001 millisecons: " << clock << std::endl;

    //inside the for if the duration is longer than .1 milli print it out if it is a vector or the shadow array

    //write very clearly with the updated report

    clock = 0;
    isVec = false;

    
    for (int i = 0; i < arrSize; i++) {
        std::chrono::high_resolution_clock::time_point timer = std::chrono::high_resolution_clock::now();
        arr->add(i);
        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();;
        std::chrono::duration<double, std::milli>elapsed = std::chrono::duration<double, std::milli>{ end - timer };
        if (elapsed.count() > .001) {
            clock++;
        }
        
        timer = std::chrono::high_resolution_clock::now();
    }

    if (isVec) {
        std::cout << "this is a vector" << std::endl;
    }
    else
        std::cout << "this is a shadow array" << std::endl;

    std::cout << "vector times above .001 millisecons: " << clock << std::endl;

}

