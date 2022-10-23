/***********************
Red Black Tree
***********************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <cassert>
#define INDENT_STEP 4

using namespace std;

enum color { RED, BLACK };

/*********************
    Node Declaration
**********************/
typedef struct rbtree_node
{
    enum color color;
    void *key;
    void *value;
    rbtree_node *left, *right, *parent;
}*node;

typedef struct rbtree_t
{
    node root;
}*rbtree;

/*********************
    Class Declaration
**********************/
class RBTree
{
    public:
        typedef int (*compare_func)(void* left, void* right);
        rbtree rbtree_create();
        void* rbtree_find(rbtree t, void* , compare_func compare);
        void rbtree_insert(rbtree t, void* , void* , compare_func compare);
        void rbtree_delete(rbtree t, void* , compare_func compare);
        node grandparent(node n);
        node sibling(node n);
        node uncle(node n);
        void verify_properties(rbtree t);
        void verify_property_1(node root);
        void verify_property_2(node root);
        color node_color(node n);
        void verify_property_4(node root);
        void verify_property_5(node root);
        void verify_property_5_helper(node n, int , int*);
        node new_node(void* key, void* , color , node , node);
        node find_node(rbtree t, void* , compare_func compare);
        void rotate_left(rbtree t, node n);
        void rotate_right(rbtree t, node n);
        void replace_node(rbtree t, node oldn, node newn);
        void insert_case1(rbtree t, node n);
        void insert_case2(rbtree t, node n);
        void insert_case3(rbtree t, node n);
        void insert_case4(rbtree t, node n);
        void insert_case5(rbtree t, node n);
        node maximum_node(node root);
        void delete_case1(rbtree t, node n);
        void delete_case2(rbtree t, node n);
        void delete_case3(rbtree t, node n);
        void delete_case4(rbtree t, node n);
        void delete_case5(rbtree t, node n);
        void delete_case6(rbtree t, node n);
};

/******************************
    Return Grandparent of Node
*******************************/
node RBTree::grandparent(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return n->parent->parent;
}

/****************************
    Return Sibling of Node
*****************************/
node RBTree::sibling(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    if (n == n->parent->left)
        return n->parent->right;
    else
        return n->parent->left;
}

/*****************************
    Return Uncle of Node
******************************/
node RBTree::uncle(node n)
{
    assert (n != NULL);
    assert (n->parent != NULL);
    assert (n->parent->parent != NULL);
    return sibling(n->parent);
}

/*******************************************
    Verifying Properties of Red black Tree
********************************************/
void RBTree::verify_properties(rbtree t)
{
    verify_property_1 (t->root);
    verify_property_2 (t->root);
    verify_property_4 (t->root);
    verify_property_5 (t->root);
}

/*******************************************
    Verifying Property 1
    A node is either RED or BLACK
********************************************/
void RBTree::verify_property_1(node n)
{
    assert (node_color(n) == RED || node_color(n) == BLACK);
    if (n == NULL)
        return;
    verify_property_1(n->left);
    verify_property_1(n->right);
}

/***************************************
    Verifying Property 2
    The root node is BLACK
****************************************/
void RBTree::verify_property_2(node root)
{
    assert (node_color(root) == BLACK);
}

/*****************************************
    Returns color of a node
******************************************/
color RBTree::node_color(node n)
{
    return n == NULL ? BLACK : n->color;
}

/************************************************
    Verifying Property 4
    Every RED node must have 2 BLACK child node
*************************************************/
void RBTree::verify_property_4(node n)
{
    if (node_color(n) == RED)
        {
            assert (node_color(n->left) == BLACK);
            assert (node_color(n->right) == BLACK);
            assert (node_color(n->parent) == BLACK);
        }

    if (n == NULL)
        return;

    verify_property_4(n->left);
    verify_property_4(n->right);
}

/***********************************************
    Verifying Property 5
    Every path from a given node to have
    any of its decendant NULL nodes contains
    the same number os BALCK nodes
************************************************/
void RBTree::verify_property_5(node root)
{
    int black_count_path = -1;
    verify_property_5_helper(root, 0, &black_count_path);
}

