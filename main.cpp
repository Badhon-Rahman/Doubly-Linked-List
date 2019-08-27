#include <iostream>

using namespace std;

typedef struct DoublyListNode{
     int data;
     struct DoublyListNode *previousNode;
     struct DoublyListNode *nextNode;
} *doublyPtr;
doublyPtr head = NULL, currentNode = NULL;

void InsertData(int item){
        doublyPtr newNode = new DoublyListNode;
        newNode->data = item;
        if(head == NULL){
            newNode->previousNode = NULL;
            newNode->nextNode = NULL;
            head = newNode;
            currentNode = head;
        }
        else{
            newNode->previousNode = currentNode;
            newNode->nextNode = NULL;
            currentNode->nextNode = newNode;
            currentNode = newNode;
        }
}

void DisplayLinkedList(){
          doublyPtr SPtr = head;
          if(SPtr == NULL){
            cout << "List is Empty!!!" << endl;
          }
          else{
            cout << "Doubly Listed Data: ";
            while(SPtr != NULL){
              cout << SPtr->data << " ";
              SPtr = SPtr->nextNode;
            }
            cout << endl;
          }
}

void InsertBegin(int firstData){
        doublyPtr newNode = new DoublyListNode;
        newNode->data = firstData;
        newNode->nextNode = head;
        newNode->previousNode = NULL;
        head->previousNode = newNode;
        head = newNode;
}

void InsertAnyWereList(int midData, int des){
           doublyPtr desPtr = head;
           doublyPtr newNode = new DoublyListNode;
           newNode->data = midData;
           while(desPtr->data != des && desPtr->nextNode != NULL){
             desPtr = desPtr->nextNode;
           }
           if(desPtr->nextNode != NULL){
              newNode->nextNode = desPtr->nextNode;
              newNode->previousNode = desPtr;
              desPtr->nextNode->previousNode = newNode;
              desPtr->nextNode = newNode;
           }
           else{
            cout << "Insert in middle was  not successful." << endl;
           }
}

void DeleteFirstElement(){
       doublyPtr deletePtr = head;
       if(deletePtr == NULL){
        cout << "LIst is Empty!!!" << endl;
       }
       else{
         head->nextNode->previousNode = NULL;
         head = head->nextNode;
         delete(deletePtr);
       }
}

void DeleteLastElement(){
       doublyPtr deletePtr = currentNode;
       if(head == NULL){
        cout << "List is Empty." << endl;
       }
       else{
          currentNode = currentNode->previousNode;
          currentNode->nextNode = NULL;
          delete(deletePtr);
       }
}

void DeleteMiddle(int deleteMid){
         doublyPtr deletePtr = head;
         if(deletePtr == NULL){
          cout << "List is Empty." << endl;
         }
         else{
            while(deletePtr->data != deleteMid && deletePtr->nextNode!= NULL){
                deletePtr = deletePtr->nextNode;
            }
            if(deletePtr->data == deleteMid && deletePtr->nextNode != NULL && deletePtr->previousNode != NULL){
                 deletePtr->previousNode->nextNode = deletePtr->nextNode;
                 deletePtr->nextNode->previousNode = deletePtr->previousNode;
                 delete(deletePtr);
            }
            else{
                cout << "Delete from Middle is not Possible." << endl;
            }
         }
}

void SearchListItem(int item){
         doublyPtr searchPtr = head;
         if(searchPtr == NULL){
            cout << "List is Empty!!!" << endl;
         }
         else{
           while(searchPtr->data != item && searchPtr->nextNode != NULL){
                 searchPtr = searchPtr->nextNode;
           }
        if(searchPtr->data == item){
              cout << "Data found." << searchPtr->data << endl;
           }
        else{
            cout << "Data Not Found!!!" << endl;
           }
         }
}

int main()
{
     int choice;

    do{
        cout << "Enter 1 add to the linkedList." << endl;
        cout << "Enter 2 to add first of the linkedList." << endl;
        cout << "Enter 3 to add Middle of the linkedList." << endl;
        cout << "Enter 4 delete first element." << endl;
        cout << "Enter 5 to delete last element." << endl;
        cout << "Enter 6 to delete from middle element of the linkedList." << endl;
        cout << "Enter 7 to search a linkedList element." << endl;
        cout << "Enter 8 to display the Linked List." << endl;
        cout << "Enter 9 to exit the program." << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:{
               int listData;
               cout << "Enter Data to insert in linked list:" ;
               cin >> listData;
               InsertData(listData);
               break;
            }
           case 2:{
              int insertFirst;
              cout << "Enter data to insert at first of the list:";
              cin >> insertFirst;
              InsertBegin(insertFirst);
              break;
            }
            case 3:{
              int insertAnywhere, des;
              cout << "Enter to insert anywhere in list: ";
              cin >> insertAnywhere;
              cout << "Enter desired destination: ";
              cin >> des;
              InsertAnyWereList(insertAnywhere, des);
              break;
            }
              case 4:{
              DeleteFirstElement();
              break;
            }
            case 5:{
              DeleteLastElement();
              break;
            }
            case 6:{
              int deleteMid;
              cout << "Enter delete data:";
              cin >> deleteMid;
              DeleteMiddle(deleteMid);
              break;
            }
            case 7:{
              int item;
              cout << "Enter Item to search in list: ";
              cin >> item;
              SearchListItem(item);
              break;
            }
            case 8:{
              DisplayLinkedList();
              break;
            }
            case 9:{
              cout << "Program End." << endl;
              break;
            }
            default:{
              cout << "You Entered the wrong choice!!! Chose from listed numbers." << endl;
            }
        }

    }while(choice != 9);
    return 0;
}
