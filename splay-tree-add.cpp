void insert(int val) {
    Node* current = root;
    Node* parent = nullptr;

    while (current) {
        parent = current;
        if (val < current->val) {
            current = current->pLeft;
        } else if (val >= current->val) {
            current = current->pRight;
        }
    }

    Node* newNode = new Node(val, nullptr, nullptr, parent);
    if (parent == nullptr) {
        root = newNode;
    } else if (val < parent->val) {
        parent->pLeft = newNode;
    } else {
        parent->pRight = newNode;
    }

    splay(newNode);
}



void rotateLeft(Node* x) {
    Node* y = x->pRight;
    if (y == nullptr) return;
    
    x->pRight = y->pLeft;
    if (y->pLeft) y->pLeft->pParent = x;
    y->pParent = x->pParent;
    if (x->pParent == nullptr)
        root = y;
    else if (x == x->pParent->pLeft)
        x->pParent->pLeft = y;
    else
        x->pParent->pRight = y;
        
    y->pLeft = x;
    x->pParent = y;
}

void rotateRight(Node* x) {
    Node* y = x->pLeft;
    if (y == nullptr) return;
    x->pLeft = y->pRight;
    if (y->pRight) y->pRight->pParent = x;
    y->pParent = x->pParent;
    if (x->pParent == nullptr)
        root = y;
    else if (x == x->pParent->pLeft)
        x->pParent->pLeft = y;
    else
        x->pParent->pRight = y;
    y->pRight = x;
    x->pParent = y;
}

void splay(Node* x) {
    while (x->pParent) {
        if (x->pParent->pParent == nullptr) {
            if (x->pParent->pLeft == x)
                rotateRight(x->pParent);
            else
                rotateLeft(x->pParent);
        } else if (x->pParent->pLeft == x && x->pParent->pParent->pLeft == x->pParent) {
            rotateRight(x->pParent->pParent);
            rotateRight(x->pParent);
        } else if (x->pParent->pRight == x && x->pParent->pParent->pRight == x->pParent) {
            rotateLeft(x->pParent->pParent);
            rotateLeft(x->pParent);
        } else if (x->pParent->pLeft == x && x->pParent->pParent->pRight == x->pParent) {
            rotateRight(x->pParent);
            rotateLeft(x->pParent);
        } else {
            rotateLeft(x->pParent);
            rotateRight(x->pParent);
        }
    }
}
