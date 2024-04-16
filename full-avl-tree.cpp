//Helping functions

Node* rotateRight(Node* root) {
    //TODO: Rotate and return new root after rotate
    Node* x = root->pLeft;

    root->pLeft = x->pRight;
    x->pRight = root;
    
    return x;

}

Node* rotateLeft(Node* root) {
    //TODO: Rotate and return new root after rotate
 
    Node* x = root->pRight;
    
    root->pRight = x->pLeft;
    x->pLeft = root;
    
    return x;
}

Node* insert2(Node* node, T value) {
    if(node == nullptr) {
        return new Node(value);
    }
    
    if(value >= node->data) {
        node->pRight = insert2(node->pRight, value);
    } else if(value < node->data) {
        node->pLeft = insert2(node->pLeft, value);
    } 
    
    int bal = getHeightRec(node->pLeft) - getHeightRec(node->pRight);
    
 
    // Left Left
    if(bal > 1 && value < node->pLeft->data) {
        return rotateRight(node);
    }
    
    // Right Right
    if(bal < -1 && value >= node->pRight->data) {
        return rotateLeft(node);
    }
    
    // Left Right
    if(bal > 1 && value >= node->pLeft->data) {
        node->pLeft = rotateLeft(node->pLeft);
        return rotateRight(node);
    }
    
    // Right Left
    if(bal < -1 && value < node->pRight->data) {
        node->pRight = rotateRight(node->pRight);
        return rotateLeft(node);
    }
    
    return node;
}

void insert(const T &value){
    //TODO
    root = insert2(root, value);
    
    
    
}

