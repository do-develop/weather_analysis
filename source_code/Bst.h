#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
//-------------------------------------------------------------
//-------------------------------------------------------------

/**
 * @class Bst
 * @brief Customized minimum binary search tree template class
 *
 * @author Doyoung Oh
 * @version 01
 * @date 09/10/2020 Created Bst class as per lab9 requirement
 *
 * @author Doyoung Oh
 * @version 02
 * @date 13/10/2020 Modified the class to meet lab10 requirement.(function poiter)
 */

//-------------------------------------------------------------
//DEFINITION OF STRUCT 'node'
//-------------------------------------------------------------
/**
 * @struct node
 * @brief represents a node inside a tree
 *
 * @author Doyoung Oh
 * @version 01
 * @date 09/10/2020 Created node struct for Bst class
 */
//To simplify operations such as insert and delete, the node of
//this binary search tree is implemented as a struct.
template<class T>
struct node
{
    T data;
    node* left;
    node* right;
};

//-------------------------------------------------------------
//DEFINITION OF THIS CLASS 'Bst'
//-------------------------------------------------------------
template<class T>
class Bst
{
public:

       /**
        * @brief Default constructor of Bst
        */
    Bst();

        /**
         * @brief Destructor of Bst
         */
    ~Bst();

        /**
         * @brief Copy constructor of Bst
         */
    Bst(const Bst<T>& other);

        /**
         * @brief Overloaded assignment operator of Bst
         * @param takes in a Bst object to be copied from
         * @return this Bst after assignment
         */
    Bst<T>& operator=(const Bst<T>& other);

        /**
         * @brief Searches an element inside the tree
         * @param takes in the reference to the element to be searched
         * @return boolean value indicating if the element exists in the tree
         */
    bool searchElement(const T& item);

        /**
         * @brief it searches an element and returns it when found
         * @param takes in the reference to the element to be searched
         * @return the matching node that has the element as the data
         */
    node<T>* findNode(T& item);

        /**
         * @brief a method to insert element inside the tree
         * @param takes in an item to be stored in the tree
         */
    void insertElement(T item);

        /**
         * @brief a method to delete element inside the tree
         * @param takes in an item to be removed from the tree
         */
    void deleteElement(T item);

        /**
         * @brief a method that completely deletes the tree
         */
    void deleteTree();

        /**
         * @brief traverse through the tree in inorder
         * @param void type function pointer
         */
    void inOrderTraversal(void(*fptr)(T& item)) const;

        /**
         * @brief traverse through the tree in preorder
         * @param void type function pointer
         */
    void preOrderTraversal(void(*fptr)(T& item)) const;

        /**
         * @brief traverse through the tree in postorder
         * @param void type function pointer
         */
    void postOrderTraversal(void(*fptr)(T& item)) const;

        /**
         * @brief a method that return the count of the nodes inside the tree
         * @return count of the nodes
         */
    int Count();

        /**
         * @brief a method that checks if the root is null. This method exist to fit the minimum but complete concept of this class
         * @return whether the tree is empty or not
         */
    bool IsEmpty() const;

private:
    ///the first node of the tree
    node<T>* root;
    ///count of the nodes of the tree
    int nodeCount;

//overloading methods to enable recursion
        /**
         * @brief a method that enables recursive call to insert element
         * @param a node to track the place to insert, item to be inserted
         */
    void insertElement(node<T>*& nd, T& item);

        /**
         * @brief a method that enables recursive call to search element
         * @param a node to track the place to search, item to be searched
         * @return the node tracing towards the item to be found/or not found
         */
    node<T>* searchElement(node<T>* nd, const T& item);

        /**
         * @brief a method that enables recursive call to delete element
         * @param a node to track the place to delete, item to be deleted
         * @return the node tracing towards the item to be found/or not found
         */
    void deleteElement(node<T>*& nd, T& item);

        /**
         * @brief a method that enables recursive call to delete entire tree
         * @param a node to track and delete one by one
         */
    void deleteTree(node<T>* nd);

        /**
         * @brief a method that enables recursive call to traverse the tree inorder
         * @param a node to track, a function pointer to do something throughout the traverse
         */
    void inOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const;

        /**
         * @brief a method that enables recursive call to traverse the tree preorder
         * @param a node to track, a function pointer to do something throughout the traverse
         */
    void preOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const;

        /**
         * @brief a method that enables recursive call to traverse the tree postorder
         * @param a node to track, a function pointer to do something throughout the traverse
         */
    void postOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const;

//private helper methods
        /**
         * @brief a method that creates a new node
         * @param an item to be inserted to the new node
         * @return the new node that is created
         */
    node<T>* createNewNode(const T& item);

