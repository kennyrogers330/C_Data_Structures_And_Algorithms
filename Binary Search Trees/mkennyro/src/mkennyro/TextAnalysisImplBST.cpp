#include "TextAnalysisBST.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <cstring> // For strcmp
#include <cctype>

node* insertNode(node* root, const string& value){
    if(root == nullptr)
        return new node(value);
    
    if(value == root->word){
        root->count +=1;
        return root;
    }

    if(value < root->word)
        root->left = insertNode(root->left, value);
    else if(value > root->word)
        root->right = insertNode(root->right, value);

    return root;
}

int getLevelFn(node* root, const string& word, int level){
    
    if(root == nullptr)
    {
        // cout << "The root is null" << endl;
        return 0;
    }
    
    if (root->word == word)
    {
        return level;
    }

    // return 15;
    int nextLevel = getLevelFn(root->left, word, level + 1);

    if(nextLevel != 0){
        // cout << "found at level" << nextLevel << endl;
        return nextLevel;
    }

    nextLevel = getLevelFn(root->right, word, level + 1);
    return nextLevel;

    // return 15;
}

int getLevel(node* root, const string& word)
{
    return getLevelFn(root, word, 0);
}

int treeHeight(node* root){
    if(root == nullptr){
        return 0;
    }
    else {
        int l_height = treeHeight(root->left);
        int r_height = treeHeight(root->right);

        if(l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
}

int searchNode(node* root, const string& word){
    
    if(root == nullptr)
        return 0;

    if(root->word == word)
        return 1;  

    if(root->word < word)
        return 1 + searchNode(root->right, word);

    return 1 + searchNode(root->left, word);
} 

probes* add_probe_at_end(probes* head, int probe) {

    probes* newNode = new probes(probe);

    if(head == nullptr){
        return newNode;      
    }
    
    probes* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void Determineprobes(node* root, node* ptr, probes** head) { 
    
    if(root != nullptr){
        Determineprobes(root->left, ptr, head);
        // cout << root->word << "\t" << root->count << "\t" << "(" << getLevel(ptr, root->word) << ")" << endl;

        int height = searchNode(ptr, root->word);
        *head = add_probe_at_end(*head, height);

        Determineprobes(root->right, ptr, head);
    }
}

double getProbesAverage(probes* head) {

    if (head == nullptr){
        cout << "Head still null" << endl;
        return 0;
    }      
       
    int sum = 0;
    int count = 0;
    double average = 0;
    probes* temp = head;
    while (temp != nullptr) {
        sum += temp->probe;
        count++;  
        temp = temp->next;
    }

    if(count !=0 ) {
        average = static_cast<double>(sum) / count;
        cout << "Average number of probes:" <<  average << endl;  
    } 
    return average;            
    
}

void inOrder(node* root, node* ptr, ofstream& outFile) {     
    
    if(root != nullptr){
        inOrder(root->left, ptr, outFile);
        cout << root->word << " " << root->count << " " << "(" << getLevel(ptr, root->word) << ")" << endl;
        outFile << root->word << " " << root->count << " " << "(" << getLevel(ptr, root->word) << ")" << endl;
        inOrder(root->right, ptr, outFile);
    }
}

string removeAfterApostrophe(string word) {
    size_t pos = word.find('\'');
    if (pos != string::npos) {
        // Apostrophe found, truncate the word
        word = word.substr(0, pos);
    }
    return word;
}