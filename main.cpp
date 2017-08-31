//
//  main.cpp
//  Palindrom
//
//  Created by Kaila Billie on 8/26/17.
//  Copyright © 2017 Kaila Billie. All rights reserved.
//

#include <iostream>
using namespace std;

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

typedef int ElementType;

struct node{
    char data;
    node * next;
};

class List
{
public:
    bool isPalindrome (node *head) {
        if (head == NULL) {
            return true;
        }
        
        node *p = head->next;
        node *trail = head;
        
        //create a linked list in the reverse order of the given linked list
        while (p->next != NULL) {
            node *temp = p->next;
            temp->next = trail;
            trail = temp;
            p = p->next;
        }
        
        //create pointers to traverse the given linkedlist and the reversed one
        node *pointer = head;
        node *reversePointer = trail;
        
        //check if the spot in the given linkedlist matches the value in the reversed one
        while (pointer != NULL) {
            //if doesn't match then isn't a palindrome
            if (pointer->data != reversePointer->data) {
                return false;
            }
            
            pointer = pointer->next;
            reversePointer = reversePointer->next;
        }
        //is a palindrome
        return true;
    }

};


int main(int argc, const char * argv[]) {
    cout << "Hello, World!\n";
    return 0;
}

#endif /* List_hpp */