/*******************************************
    Verifying Property 5 Helper

*******************************************/
void RBTree::verify_property_5_helper(node n, int black_count, int* path_black_count)
{
    if (node_color(n) == BLACK)
        {
            black_count++;
        }
    if (n == NULL)
        {
            if (*path_black_count == -1)
            {
                *path_black_count = black_count;
            }
            else
            {
                assert (black_count == *path_black_count);
            }
            return;
        }

        verify_property_5_helper(n->left, black_count, path_black_count);
        verify_property_5_helper(n->right, black_count, path_black_count);
}

/*********************************
    Create Red Black Tree
**********************************/
rbtree RBTree::rbtree_create()
{
    rbtree t = new rbtree_t;
    t->root = NULL;
    verify_properties(t);
    return t;
}

/*********************************************
    Creating New Node of RBT
*********************************************/
node RBTree::new_node(void* k, void* v, color n_color, node left, node right)
{
    node result = new rbtree_node;
    result->key = k;
    result->value = v;
    result->color = n_color;
    result->left = left;
    result->right = right;
    if (left != NULL)
        left->parent = result;
    if (right != NULL)
        right->parent = result;

    result->parent = NULL;
    return result;
}

/***************************
    Find
****************************/
node RBTree::find_node(rbtree t, void* key, compare_func compare)
{
    node n = t->root;
    while (n != NULL)
        {
            int comp_result = compare(key, n->key);
            if (comp_result == 0)
                {
                    return n;
                }
            else if (comp_result < 0)
                {
                    n = n->left;
                }
            else
                {
                    assert(comp_result > 0);
                    n = n->right;
                }
        }
    return n;
}

/*****************************
    RBT Find
******************************/
void* RBTree::rbtree_find(rbtree t, void* key, compare_func compare)
{
    node n = find_node(t, key, compare);
    return n == NULL ? NULL : n->value;
}

/*****************************
    Rotate left
******************************/
void RBTree::rotate_left(rbtree t, node n)
{
    node r = n->right;
    replace_node(t, n, r);
    n->right = r->left;
    if (r->left != NULL)
        {
            r->left->parent = n;
        }

    r->left = n;
    n->parent = r;
}

/*************************
    Rotate right
**************************/
void RBTree::rotate_right(rbtree t, node n)
{
    node L = n->left;
    replace_node(t, n, L);
    n->left = L->right;
    if (L->right != NULL)
        {
            L->right->parent = n;
        }

    L->right = n;
    n->parent = L;
}

/***************************
    Replace a node
****************************/
void RBTree::replace_node(rbtree t, node oldn, node newn)
{
    if (oldn->parent == NULL)
        {
            t->root = newn;
        }
    else
        {
            if (oldn == oldn->parent->left)
                oldn->parent->left = newn;
            else
                oldn->parent->right = newn;
        }

    if (newn != NULL)
        {
            newn->parent = oldn->parent;
        }
}

/**************************************
    Insertion
***************************************/
void RBTree::rbtree_insert(rbtree t, void* key, void* value, compare_func compare)
{
    node inserted_node = new_node(key, value, RED, NULL, NULL);
    if (t->root == NULL)
        {
            t->root = inserted_node;
        }
    else
        {
            node n = t->root;
            while (1)
                {
                    int comp_result = compare(key, n->key);

                    if (comp_result == 0)
                        {
                            n->value = value;
                            return;
                        }
                    else if (comp_result < 0)
                        {
                            if (n->left == NULL)
                            {
                                n->left = inserted_node;
                                break;
                            }
                            else
                            {
                                n = n->left;
                            }
                        }
                    else
                        {
                            assert (comp_result > 0);
                            if (n->right == NULL)
                                {
                                    n->right = inserted_node;
                                    break;
                                }
                            else
                                {
                                    n = n->right;
                                }
                        }
                }

            inserted_node->parent = n;
        }
    insert_case1(t, inserted_node);
    verify_properties(t);
}

/**************************
    Insertion Case 1
    Root case
***************************/
void RBTree::insert_case1(rbtree t, node n)
{
    if (n->parent == NULL)
        n->color = BLACK;
    else
        insert_case2(t, n);
}

