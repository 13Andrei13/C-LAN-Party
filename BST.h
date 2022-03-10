#pragma once

/*#include<iostream>
#include"Echipa.h"
#include<iomanip>
using namespace std;

class BST {
    
    struct node {
        string teamName;
        float teamScore;
        node* left;
        node* right;
    };

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(string name, float score, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->teamName = name;
            t->teamScore = score;
            t->left = t->right = NULL;
        }
        else if(score < t->teamScore)
            t->left = insert(name, score, t->left);
        else if(score > t->teamScore)
            t->right = insert(name, score, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(float x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->teamScore)
            t->left = remove(x, t->left);
        else if(x >  t->teamScore)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->teamName = temp->teamName;
            t->right = remove(t->teamScore, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t, ofstream& out) {
        if(t == NULL)
            return;
        inorder(t->left, out);

        char str[16];
        sprintf(str, "%.2f", t->teamScore);
        out << t->teamName << setw(37 - t->teamName.length()) << "-  " << str << endl;
        //cout << t->echipa->getPoe(t->echipa->getPl(), t->echipa->getNr()) << " ";


        inorder(t->right, out);
    }

    node* find(node* t, float x) {
        if(t == NULL)
            return NULL;
        else if(x < t->teamScore)
            return find(t->left, x);
        else if(x > t->teamScore)
            return find(t->right, x);
        else
            return t;
    }

public:
    bool isInited = false;
    BST() {
        root = NULL;
    }

    BST(Echipa* st) {
        Echipa* aux = st;
        isInited = true;
        root = NULL;
        while(aux != nullptr)
        {
            insert(aux->getNu(), aux->getPoe(aux->getPl(), aux->getNr()));
            aux = aux->next;
        }
    }

    ~BST() {
        isInited = false;
        root = makeEmpty(root);
    }

    void insert(string s, float f) {
        root = insert(s, f, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display(ofstream& out) {
        inorder(root, out);
    }

    void search(int x) {
        root = find(root, x);
    }

};*/

#include <fstream>

using namespace std;

struct node {
  string name;
  float data;
  node* left;
  node* right;
};

class BST 
{
  node* root;
  void insert(node*, float, string);
  void destroyTree(node*);
  void inOrder(node*, ofstream&);

public:
  BST();
  ~BST();
  void insert(float, string);
  void destroyTree();
  void display(ofstream&);
};