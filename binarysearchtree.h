#ifndef BINARY_SEARCH_TREEE
#include <stdexcept>
#include <iostream>


class NonExistentElement:public std::logic_error{

public:
      NonExistentElement(std::string const& msg) : std::logic_error(msg) { }
};
class DuplicateKey:public std::logic_error{public:
      DuplicateKey(std::string const& msg) : std::logic_error(msg) { }
};

using std::ostream;
using std::endl;

template<typename K, typename V>
class BinarySearchTree;

template <typename K, typename V>
class TNode{

    K key;
    V value;
    TNode<K,V> * left;
    TNode<K,V> * right; // name convetnion lower case because its not a class


    friend class BinarySearchTree<K, V>;

  public:
    const V& getValue(){  //V& reference to actual value that node is pointing to
      return value;       //const: you cant modify the above value // just returns a pointer
    }

    TNode(K key, V value, TNode<K,V> * left = nullptr,
      TNode<K,V> * right = nullptr){
        this -> key = key;
        this -> value = value;
        this -> left = left;
        this -> right = right;
      }

};


template<typename K, typename V>
class BinarySearchTree {
private:

  TNode<K,V> * root;
  size_t size;
  TNode <K,V> * insert(K key, V value, TNode<K,V> * node);
  void serialize_helper(ostream& out, TNode<K,V> * node);
  TNode <K,V> *deleteNode(TNode<K, V> * node, K key, bool & found);
  TNode<K,V>* findMin(TNode<K,V>*n);
  TNode<K,V> * search(TNode<K,V>*n ,K key);


public:

  void insert(K key, V value);

  TNode<K,V> * search(K key); //output a value

  bool remove(K key);

  void serialize (std::ostream& out);//output all value to a strea

};

template<typename K, typename V>
TNode <K,V> * BinarySearchTree<K,V>::search(TNode<K,V>*node, K key){

  if (node == NULL || node->key == key)
     return node;

  if (node->key < key)
     return search(node -> right, key);

  return search(node -> left, key);
}

template<typename K, typename V>
TNode <K,V> * BinarySearchTree<K,V>::search(K key){



  return search(root, key);
}

template<typename K, typename V>
void BinarySearchTree<K,V>::insert(K key, V value){
    root= insert(key, value, root);
}

template<typename K, typename V>
TNode <K,V> * BinarySearchTree<K,V>::insert(K key, V value, TNode<K, V> * node){


  if (node == NULL) {
    ++size;
    return new TNode<K, V> (key, value);
  }


  if (key < node -> key)
      node -> left  = insert(key, value, node -> left);
  else if (key > node -> key)
      node -> right = insert(key, value, node -> right);
  else
  throw DuplicateKey("Insert of Invalid");

  return node;



}

template<typename K, typename V>
bool BinarySearchTree<K,V>::remove(K key){
  bool found = false;
  deleteNode(root, key, found);
  return found;

}

template<typename K, typename V>
TNode <K,V> * BinarySearchTree<K,V>::deleteNode(TNode<K, V> * node, K key, bool & found){

  if (node == NULL) return node; // base case

  //go Left
  if (key < node->key) {
      node->left = deleteNode(node->left, key);
      return node;
    }

  //go right
  else if (key > node->key) {
      node->right = deleteNode(node->right, key);
      return node;
    }

//found the key to be deleted
      else
      {
          found = true;
          if (node->right == NULL && node -> left == NULL){
            delete node;
            return NULL;
          }
          else if (node->right == NULL && node -> left != NULL){
            TNode<K, V>* leftChild = node -> left;
            delete node;
            return leftChild;
          }

          else if (node->right != NULL && node -> right -> left == NULL){
            TNode<K, V>* leftChild = node -> left;

            TNode<K, V>* rightChild = node -> right; //oringal nodes left kid

            rightChild -> left = leftChild;

            delete node;

            return rightChild;
          }
          else if(node->right != NULL && node -> right -> left != NULL){

            TNode<K, V>* inorderSuccesor = findmin(node->right);
            K tempkey = node -> key;
            V tempvalue = node -> value;

            node -> key = inorderSuccesor -> key;
            node -> value = inorderSuccesor -> value;

            inorderSuccesor -> key = tempkey;
            inorderSuccesor -> value = tempvalue;

            node -> right = deleteNode(node -> right, key);
            return node;

            }
          }
}

template<typename K, typename V>
void BinarySearchTree<K,V>::serialize(std::ostream& out){
  serialize_helper(out, root);

}

template<typename K, typename V>
void BinarySearchTree<K,V>::serialize_helper(std::ostream& out, TNode<K,V> * node){
  if (node == nullptr)
    return;

  out << node -> key << "~" << node -> value << std::endl;
  serialize_helper(out, node -> left);
  serialize_helper(out, node -> right);
}

template <typename K, typename V>
 TNode<K,V>* BinarySearchTree<K,V>::findMin(TNode<K,V>*n){

   TNode<K, V>* curr = n;

   while(curr->left != NULL)
       curr = curr->left;

   return curr;
 }
#endif
