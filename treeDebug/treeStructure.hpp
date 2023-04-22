#pragma once

#include<iostream>
#include<sstream>
#include<iomanip>
#include<memory>

template <typename T>
struct __treenode
{
    T val;
    __treenode<T>* left;
    __treenode<T>* right;
};