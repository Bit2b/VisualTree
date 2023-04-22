#pragma once

#include "treeStructure.hpp"

static inline void add_spaces(std::string& s,int n)
{
    s.append(n + 1, ' ');
}

static inline void remove_spaces(std::string& s,int n)
{
    s.resize(s.size() - n - 1);
}

template <typename T>
static void print_values(std::string& s,std::stringstream&tree_buffer, const __treenode<T>* root,int width )
{
    remove_spaces(s,width);
    // tree_buffer << s << "-" << std::setw(width)<<std::setfill('-')<< (root ? root->val : "#") << std::endl;
    //it can not be used as tree value can be a value i.e. not string.
    if(!root)
        tree_buffer << s << "-" << std::setw(width)<<std::setfill('-')<< "#" << std::endl;
    else
        tree_buffer << s << "-" << std::setw(width)<<std::setfill('-')<< root->val << std::endl;
    add_spaces(s,width);
}

template <typename T>
static void PrintTreeHorizontally(const __treenode<T>* root, int width, std::stringstream& tree_buffer,std::string s,bool isright)
{
    //stopping condition for recursion
    if (!root)
    {
        print_values(s,tree_buffer,root,width);
        return;
    }

    //if it is right child then before recursing right remove the '|' symbol.
    if(isright)
    {
        remove_spaces(s,width+1);
        add_spaces(s,width+1);
    }

    //recurse to the right
    s.push_back('|');
    add_spaces(s,width);
    PrintTreeHorizontally(root->right, width, tree_buffer,s,1);
    remove_spaces(s,width);
    s.pop_back();
    
    //if it is right child then after printing right side add '|' symbol.
    if(isright)
    {
        remove_spaces(s,width+1);
        s.push_back('|');
        add_spaces(s,width);
    }    

    //print the value with indentation's
    print_values(s,tree_buffer,root,width);

    //if leftchild and going to left remove '|' symbol.
    if(!isright)
    {
        remove_spaces(s,width+1);
        add_spaces(s,width+1);
    }

    //recurse to the left
    s.push_back('|');
    add_spaces(s,width);
    PrintTreeHorizontally(root->left, width, tree_buffer,s,0);
    remove_spaces(s,width);
    s.pop_back();
}

template <typename T>
void PrintTreeHorizontally(void* rootNode,int width=5)
{
    __treenode<T>* root = (static_cast <__treenode<T>*> (rootNode));
    std::stringstream tree_buffer;
    std::string s(2*width,' ');
    PrintTreeHorizontally(root, width, tree_buffer, s,0);
    std::cout <<std::endl<<tree_buffer.str()<<std::endl;
}