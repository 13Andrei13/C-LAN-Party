#include <iostream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include "BST.h"

BST::BST()
{
  root = NULL;
}

BST::~BST()
{
  destroyTree();
}

void BST::insert(float key, string name)
{
  if (root != NULL) {
    insert(root, key, name);
  } else {
    root = new node;
    root->data = key;
    root->name = name;
    root->left = NULL;
    root->right = NULL;
  }
}

void BST::insert(node* leaf, float key, string name)
{
  if(key == leaf->data)
  {
      if(name.compare(leaf->name) <= 0) {
        if (leaf->left != NULL) {
          insert(leaf->left, key, name);
        } else {
        leaf->left = new node;
        leaf->left->data = key;
        leaf->left->name = name;
        leaf->left->left = NULL;
        leaf->left->right = NULL;
        }
      } else {
          if (leaf->right != NULL) {
            insert(leaf->right, key, name);
        } else {
            leaf->right = new node;
            leaf->right->data = key;
            leaf->right->name = name;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }
      }
  }else {
  
  
  if (key < leaf->data){
    if (leaf->left != NULL) {
      insert(leaf->left, key, name);
    } else {
      leaf->left = new node;
      leaf->left->data = key;
      leaf->left->name = name;
      leaf->left->left = NULL;
      leaf->left->right = NULL;
    }
  } else {
    if (leaf->right != NULL) {
      insert(leaf->right, key, name);
    } else {
      leaf->right = new node;
      leaf->right->data = key;
      leaf->right->name = name;
      leaf->right->left = NULL;
      leaf->right->right = NULL;
    }
  }
}
}



void BST::destroyTree()
{
  destroyTree(root);
}

void BST::destroyTree(node* leaf)
{
  if (leaf != NULL) {
    destroyTree(leaf->left);
    destroyTree(leaf->right);
  }

  delete leaf;
}

void BST::inOrder(node* t, ofstream& out)
{
  if (t != NULL) {
    inOrder(t->right, out);

    char str[16];
    sprintf(str, "%.2f", t->data);
    out << t->name<< setw(37 - t->name.length()) << "-  " << str << endl;
    //out << t->name << " " <<t->data <<" "<<endl;
    inOrder(t->left, out);
  }
}

void BST::display(ofstream& out)
{ 
  inOrder(root, out);
}