//Helping functions



int getBal(Node* node) {
    if(node == nullptr) {
        return 0;
    }
    
    return getHeightRec(node->pLeft) - getHeightRec(node->pRight);
}

Node* findMaxVal(Node* node) {
    while(node && node->pRight != nullptr) {
        node = node->pRight;
    }
    return node;
}

Node* deleteNode(Node* node, T value) {
    
    if(node == nullptr) {
        return node;
    }
    
    if(value < node->data) {
        node->pLeft = deleteNode(node->pLeft, value);
    } else if(value > node->data) {
        node->pRight = deleteNode(node->pRight, value);
    } else {
        
        if(node->pLeft == nullptr || node->pRight == nullptr) {
            Node* t = node->pLeft != nullptr ? node->pLeft : node->pRight;
            if(t == nullptr) {
                node = NULL;
            } else {
                *node = *t;
            }
            
            
            delete t;
        } 
        else {
            Node* t = findMaxVal(node->pLeft);
            if(t != nullptr) {
                node->data = t->data;
                node->pLeft = deleteNode(node->pLeft, t->data);
            }
        }
    }
    
    
    if(node == nullptr) {
        return node;
    }
    
    int bal = getBal(node);
    
    // Left Left
    if(bal > 1 && getBal(node->pLeft) >= 0) {
        return rotateRight(node);
    }
    
    // Left Right
    if(bal > 1 && getBal(node->pLeft) < 0) {
            
        node->pLeft = rotateLeft(node->pLeft);
        
        return rotateRight(node);
    }
    
    // Right Right
    if(bal < -1 && getBal(node->pRight) <= 0) {
        return rotateLeft(node);
    }
    
    if(bal < -1 && getBal(node->pRight) > 0) {
            
        node->pRight = rotateRight(node->pRight);
        
        return rotateLeft(node);
    }
    
    return node;
}

void remove(const T &value){
    //TODO
    
    
    root = deleteNode(root, value);
    
    
    
}