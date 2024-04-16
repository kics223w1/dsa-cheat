bool search(int val) {
    Node* current = root; 
    Node* lastAccessed = nullptr; 
    
    
    while (current) {
        lastAccessed = current; 
        if (val < current->val) {
            current = current->pLeft;
        } else if (val > current->val) {
            current = current->pRight;
        } else {
            splay(current); // Splay the found node to the root
            return true;
        }
    }

    if (lastAccessed) {
        splay(lastAccessed);
    }

    return false;
}
