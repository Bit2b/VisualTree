#include <iostream>
#include <string>
#include "../treeDebug/tree.hpp"
#include "../treeDebug/benchmark.hpp"
using namespace std;

// Define the Student struct
struct Student {
    int id;
    std::string name;

    // Constructor
    Student(int id, std::string name) : id(id), name(name) {}
	Student():id(0),name(""){}
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os <<student.id <<" "<< student.name;
        return os;
    }
};

// Define the Node struct
struct Node {
    Student student;
    Node* left;
    Node* right;

    // Constructor
    Node(Student student) : student(student), left(nullptr), right(nullptr) {}
};

// Function to insert a new node into the binary search tree
Node* insert(Node* root, Student student) {
    // If the root is null, create a new node with the student data
    if (root == nullptr) {
        return new Node(student);
    }

    // If the student ID is less than the root node's ID, insert into the left subtree
    if (student.id < root->student.id) {
        root->left = insert(root->left, student);
    }

    // If the student ID is greater than or equal to the root node's ID, insert into the right subtree
    else {
        root->right = insert(root->right, student);
    }

    return root;
}

// Function to print the binary search tree in inorder traversal
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << "ID: " << root->student.id << ", Name: " << root->student.name << endl;
    inorder(root->right);
}

int main() {
    // Create the root node
    Node* root = nullptr;

    // Insert some students into the binary search tree
    root = insert(root, Student(3, "Alice"));
    root = insert(root, Student(1, "Bob"));
    root = insert(root, Student(5, "Charlie"));
    // root = insert(root, Student(2, "Dave"));
    // root = insert(root, Student(4, "Emily"));

    // Print the binary search tree in inorder traversal
    inorder(root);

	PrintTreeHorizontally<Student>(root,15);
	PrintTree<Student>(root,15);
    return 0;
}
