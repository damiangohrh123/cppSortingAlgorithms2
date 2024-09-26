#include <bits/stdc++.h>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:

public:
    Node* root = nullptr;
    BinaryTree();
    ~BinaryTree();

    // Insert a node into the tree
    void insertNode(Node*& current, int val);

    // Delete a node from the tree
    Node* deleteNode(Node*& current, int val);

    // Get the lowest value node from the right subtree
    Node* getSuccessor(Node* current);

    // Search for a node in the tree
    Node* search(int val);

    // Visit the left subtree, the node, and then the right subtree.
    void inOrder(Node* current);

    // Visit the node, the left subtree, and then the right subtree.
    void preOrder(Node* current);

    // Visit the left subtree, the right subtree, and then the node.
    void postOrder(Node* current);

    // Visit nodes level by level from top to bottom (Breadth first).
    void levelOrder(Node* root);
};

BinaryTree::BinaryTree() {}

BinaryTree::~BinaryTree() {}

void BinaryTree::insertNode(Node*& current, int val) {
    // Base case
    if (current == nullptr) {
        current = new Node(val);
        return;
    }

    if (val > current->data) {
        insertNode(current->right, val);
    } else {
        insertNode(current->left, val);
    }
}

Node* BinaryTree::deleteNode(Node*& current, int val) {
    // If node cannot be found
    if (!current) return current;

    // Recursive calls
    if (val > current->data) {
        current->right = deleteNode(current->right, val);
    } else if (val < current->data) {
        current->left = deleteNode(current->left, val);
    } else {
        // Node to delete is a leaf
        if (!current->left && !current->right) return nullptr;

        // Node to delete has one child
        if ((!current->right && current->left) || (!current->left && current->right)) {
            if (current->left) {
                return current->left;
            } else {
                return current->right;
            }
        }

        // Node to delete has 2 children
        if (current->right && current->left) {
            Node *successor = getSuccessor(current);
            current->data = successor->data;

            // Delete successor node using deleteNode
            current->right = deleteNode(current->right, successor->data);
            return current;
        }
    }
    // Ensure every path returns a value
    return current;
}

Node* BinaryTree::getSuccessor(Node* current) {
    // Go to the right subtree first
    current = current->right;

    // If current node has no children, return current
    if (!current->left && !current->right) {
        return current;
    }

    // Start traversing to the left subtree
    while (current->left) {
        current = current->left;
    }

    return current;
}

Node* BinaryTree::search(int val) {
    return root;
}

void BinaryTree::inOrder(Node* current) {
    if (!current) return;

    inOrder(current->left);
    std::cout << current->data << " ";
    inOrder(current->right);
}

void BinaryTree::preOrder(Node* current) {
    if (!current) return;
    
    std::cout << current->data << " ";
    preOrder(current->left);
    preOrder(current->right);
}

void BinaryTree::postOrder(Node* current) {
    if (!current) return;
    
    postOrder(current->left);
    postOrder(current->right);
    std::cout << current->data << " ";
}

void BinaryTree::levelOrder(Node* root) {
    std::queue<Node*> queue;

    // Enqueue the root
    queue.push(root);

    while (queue.size() > 0) {
        // Dequeue a node
        Node* current = queue.front();
        std::cout << current->data << " ";
        queue.pop();

        // Enqueue its chilren if present
        if (current->left) queue.push(current->left);
        if (current->right) queue.push(current->right);
    }
}

int main() {
    BinaryTree *bt = new BinaryTree();
    bt->insertNode(bt->root, 56);
    bt->insertNode(bt->root, 22);
    bt->insertNode(bt->root, 33);
    bt->insertNode(bt->root, 45);
    bt->insertNode(bt->root, 66);
    bt->insertNode(bt->root, 23);
    bt->insertNode(bt->root, 5);
    bt->insertNode(bt->root, 2);
    bt->insertNode(bt->root, 8);
    bt->deleteNode(bt->root, 22);
    bt->inOrder(bt->root);
    std::cout << "\n";
    bt->preOrder(bt->root);
    std::cout << "\n";
    bt->postOrder(bt->root);
    std::cout << "\n";
    bt->levelOrder(bt->root);

    return 0;
}