        /**
         * @brief a method that finds the node with smallest value
         * @param a reference to the node to track towards the smallest node
         * @return a reference to the node with smallest value
         */
    node<T>*& findMin(node<T>*& nd);

        /**
         * @brief a method that copies the node from other tree
         * @param the copied node, the node to be copied are passed as parameter
         */
    void copyHelper(node<T>*& copyTo, const node<T>* copyFrom);

    //iterative delete node approach
    void deleteNode(node<T>*& nd);

};

//--------------------------------------------------------------
//CONSTRUCTORS & DESTRUCTOR
//--------------------------------------------------------------
template<class T>
Bst<T>::Bst()
{
    nodeCount = 0;
    root = nullptr;
}

template<class T>
Bst<T>::~Bst()
{
    deleteTree();
}

template<class T>
Bst<T>::Bst(const Bst<T>& other)
{
    copyHelper(root, other.root);
}

template<class T>
Bst<T>& Bst<T>::operator=(const Bst<T>& other)
{
    copyHelper(root, other.root);
    return *this;
}

//--------------------------------------------------------------
//SEARCH FOR AN ELEMENT
//--------------------------------------------------------------
template<class T>
bool Bst<T>::searchElement(const T& item)
{
    return searchElement(root, item);
}

template<class T>
node<T>* Bst<T>::searchElement(node<T>* nd, const T& item)
{
    if(nd!=nullptr)
    {
        if(item == nd->data)
            return nd;
        else if(item > nd->data)
            return searchElement(nd->right, item);
        else
            return searchElement(nd->left, item);
    }
    else
        return nullptr;
}

