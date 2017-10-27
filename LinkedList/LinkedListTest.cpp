#include "LinkedList.h"
#include <iostream>

using namespace std;
enum Options{EXIT, INSERT, DELETE, PRINT, SWAP, REVERSE};

Options printMessage(){
  Options op;
  printf("What do you want to do?\n");
  printf("1 - Insert\n2 - Delete\n3 - Print\n4 - Swap\n5 - Reverse\notherwise - Exit\n");
  printf("Enter the needed Operation Number: ");
  scanf("%d", &op);
  return op;
}

int main(){
  int val;
  LinkedList<int> li;
  while(1){
    Options op = printMessage();
    puts("");
    switch(op){
      case INSERT:
        printf("Enter the value to be added: ");
        scanf("%d", &val);
        li.insert(val, li.size());
        printf("-------Number %d was added successfully-------\n", val);
        break;
      case DELETE:
        printf("Enter the value to be deleted: ");
        scanf("%d", &val);
        if(!li.erase(val))  printf("-------%d Not found-------\n", val);
        else  printf("-------%d was deleted successfully-------", val);
        break;
      case PRINT:
        printf("The list in reversed order is:\n");
        li.printReverse(li.begin());
        puts("");
        break;
      case SWAP :
        printf("Enter an index to be swapped with its successor: ");
        scanf("%d", &val);
        if(val<li.size()){
          li.swapNodes(val);
          puts("-------Swapping Done successfully-------");
        }
        else  puts("Invalid index");
        break;
      case REVERSE :
        li.reverse();
        li.printList();
        break;
      default:  return 0;
    }
    puts("\n\n\n");
  }
  return 0;
}
