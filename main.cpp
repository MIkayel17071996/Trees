#include "Bst.h"
#include "Avl.h"
#include "Tree.h"
#include "RB-Tree.h"

int main()
{
   Avl<int> bs;
   for (int i = 0; i < 10; ++i)
   {
      bs.insert(i + 10);
   }

   std::cout << "Inorder Traversal : ";
   bs.inOrderTraversal();
   std::cout << std::endl;

   std::cout << "PreOrder Traversal : ";
   bs.preOrderTraversal();
   std::cout << std::endl;

   std::cout << "PostOrder Traversal : ";
   bs.postOrderTraversal();
   std::cout << std::endl;
}