/***************************
    Insertion Case 2
    Parent color is BLACK
****************************/
void RBTree::insert_case2(rbtree t, node n)
{
    if (node_color(n->parent) == BLACK)
        return;
    else
        insert_case3(t, n);
}

/***********************
    Insertion Case 3
    Uncle color is RED
************************/
void RBTree::insert_case3(rbtree t, node n)
{
    if (node_color(uncle(n)) == RED)
        {
            n->parent->color = BLACK;
            uncle(n)->color = BLACK;
            grandparent(n)->color = RED;
            insert_case1(t, grandparent(n));
        }
    else
        {
            insert_case4(t, n);
        }
}

/****************************
    Insertion Case 4
    Uncle color is BLACK
    Left Right and Right Left Cases
*****************************/
void RBTree::insert_case4(rbtree t, node n)
{
    //Left Right Case
    if (n->parent == grandparent(n)->left && n == n->parent->right)
        {
            rotate_left(t, n->parent);
            n = n->left;
        }
    //Right Left Case
    else if (n->parent == grandparent(n)->right && n == n->parent->left)
        {
            rotate_right(t, n->parent);
            n = n->right;
        }
    insert_case5(t, n);
}

/********************************
    Insertion Case 5
    Uncle color is BLACK
    Left Left and  Right Right Case
*********************************/
void RBTree::insert_case5(rbtree t, node n)
{
    n->parent->color = BLACK;
    grandparent(n)->color = RED;
    //Left Left Case
    if (n->parent == grandparent(n)->left && n == n->parent->left)
        {
            rotate_right(t, grandparent(n));
        }
    //Right Right case
    else if (n->parent == grandparent(n)->right && n == n->parent->right)
        {
            rotate_left(t, grandparent(n));
        }
}

/*********************************
    Deletion
**********************************/
void RBTree::rbtree_delete(rbtree t, void* key, compare_func compare)
{
    node child;
    node n = find_node(t, key, compare);
    if (n == NULL)
        return;
    if (n->left != NULL && n->right != NULL)
        {
            node pred = maximum_node(n->left);
            n->key = pred->key;
            n->value = pred->value;
            n = pred;
        }

    assert(n->left == NULL || n->right == NULL);
    child = n->right == NULL ? n->left : n->right;
    if (node_color(n) == BLACK)
        {
            n->color = node_color(child);
            delete_case1(t, n);
        }
    replace_node(t, n, child);
    free(n);
    verify_properties(t);
}

/******************************
    Return Maximum node
*******************************/
node RBTree::maximum_node(node n)
{
    assert (n != NULL);
    while (n->right != NULL)
        {
            n = n->right;
        }
    return n;
}

/*******************************
    Deletion Case 1
    Root Case
********************************/
void RBTree::delete_case1(rbtree t, node n)
{
    if (n->parent == NULL)
        return;
    else
        delete_case2(t, n);
}

/*****************************
    Deletion Case 2
    Sibling Node is RED
******************************/
void RBTree::delete_case2(rbtree t, node n)
{
    if (node_color(sibling(n)) == RED)
        {
            n->parent->color = RED;
            sibling(n)->color = BLACK;
            if (n == n->parent->left)
                rotate_left(t, n->parent);
            else
                rotate_right(t, n->parent);
        }
    delete_case3(t, n);
}

/****************************
    Deleting Case 3
    Parent is BLACK
    Sibling is BLACK
    Both Childrent are BLACK
*****************************/
void RBTree::delete_case3(rbtree t, node n)
{
    if (node_color(n->parent) == BLACK && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == BLACK && node_color(sibling(n)->right) == BLACK)
        {
            sibling(n)->color = RED;
            delete_case1(t, n->parent);
        }
    else
        delete_case4(t, n);
}

/***********************************
    Deleting Case 4
    Parent is RED
    Sibling is BLACK
    Both Childrent are BLACK
*************************************/
void RBTree::delete_case4(rbtree t, node n)
{
    if (node_color(n->parent) == RED && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == BLACK && node_color(sibling(n)->right) == BLACK)
            {
                sibling(n)->color = RED;
                n->parent->color = BLACK;
            }
    else
        delete_case5(t, n);
}

