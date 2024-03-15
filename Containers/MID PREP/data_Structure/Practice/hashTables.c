/**
 * @author: Jeremie
 * @date  : 12,09,2021
 * @title : HASHING IMPLEMENTATION
 */ 

// preprocessor
#include<stdio.h>
#include<stdlib.h>

/**
 * Hash Table is a data structure which stores data in an associative manner. 
 * In a hash table, data is stored in an array format, where each data value 
 * has its own unique index value. Access of data becomes very fast if we know 
 * the index of the desired data
 */ 

// structure  definition

struct hashTable{
    int key;
    int data;
};

// we define size of our hashtable array
#define MAX 30
struct hashTable *hashArray[MAX];


int hashCode(int key){
    return key % MAX;
}

void insertData(int index,int value){
    struct hashTable *newItem = (struct hashTable*)malloc(sizeof(struct hashTable));
    newItem->key = index;
    newItem->data = value;

    // we need to get hashIndex generated from hashcode function
    int hashIndex = hashCode(index);
    // data will be inserted at the end of array or in an empty cell where has deleted or
    while(hashArray[hashIndex] !=NULL && hashArray[hashIndex]->key != -1){
        // we move to next cell in hash table
        ++hashIndex;
        hashIndex %= MAX;
    }

    // after reaching to empty cell or deleted cell then we insert

    hashArray[hashIndex] = newItem;
    printf("New Item added successful!\n");
}

void searchIntoHashTable(int indexToSearch){
    // we generate hash index depend on indexToSearch
    int hashIndex = hashCode(indexToSearch);
    // we will traversal through our array to the end
    while(hashArray[hashIndex] != NULL){
        if(hashArray[hashIndex]->key == indexToSearch){
            printf("at Index %d Data found IS : %d\n\n",hashArray[hashIndex]->key,hashArray[hashIndex]->data);
            return;
        }
        // otherwise
        // we move to next cell
        ++hashIndex;
        hashIndex %=MAX;
    }
    printf("OopS!! No value at that index in hash Tables\n\n");
}

void deleteElement(int indexToDelete){
    // get hashIndex
    int hashIndex = hashCode(indexToDelete);
    // traverse to the end of array
    while(hashArray[hashIndex] !=NULL) {
        if(hashArray[hashIndex]->key == indexToDelete) {
            hashArray[hashIndex]->data = 0;
            hashArray[hashIndex]->key = 0;
            printf("data deleted successful");
            return;
        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= MAX;
    }
    printf("No data at given index!!\n\n");

}

// still implementing th display function
void display(){
    int hashIndex = hashCode(1);
    while(hashArray[hashIndex] !=NULL){
        if(hashArray[hashIndex]->data == 0){
            printf("No Data at this index!!");
        }else{
            printf("Key: %d Value: %d\n",hashArray[hashIndex]->key,hashArray[hashIndex]->data);
        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= MAX;
    }
}


int main(){
    int choice,index,data;
    while(1){
        start:
        printf("=========================\n");
        printf("1. InsertData\n");
        printf("2. Delete Data\n");
        printf("3. Search Data\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("---------------------\nType: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter index do you wish to insert: ");
            scanf("%d",&index);
            printf("Enter value to insert: ");
            scanf("%d",&data);
            insertData(index,data);
            break;
        case 2:
            printf("Enter index do you wish to Delete: ");
            scanf("%d",&index);
            deleteElement(index);
            break;
        case 3:
            printf("Enter index do you wish to Search from: ");
            scanf("%d",&index);
            searchIntoHashTable(index);
            break;
        case 4:
            display();
            printf("\n\nDONE!!\n");
            break;
        case 5:
            printf("Thank You for using the sysystem!!\n");
            exit(1);
            break;

        default:
            printf("Oops!! Worng input!!\n");
            goto start;
            break;
        }
    }

}