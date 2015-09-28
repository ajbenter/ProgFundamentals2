//
//  main.cpp
//  LinkedLists
//
//  Created by Alexis Benter on 10/21/14.
//  Copyright (c) 2014 Alexis Benter. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class LinkedLists{
    
    //properties of each node
    struct Node {
        string programName;
        Node* nextInList;
        Node* nextInOrder;
    };
    
    Node* usedListHead;
    Node* freeListHead;
    Node* firstNode;
    int freeCount;
    int usedCount;
    
public:
    
    LinkedLists() {
        //starting properties of all pages
        freeCount = 32;
        usedCount = 0;
        
        usedListHead = nullptr;
        freeListHead = new Node();
        freeListHead->programName = "Free";
        firstNode = freeListHead;
        
        //setting all 32 pages as free nodes
        Node* pointer = freeListHead;
        for (int i = 0; i < freeCount; ++i) {
            Node* newNode = new Node();
            newNode->programName = "Free";
            pointer->nextInOrder = newNode;
            pointer->nextInList = newNode;
            pointer = newNode;
        }
    }
    
    //properties for free nodes
     Node* getFreeNode(string progName) {
        Node* freeNode = freeListHead;
        freeListHead = freeListHead->nextInList;
        
        freeNode->nextInList = nullptr;
        freeNode->programName = progName;
        
        return freeNode;
    }
    
    //adding new program to next free space
    void addNode(Node* node, Node* head, int& listCount) {
        Node* n;
        
        for (n = head; n->nextInList != nullptr; n = n->nextInList);
        
        n->nextInList = node;
        
        ++listCount;
    }
    
    //splitting program in to pages according to memory of program
    void addProgram(string progName, int progSize) {
        int nodesNeeded = progSize/4;
        if ((progSize%4) != 0) { ++nodesNeeded; }
        
        for (int i = 0; i < nodesNeeded; ++i) {
            Node* newNode = getFreeNode(progName);
            if (!usedListHead) { usedListHead = newNode; }
            else { addNode(newNode, usedListHead, usedCount); }
        }
    }
    
    //making used nodes of declared program free to kill it
    void freeUpNode(Node* nodeBefore) {
        Node* nodeToFreeUp = nodeBefore->nextInList;
        nodeBefore->nextInList = nodeToFreeUp->nextInList;
        nodeToFreeUp->programName = "Free";
        addNode(nodeToFreeUp, freeListHead, freeCount);
    }
    
    //killing the program
    void killProgram(string progName) {
        
        Node* n;
        
        for(n = firstNode; n->nextInOrder != nullptr; n = n-> nextInOrder) {
            if (n->nextInOrder->programName == progName) {
                freeUpNode(n);
            }
            
        }
        
        
    }
    
    //counting the memory used in all the pages for possible user errors
    int checkMemory(int& memoryCount) {
        Node* n;
        memoryCount = 0;
        
        for(n = firstNode; n->nextInOrder != nullptr; n = n->nextInOrder) {
            if (n->programName == "Free"){
                ++memoryCount;
                memoryCount = memoryCount*4;
            }
            
        }
        return memoryCount;
    }
    
    //counting the fragments
    void fragmentation(int& fragmentCount) {
        Node* n;
        fragmentCount = 0;
        
        for(n = firstNode; n->nextInOrder != nullptr; n = n->nextInOrder) {
            if (n->programName != "Free" && n->nextInOrder->programName == "Free"){
                ++fragmentCount;
            }
        }
    }
    
    //printing the pages of memory used or free
    void printMemory() {
        for(Node* n = firstNode; n->nextInOrder != nullptr; n = n->nextInOrder) {
            cout << n->programName << " ";
        }
        cout << endl;
    };
};

//running the program
int main() {
    char x;
    LinkedLists list = *new LinkedLists();
    
    //program menu
    while (x != '5'){
        cout<<"Choose the Number Corresponding to the Menu Option"<<endl;
        cout<<"1. Add Program"<<endl;
        cout<<"2. Kill Program"<<endl;
        cout<<"3. Fragmentation"<<endl;
        cout<<"4. Print Memory"<<endl;
        cout<<"5. Exit"<<endl;
    
        cin>>x;
    
        //user adding a program
        if (x == '1'){
            string programName;
            int programSize;
            int memoryCount;
            cout << "Enter a program name: ";
            cin >> programName;
            cout << endl;
            
            cout << "Enter a program size: ";
            cin >> programSize;
            cout << endl;
            if (programSize > list.checkMemory(memoryCount)){
                    cout << "Error: Not enough memory";
                    cout << "Enter a new program size: ";
                    cin >> programSize;
                }
            
            
            list.addProgram(programName, programSize);
        }
        
        //user killing a program
        else if (x == '2'){
            string programName;
            
            cout << "Enter the program name you want to delete";
            cin >> programName;
            cout << endl;
            
            list.killProgram(programName);
    
        }
        
        //user asking for fragment count
        else if (x == '3'){
            int fragmentCount;
            
            list.fragmentation(fragmentCount);
            
            cout<<fragmentCount;
            cout<<endl;
        }
        
        //user printing the pages of memory
        else if (x == '4'){
            list.printMemory();
        }
        
        //exiting the program
        else if (x == '5'){
            
        }
    
        else {
            cout<<"This is not an Option in the Menu.";
        }
    }
    
    return 0;
}