/*******************************
    Deleting Case 5
    Parent is BLACK
    Sibling is BLACK
********************************/
void RBTree::delete_case5(rbtree t, node n)
{
    //Parent Left Child, Sibling Left Child is RED, Sibling Right Child is BLACK
    if (n == n->parent->left && node_color(sibling(n)) == BLACK &&
        node_color(sibling(n)->left) == RED && node_color(sibling(n)->right) == BLACK)
            {
                sibling(n)->color = RED;
                sibling(n)->left->color = BLACK;
                rotate_right(t, sibling(n));
            }
    //Parent Right Child, Sibling Left Child is BLACK, Sibling Right Child is RED
    else if (n == n->parent->right && node_color(sibling(n)) == BLACK &&
             node_color(sibling(n)->left) == BLACK && node_color(sibling(n)->right) == RED)
            {
                sibling(n)->color = RED;
                sibling(n)->right->color = BLACK;
                rotate_left(t, sibling(n));
            }
    delete_case6(t, n);
}

/********************************************
    Deleting Case 6
    Sibling and parent colors are BLACK
*********************************************/
void RBTree::delete_case6(rbtree t, node n)
{
    sibling(n)->color = node_color(n->parent);
    n->parent->color = BLACK;
    //Parent Left Child
    if (n == n->parent->left)
        {
            assert (node_color(sibling(n)->right) == RED);
            sibling(n)->right->color = BLACK;
            rotate_left(t, n->parent);
        }
    //Parent Right Child
    else
        {
            assert (node_color(sibling(n)->left) == RED);
            sibling(n)->left->color = BLACK;
            rotate_right(t, n->parent);
        }
}

/*******************************
    Comparation of two nodes
********************************/
int compare_int(void* leftp, void* rightp)
{
    int left = (int)leftp;
    int right = (int)rightp;
    if (left < right)
        return -1;
    else if (left > right)
        return 1;
    else
        {
            assert (left == right);
            return 0;
        }
}

/**********************************
    Print Red Black Tree
***********************************/
void print_tree_helper(node n, int indent)
{
    int i;
    if (n == NULL)
        {
            fputs("<empty tree>", stdout);
            return;
        }
    if (n->right != NULL)
        {
            print_tree_helper(n->right, indent + INDENT_STEP);
        }
    for(i = 0; i < indent; i++)
        fputs(" ", stdout);
    if (n->color == BLACK)
        cout<<(int)n->key<<endl;
    else
        cout<<"<"<<(int)n->key<<">"<<endl;
    if (n->left != NULL)
        {
            print_tree_helper(n->left, indent + INDENT_STEP);
        }
}

void print_tree(rbtree t)
{
    print_tree_helper(t->root, 0);
    puts("");
}

/*********************************
    Main
**********************************/
int main()
{
    int i;
    RBTree rbt;
    rbtree t = rbt.rbtree_create();

    cout << "Red Node is displayed as < >"<< endl << endl;

    //Insert
    for (i = 1; i <= 15; i++)
        {
            //int x = i; //key
            //int y = i; //value
            int x = rand() % 15 + 1; //x in the range 1 to *
            int y = rand() % 15 + 1; //y in the range 1 to *
            //print_tree(t);
            //cout<<"Inserting "<<x<<" -> "<<y<<endl<<endl;
            rbt.rbtree_insert(t, (void*)x, (void*)y, compare_int);
            assert(rbt.rbtree_find(t, (void*)x, compare_int) == (void*)y);
        }
    cout << "RBT after Insertion:" << endl;
    print_tree(t);

    //Delete
    for (i = 2; i <= 5; i++)
        {
            //int x = i;
            int x = rand() % 15 + 1; //y in the range 1 to *
            //print_tree(t);
            cout<<"Deleting key "<<x<<endl;
            rbt.rbtree_delete(t, (void*)x, compare_int);
        }
    //int x = 8; //key
    //rbt.rbtree_delete(t, (void*)x, compare_int);
    //cout<<"Deleting key "<<x<<endl<<endl;
    cout << "RBT after Deletion:" << endl;
    print_tree(t);

    return 0;
}
