#include <iostream>
#include "ctime"
#include "fstream"
using namespace std;

struct Node
{
    int value = 0;
    int level = 0;
    Node* left = NULL;
    Node* right = NULL;

};

struct AATree {
    int count = 0;
    Node *root = 0;

    bool isEmpty(Node *n) {
        return n->value == 0;
    }

    Node *Skew(Node *node) {
        Node *left = node->left;
        if (left && left->level == node->level) {
            node->left = left->right;
            left->right = node;
            node = left;
        }
        return node;
    }

    Node *Split(Node *node) {
        Node *right = node->right;
        if (!right || !right->right) { return node; }
        else if (right->right->level == node->level) {
            node->right = right->left;
            right->left = node;
            node = right;
            node->level++;
            return node;
        } else return node;
    }

    Node *predecessor(Node *curNode) {

        curNode = curNode->left;
        while (curNode->right) {
            curNode = curNode->right;
        }
        return curNode;
    }

    Node *successor(Node *curNode) {

        curNode = curNode->right;
        while (curNode->left) {
            curNode = curNode->left;
        }
        return curNode;
    }

    bool Research(int item)
    {
        return Research(root,item);
    }

    bool Research(Node *r, int item) {
        bool found = false;
        int tempval;
        Node *temp = r;
        while (!found) {
            tempval = temp->value;
            if (item < tempval) {
                if (temp->left != 0) {
                    temp = temp->left;
                } else {
                    break;
                }

            } else if (item > tempval) {
                if (temp->right != 0) {
                    temp = temp->right;
                } else {
                    break;
                }
            } else {
                found = true;
            }
        }
        return found;
    }

    Node* decreaseLevel(Node *t) {
        int lvl;
        if (t->left && t->right) {
            if (t->left->level > t->right->level) {
                lvl = t->right->level + 1;
            } else {
                lvl = t->left->level + 1;
            }
            if (lvl < t->level) {
                t->level = lvl;
                if (t->right && lvl < t->right->level) {
                    t->right->level = lvl;
                }
            }
        }
        return t;
    }

    void Insert(int val) {
        root = Insert(root, val);
    }

    Node *Insert(Node *node, int val) {
        if (!node) {
            count++;
            Node *node1 = new Node;
            node1->value = val;
            node = node1;
            return node;
        } else {
            if (val < node->value) {
                node->left = Insert(node->left, val);
            } else if (val > node->value) {
                node->right = Insert(node->right, val);
            } else return node;
        }
        return Split(Skew(node));
    }

    void Delete(int item) {
        if (Research(root, item)) {
            root = Delete(root, item);
        }
    }

    Node* Delete(Node * t, int item) {
        Node *ms;
        if (isEmpty(t))
            return 0;
        if (item < t->value) {
            t->left = Delete(t->left, item);
        } else if (item > t->value) {
            t->right = Delete(t->right, item);
        } else {
            if (!t->left && !t->right) {
                return 0;
            }
            if (!t->left) {
                Node *l;
                l = successor(t);
                t->value = l->value;
                t->right = Delete(t->right, l->value);
            } else {
                Node *l;
                l = predecessor(t);
                t->value = l->value;
                t->left = Delete(t->left, l->value);
            }
        }
        t = decreaseLevel(t);
        t = Skew(t);
        if (t->right) {
            ms = t->right;
            t->right = Skew(ms);
            if (ms && ms->right) {
                t->right->right = Skew(ms->right);
            }
        }
        t = Split(t);
        t->right = Split(ms);
        return t;
    }

    void PrintAll(){
        PrintAll(root,0);
    }

    void PrintAll(Node* node, int id){
        if(!node) return;
        int i;
        PrintAll(node->right, id + 1);
        for (i = 0; i < id; i++)
            cout << "     ";
        printf("%d[%d]\r\n", node->value,node->level);
        PrintAll(node->left, id + 1);
    }
};
int main()
{
    AATree* tree = new AATree;

    tree->Insert(1);
    tree->Insert(3);
    tree->Insert(5);
    tree->Insert(6);
    tree->Insert(4);
    tree->Insert(0);

    tree->PrintAll();

    cout << "-------------------------";

    tree->Delete(4);
    cout << endl << tree->Research(4) << endl;
    cout << "-------------------------" << endl;
    tree->PrintAll();

    return 0;
}