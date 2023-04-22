#pragma once

#include "treeStructure.hpp"

template <typename T>
static int CalculateTreeHeight(const __treenode<T>* root)
{
    if(!root) return 0;
    return 1+std::max(CalculateTreeHeight(root->left),CalculateTreeHeight(root->right));
}

template <typename T>
static void FillElementsArray(const std::unique_ptr<T[]>& elements,
const __treenode<T>* Root,const std::unique_ptr<bool[]>& elementExist,const int index)
{
    if(!Root)return;
    elements[index]=Root->val;
    elementExist[index]=true;
    FillElementsArray(elements,Root->left,elementExist,index*2+1);
    FillElementsArray(elements,Root->right,elementExist,index*2+2);
}

template <typename T>
void PrintTreeVisual(const std::unique_ptr<T[]>& elements,int treeHeight,const std::unique_ptr<bool[]>& elementExist,const int elementWidth)
{
    int currentIndex=0;
    int treeWidth =(1<<(treeHeight+1))*elementWidth;
    std::string startEnd(treeWidth,'_');
    std::string nline(treeWidth,' ');
    std::cout<<" "<<startEnd<<" "<<std::endl;
    std::cout<<"|"<<nline<<"|"<<std::endl;
    for(int k=0;k<=treeHeight;k++)
    {
        std::stringstream ss;
        ss<<"|"<<nline<<"|"<<std::endl;
        ss<<"|";
        int currentLevelEndIndex = (1<<k) + currentIndex;
        while(currentIndex<currentLevelEndIndex)
        {
            int spacesBetweenElements=(1<<(treeHeight-k))-1;
            for(int j=0;j<spacesBetweenElements;j++)
            {
                ss<<std::setw(elementWidth) << " ";
            }
            if(elementExist[currentIndex])
                ss<<std::setw(elementWidth) << elements[currentIndex];
            else
            {
                int parent = currentIndex%2?currentIndex>>1:(currentIndex-1)>>1;
                if(elementExist[parent])
                    ss<<std::setw(elementWidth) << "#";
                else
                    ss<<std::setw(elementWidth) << " ";
            }   
            for(int j=0;j<spacesBetweenElements;j++)
            {
                ss<<std::setw(elementWidth) << " ";
            }
            ss<<std::setw(elementWidth) << " ";
            currentIndex++;
        }
        ss<<"|"<<std::endl<<"|"<<nline<<"|"<<std::endl;
        std::cout << ss.str();
    }
    std::cout<<"|"<<startEnd<<"|"<<std::endl;    
}

template <typename T>
void PrintTree(void* rootNode, int elementWidth=2) 
{
    __treenode<T>* root=(static_cast<__treenode<T>*>(rootNode));
    int treeHeight = CalculateTreeHeight(root);
    int treeWidth =(1<<(treeHeight+1))*elementWidth;
    const int screenWidth=174;//in no of characters
    int numElements = (1<<(treeHeight+1))-1;
    std::unique_ptr<T[]> elements(new T[numElements]());
    std::unique_ptr<bool[]> elementExists(new bool[numElements]());
    while(treeWidth>screenWidth)
    {
        treeHeight--;
        treeWidth =(1<<(treeHeight+1))*elementWidth;
    }
    FillElementsArray(elements,root,elementExists,0);
    PrintTreeVisual(elements,treeHeight,elementExists,elementWidth);
}