Node* remove(int val) {
    if (!root) {
        return nullptr;
    }
    
    bool found = search(val);

    if (!found || root->val != val) {
        return nullptr; 
    }

    Node* nodeToRemove = root;

    Node* tree1 = root->pLeft;
    Node* tree2 = root->pRight;

    if (tree1) {
        tree1->pParent = nullptr;
    }
    if (tree2) {
        tree2->pParent = nullptr;
    }

    delete root;

    if (!tree1) {
        root = tree2;
    } else {
        Node* largestInTree1 = tree1;
        while (largestInTree1->pRight) {
            largestInTree1 = largestInTree1->pRight;
        }
        splay(largestInTree1);

        root->pRight = tree2;

        if (tree2) {
            tree2->pParent = root;
        }
    }

    return nodeToRemove;
}
