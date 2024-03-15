/*
 Author: Kenny Roger Munyaneza
 Date: 03/08/2024
 */

 /*
 Format of input and output
 ==========================

 Input: 
 ======

 1. Input File Paths: The program expects an input file named input.txt that contains one or more file paths. Each file path corresponds to a text file that the program will analyze.
 
 2. Text Files: The text files specified in input.txt contain the actual text data that the program will analyze. These text files may contain any textual content, such as sentences, paragraphs, or documents.

 In summary, the input of the program consists of a list of file paths to text files that the program will process and analyze. These text files contain the textual data that forms the basis of the analysis performed by the program.

 Output:
 =======
 
 1. Each section of the output begins with a line containing the file path of the text file being analyzed.

 2. For each text file, the output includes the maximum number of probes required to access a word in the Binary Search Tree (BST) and the average number of probes across all words in the text file. This information gives insight into the efficiency of the BST data structure for storing and retrieving words from the text file.

 3.  Following the probing information, the output lists the unique words found in the text file along with their respective frequencies and the number of probes required to access each word in the BST. 

 4. After processing each text file, a separator line (----------------) is printed to separate the results. 
 
 */

/*

Solution Strategy:
==================

searchNode(root, word):
    if root is null:
        return 0
    
    if root.word equals word:
        return 1
    
    if root.word is less than word:
        return 1 + searchNode(root.right, word)
    
    return 1 + searchNode(root.left, word)

This function recursively searches for a word in a Binary Search Tree (BST). If the word is found at a node, it returns 1. 
If the word is not found, it continues searching either in the left or right subtree, depending on whether the word is greater or less than the word 
stored at the current node. The function counts the number of steps (probes) taken to find the word and returns the total number of probes required.


Determineprobes(root, ptr, head):
    if root is not null:
        Determineprobes(root.left, ptr, head)
        
        // Calculate the height (number of probes) to access the current word in the BST
        height = searchNode(ptr, root.word)
        
        // Add the probe count to the linked list
        add_probe_at_end(head, height)
        
        Determineprobes(root.right, ptr, head)

This function recursively traverses a Binary Search Tree (BST) and determines the number of probes required to access each word in the tree relative to a reference node (ptr). 
It calculates the level (probe count) for each word using the searchNode function and adds the probe count to a linked list using the add_probe_at_end function. 
The linked list (head) stores the probe counts for each word, which are later used to calculate the average number of probes.

treeHeight(root):
    if root is null:
        return 0
    else:
        l_height = treeHeight(root.left)
        r_height = treeHeight(root.right)

        if l_height > r_height:
            return l_height + 1
        else:
            return r_height + 1

This function calculates the height of a Binary Search Tree (BST). If the tree is empty (root is null), the height is 0. Otherwise, it recursively calculates 
the height of the left and right subtrees and returns the maximum height plus 1, accounting for the current level of the root node, which also gives me the maximum 
probe in a given tree


getProbesAverage(head):
    if head is null:
        print "Head still null"
        return 0
    
    sum = 0
    count = 0
    average = 0
    temp = head
    
    while temp is not null:
        sum += temp.probe
        count++
        temp = temp.next
    
    if count is not 0:
        average = sum / count
        print "Average number of probes:", average
    
    return average

This function calculates the average number of probes stored in a linked list of probe counts (head). It iterates through the linked list, summing up the probe 
counts and counting the number of nodes. Then, it calculates the average by dividing the sum by the count. If the count is non-zero, it prints the average number 
of probes. Finally, it returns the calculated average.


*/

/* 

1. I have 8 test cases that check that ensure that comparison between words before insertion into the tree is case insensitive.

example of test: Lorem ipsum dolor sit amet, consectetur adipiscing elit. lorem Ipsum Dolor Sit aMEt, COnsectetur adipIScing eliT.

2. Also, I have a test cases that test that apostrophes are not handled as words.

example of tests: 

- you must love let's dsa
- I've been Testing the program with different input files.

3. I have textfile7 that checks the proper behaviour of the program when the file is empty.

4. Lastly I have a very large file (textfile8) to evaluated performance with large input files to ensure efficient processing

*/

/*

Complexity Analysis of the program:
===================================

1. Reading M path names from the input file would have a time complexity of O(M).

2. For each file, we need to open and read the corresponding file, which would have a time complexity of O(N * W). 

3. Considering the average number of unique words in each file as U. Constructing the BST for each file would have a time complexity of O(U log U).

4. Calculating probes for all nodes would have a time complexity of O(T), assuming each node is visited once.

Total Complexity = O(M) + O(N * W) + O(N * U log U) + O(T)

*/

#include <iostream>
using namespace std;
#include <fstream>
#include <sstream>
#include <cstring> // For strcmp
#include <cctype>
#include "TextAnalysisBST.h"

int main() {
    ifstream fin, file;
    ofstream fout;

    fin.open("../data/input.txt");

    if(!fin.is_open()){
        cout << "Error opening input file!" << endl;
        return 1;
    }

    fout.open("../data/output.txt");
    if (!fout.is_open()) {
        cout << "Error opening output file!" << std::endl;
        return 1;
    }

    fout << "mkennyro" << endl;
    string path;

    while (getline(fin, path)) {
        cout << path << endl;
        fout << path << endl;
        
        file.open(path);

        if(!file.is_open()){
        cout << "Error opening file!" << endl;
        return 1;
        }
        node* root = nullptr;

        string line;
        while(getline(file, line)){  //LOPP FOR CONTENT
            istringstream words(line);
            string word;
            
            while(words >> word){

                word = removeAfterApostrophe(word);

                for(char& c: word ){

                    c = tolower(c);
                }

                root = insertNode(root, word);
            }

        }

        cout << "Maximum number of probes: " << treeHeight(root) << endl;
        fout << "Maximum number of probes: " << treeHeight(root) << endl;
            
            node* ptr = root;
            probes *head = nullptr;

            Determineprobes(root, ptr, &head);    

            double average = getProbesAverage(head);
        
            fout << "Average number of probes:" <<  average << endl;  

             
            
            inOrder(root, ptr, fout);

            fout << "--------------------" << endl;
            root = nullptr;

        file.close();
    }  
    
    fout.close();

    return 0;
}