template<class T>
node<T>* Bst<T>::findNode(T& item)
{
    return searchElement(root, item);
}
//--------------------------------------------------------------
//INSERTION OF AN ELEMENT
//--------------------------------------------------------------
//Recursive Insert
/*
template<class T>
void Bst<T>::insertElement(T item)
{
    insertElement(root, item);
}

template<class T>
void Bst<T>::insertElement(node<T>*& nd, T& item)
{
    if(nd==NULL)
    {
        nd = createNewNode(item);
    }
    else
    {
        if(nd->data < item)
        {
            insertElement(nd->right, item);
        }
        else//duplicates will be stored in left side node
        {
            insertElement(nd->left, item);
        }
    }
}
*/
//Iterative insert from text book page 1386, Chapter 19
template<class T>
void Bst<T>::insertElement(T item)
{
    node<T>* current; //pointer to traverse the tree
    node<T>* trailCurrent = nullptr; //pointer behind current
    node<T>* newNode = createNewNode(item);

    if(root==nullptr)
    {
        root = newNode;
    }
    else
    {
        current = root;
        while(current != nullptr)
        {
            trailCurrent = current;
            if(current->data < item)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        if(trailCurrent->data < item)
        {
            trailCurrent->right = newNode;
        }
        else //duplicate is allowed left side
        {
            trailCurrent->left = newNode;
        }
    }

}
//--------------------------------------------------------------
//DELETION OF AN ELEMENT
//--------------------------------------------------------------
//recursive implementation of delete node from tree
/*
template<class T>
void Bst<T>::deleteElement(T item)
{
    deleteElement(root, item);
}

template<class T>
void Bst<T>::deleteElement(node<T>*& nd, T& item)
{
    if(nd == nullptr)
    {
        //value not found in tree, no action
    }
    else if(item==nd->data) //found the item(element) in the tree
    {
        node<T>* trash = nullptr;
        if(nd->left == nullptr && nd->right == nullptr)
        {
            trash = nd;
            nd = nullptr;
        }
        else if(nd->left!=nullptr && nd->right==nullptr)
        {
            trash = nd;
            nd = nd->left;
        }
        else if(nd->left==nullptr && nd->right!=nullptr)
        {
            trash = nd;
            nd = nd->right;
        }
        else//node has left and right subtrees
        {
            node<T>*& minNode = this->findMin(nd->right);
            nd->data = minNode->data;
            deleteElement(minNode, minNode->data);
        }
        //free memory
        if(trash != nullptr) delete trash;
        nodeCount--;
    }
    else if(item > nd->data)
    {
        deleteElement(nd->right, item);
    }
    else
    {
        deleteElement(nd->left, item);
    }
}
*/
//iterative implementation of delete a node from tree
//algorithm from textbook page 1390, Chapter 19
template<class T>
void Bst<T>::deleteElement(T item)
{
    node<T>* current;
    node<T>* trailCurrent; //pointer behind current
    bool found = false;

    if(root!=nullptr)//if the tree is not empty
    {
        current = root;
        trailCurrent = root;

        while(current!=nullptr && !found)
        {
            if(current->data == item)
            {
                found = true;
            }
            else
            {
                trailCurrent = current;
                if(current->data < item)
                {
                    current = current->right;
                }
                else
                {
                    current = current->left;
                }
            }
        }
        /*
        if(current==nullptr) //item to be delete is not in the tree
        {
            std::cout<<"The item to be deleted is not in the tree"<<std::endl;
        }
        */
        if(found)
        {
            if(current==root)
            {
                deleteNode(root);
            }
            else if(trailCurrent->data < item)
            {
                deleteNode(trailCurrent->right);
            }
            else
            {
                deleteNode(trailCurrent->left);
            }
        }
    }

}
template<class T>
void Bst<T>::deleteNode(node<T>*& nd)
{
    node<T>* current;
    node<T>* trailCurrent;
    node<T>* temp;

    if(nd->left==nullptr && nd->right==nullptr)
    {
        temp = nd;
        nd = nullptr;
        delete temp;
    }
    else if(nd->left==nullptr)
    {
        temp = nd;
        nd = nd->right;
        delete temp;
    }
    else if(nd->right==nullptr)
    {
        temp = nd;
        nd = nd->left;
        delete temp;
    }
    else//there are left and right subtrees
    {
        current = nd->left;
        trailCurrent = nullptr;

        while(current->right!=nullptr)
        {
            trailCurrent = current;
            current = current->right;
        }
        nd->data = current->data;

        if(trailCurrent==nullptr)
        {
            nd->left = current->left;
        }
        else
        {
            trailCurrent->right = current->left;
        }
        delete current;
    }
}
//--------------------------------------------------------------
//DELETE TREE
//--------------------------------------------------------------
template<class T>
void Bst<T>::deleteTree()
{
    deleteTree(root);
}

template<class T>
void Bst<T>::deleteTree(node<T>* nd)
{
    if(nd==NULL) return;

    deleteTree(nd->left);
    deleteTree(nd->right);
    delete nd;
    nd = nullptr;
}

//--------------------------------------------------------------
//TRAVERSAL(recursive)
//--------------------------------------------------------------
template<class T>
void Bst<T>::inOrderTraversal(void(*fptr)(T& item)) const
{
    inOrderTraversal(root, *fptr);
}

template<class T>
void Bst<T>::preOrderTraversal(void(*fptr)(T& item)) const
{
    preOrderTraversal(root, *fptr);
}

template<class T>
void Bst<T>::postOrderTraversal(void(*fptr)(T& item)) const
{
    postOrderTraversal(root, *fptr);
}

template<class T>
void Bst<T>::inOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const
{
    if(nd!=NULL)
    {
        inOrderTraversal(nd->left, *fptr);
        (*fptr)(nd->data);
        inOrderTraversal(nd->right, *fptr);
    }
}

template<class T>
void Bst<T>::preOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const
{
    if(nd!=NULL)
    {
        (*fptr)(nd->data);
        inOrderTraversal(nd->left, *fptr);
        inOrderTraversal(nd->right, *fptr);
    }
}

template<class T>
void Bst<T>::postOrderTraversal(node<T>* nd, void(*fptr)(T& item)) const
{
    if(nd!=NULL)
    {
        inOrderTraversal(nd->left, *fptr);
        inOrderTraversal(nd->right, *fptr);
        (*fptr)(nd->data);
    }
}

//------------------------------------------------------------
//COUNT OF NODES IN THE TREE
//------------------------------------------------------------
template<class T>
int Bst<T>::Count()
{
    return nodeCount;
}

template<class T>
bool Bst<T>::IsEmpty() const
{
    return root == nullptr;
}
//------------------------------------------------------------
//PRIVATE HELPER METHODS
//------------------------------------------------------------
template<class T>
void Bst<T>::copyHelper(node<T>*& copyTo, const node<T>* copyFrom)
{
    if(copyFrom==nullptr)
    {
        copyTo = nullptr;
    }
    else
    {
        copyTo = new node<T>;
        copyTo->data = copyFrom->data;
        copyHelper(copyTo->left, copyFrom->left);
        copyHelper(copyTo->right, copyFrom->right);
    }
}

template<class T>
node<T>* Bst<T>::createNewNode(const T& item)
{
    node<T>* newNode = new node<T>;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = item;

    nodeCount++;

    return newNode;
}

template<class T> //helper method to assist delete node member function
node<T>*& Bst<T>::findMin(node<T>*& nd)
{
    if(nd->left == nullptr)
    {
        return nd;
    }
    else
    {
        return this->findMin(nd->left);
    }
}

//-------------------------------------------------------------
//-------------------------------------------------------------
#endif // BST_H_INCLUDED
