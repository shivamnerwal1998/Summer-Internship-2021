
#include<iostream>
using namespace std ;
typedef struct BST{
  int info ;
    struct BST *left ;
    struct BST *right ;
}BST;

void createEmpty( BST **tree)
{
    (*tree) = NULL ;
}
void insertElement( BST **tree , int element)
{
    BST *ptr ;
    ptr = (BST *)malloc( sizeof( BST ) )  ;
    ptr->info = element ;
    ptr->left = NULL ;
    ptr->right = NULL ;

    if( *tree == NULL ) (*tree) = ptr ;
    else{
        BST *parent = (*tree)  ;
        BST *temp = NULL ;
        while( parent != NULL )
        {
            temp =  parent ;
            if( parent->info < element )
                parent = parent->right ;
            else parent = parent->left ;
        }
        if( element > (temp->info) ) temp->right = ptr ;
        else    temp->left = ptr ;

    }

}
BST *findMin( BST *tree ){

    while( tree->left != NULL  )
    {
        tree = tree->left ;
    }
    return tree ;

} ;

// level order traversal of binary search tree

void level_Order_Traversal( BST *tree )
{
    if( tree == NULL ) return ;
    queue <BST *> Q ;
    Q.push( tree );
    Q.push(NULL) ;
    while( Q.empty()== false ){
        BST *node = Q.front();
        cout<< node->info <<"\t" ;
        Q.pop();
        if( node->left != NULL )
            Q.push( node->left ) ;
        if( node->right != NULL )
            Q.push( node->right );
    }

}

void deleteNode( BST **tree , int element)
{
    if( *tree == NULL  ){
        cout << "Empty" ;
        getchar();
    }
    else
    {
        if( (*tree)->info > element )
        deleteNode( &( (*tree)->left ) , element  ) ;
        else if( (*tree)->info < element )
        deleteNode((&(*tree)->right),element) ;
        else
        {
            BST *ptr ;
            if( (*tree)->left == NULL ) {
                ptr = (*tree) ;
                (*tree) = (*tree)->right ;
                free(ptr) ;
                ptr = NULL ;

            }
            else if( (*tree)->right == NULL)
            {
                ptr = (*tree) ;
                (*tree) = (*tree)->left ;
                free(ptr) ;
                ptr = NULL ;
            }
            else
            {
                BST *temp  = (*tree)->right ;
                temp = findMin( temp ) ;
                (*tree)->info = temp->info ;
                deleteNode( &( (*tree)->right ) , temp->info ) ;


            }



        }

    }
}

void inOrderTraversal( BST *tree )
{
    if( tree != NULL ){
        inOrderTraversal( tree->left ) ;
        cout << tree->info << "\t" ;
        inOrderTraversal( tree->right ) ;
    }


}
int main()
{
    BST *tree ;
    createEmpty(&tree);
    insertElement(&tree , 10 ) ;
    insertElement(&tree ,  5 )  ;
    insertElement(&tree , 20 ) ;
    insertElement(&tree , 25 ) ;
    insertElement(&tree , 30 ) ;

    inOrderTraversal(tree) ;
    deleteNode(&tree,10) ;
    inOrderTraversal(tree) ;



}
