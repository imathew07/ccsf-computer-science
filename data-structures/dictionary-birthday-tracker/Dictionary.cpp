// Mateo Sanchez Sinche, CS 110 C

#include "Dictionary.h"

//-----------------------
// Private Methods:
//-----------------------

// Helper function to insert a new node into the BST
Node* Dictionary::insert(Node* node, Person p)
{
    if (node == nullptr)
        return new Node(p);
    // Inserrt left
    if (p.getName() < node->data.getName())
        node->left = insert(node->left, p);
    // Insert right
    else if (p.getName() > node->data.getName())
        node->right = insert(node->right, p);

    return node;
}

// Helper function to remove a node from the BST
Node* Dictionary::removeNode(Node* node, std::string name)
{
    if (node == nullptr)
        return nullptr;

    // Go left
    if (name < node->data.getName())
    {
        node->left = removeNode(node->left, name);
    }
    // Go right
    else if (name > node->data.getName())
    {
        node->right = removeNode(node->right, name);
    }

    // Found node to delete
    else
    {
        // Case 1: no child
        if (node->left == nullptr && node->right == nullptr)
        {
            delete node;
            return nullptr;
        }

        // Case 2: one child (right)
        else if (node->left == nullptr)
        {
            Node* temp = node->right;
            delete node;
            return temp;
        }

        // Case 3: one child (left)
        else if (node->right == nullptr)
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        // Case 4: two children
        else
        {
            Node* minRight = findMin(node->right);
            node->data = minRight->data;
            node->right = removeNode(node->right, minRight->data.getName());
        }
    }
    return node;
}

// Helper function to find the node with the minimum value in a subtree
Node* Dictionary::findMin(Node* node)
{
    while (node->left != nullptr)
    {
        node = node->left;
    }
    return node;
}

// Helper function to search for a person by name
Person* Dictionary::search(Node* node, std::string name)
{
    if (!node)
        return nullptr;

    if (name == node->data.getName())
        return &node->data;

    if (name < node->data.getName())
        return search(node->left, name);

    return search(node->right, name);
}

// Helper function for in-order traversal to display all entries
void Dictionary::inorder(Node* node)
{
    if (!node) return;

    inorder(node->left);
    node->data.print();
    inorder(node->right);
}

// Helper function to search for people born in a specific month
void Dictionary::searchByMonth(Node* node, int month)
{
    if (!node) return;

    searchByMonth(node->left, month);

    if (node->data.getMonth() == month)
        node->data.print();

    searchByMonth(node->right, month);
}

//-----------------------
// Public Methods:
//-----------------------

// Constructor
Dictionary::Dictionary()
{
    root = nullptr;
}

// Add a new person to the dictionary
bool Dictionary::add(Person p)
{
    if (search(root, p.getName()) != nullptr)
        return false;

    root = insert(root, p);
    return true;
}

// Remove a person from the dictionary by name
bool Dictionary::remove(std::string name)
{
    if (search(root, name) == nullptr)
        return false;

    root = removeNode(root, name);
    return true;
}

// Search for a person by name and return a pointer to their data
Person* Dictionary::getItem(std::string name)
{
    return search(root, name);
}

// Display all entries in the dictionary
void Dictionary::displayAll()
{
    inorder(root);
}

// Display all entries in the dictionary born in a specific month
void Dictionary::displayByMonth(int month)
{
    searchByMonth(root, month);
}