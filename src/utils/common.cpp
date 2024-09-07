//
// Created by EasternMoon on 2024/6/27.
//
#include "common.h"

template<typename T>
void common<T>::printData(T data) {
    cout << data << endl;
}

template<typename T>
void common<T>::printVector(vector<T> result) {
    for_each(result.begin(), result.end(), printData);
}

template<typename T>
void common<T>::printVectors(vector<vector<T> > results) {
    for_each(results.begin(), results.end(), printVector);
}