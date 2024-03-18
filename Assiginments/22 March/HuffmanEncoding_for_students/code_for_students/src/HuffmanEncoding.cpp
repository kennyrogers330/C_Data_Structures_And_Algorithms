/*
 *  Created on: March 16, 2024
 *      Author: Kenny Roger
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include "HuffmanEncoding.h"

using namespace std;
const int MAX_CHARACTERS = 128;

// void HuffmanEncoding::generateAlphabetCode(char* trainFilePath, char* resultFilePath){

// }

// void HuffmanEncoding::encodeText(char* testASCIIFilePath, char* huffmanCodeFilePath, char* resultFilePath){

// }

// void HuffmanEncoding::decodeText(char* testEncodedFilePath, char* huffmanCodeFilePath, char* resultFilePath){

// }

// Structure to represent a node in Huffman Tree
struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct HuffmanNode {
    char character;
    string code;
};

// Function to create a new node
Node* createNode(char data, int freq) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
}

void minHeapify(Node* arr[], int size, int i){
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && arr[left]->freq < arr[smallest]->freq) {
        smallest = left;
    }

    if (right < size && arr[right]->freq < arr[smallest]->freq) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        minHeapify(arr, size, smallest);
    }

}

// Function to extract minimum element from heap
Node* extractMin(Node* arr[], int& size) {
    Node* minNode = arr[0];
    arr[0] = arr[size - 1];
    size--;
    minHeapify(arr, size, 0);
    return minNode;
}

Node* buildHuffmanTree(int frequency[]){
    const int capacity = 128; // Capacity for ASCII characters
    Node* heapArray[capacity]; // Array to store nodes

    // Create leaf nodes for characters with non-zero frequency
    int heapSize = 0;
    for (int i = 0; i < capacity; ++i) {
        if (frequency[i] > 0) {
            heapArray[heapSize++] = createNode(static_cast<char>(i), frequency[i]);
        }
    }

     // Construct Binary Heap Array
    for (int i = (heapSize - 1) / 2; i >= 0; --i) {
        minHeapify(heapArray, heapSize, i);
    }

    // Build Huffman Tree
    while (heapSize > 1) {
        Node* left = extractMin(heapArray, heapSize);
        Node* right = extractMin(heapArray, heapSize);

        Node* parent = createNode('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        heapArray[heapSize++] = parent;
        minHeapify(heapArray, heapSize, heapSize - 1);
    }

    return heapArray[0];
}

void calcFrequency(char* trainFilePath, int frequency[]) {
    // Open input file
    FILE* trainFile = fopen(trainFilePath, "r");
    if (trainFile == nullptr) {
        cerr << "Error opening file " << trainFilePath << endl;
        exit(1);
    }

    char c;

    while (fscanf(trainFile, "%c", &c) != EOF) {
        // Update frequency array
        if (static_cast<unsigned char>(c) <= 127) {
            frequency[static_cast<unsigned char>(c)]++;
        }
        // Also count spaces and line breaks
        else if (c == ' ' || c == '\n') {
            frequency[static_cast<unsigned char>(c)]++;
        }
    }

    // Close the input file
    fclose(trainFile);
}

int calculateTotalCharacters(int frequency[]){
    int totalChars = 0;
    // Print the computed frequencies
    for (int i = 0; i < 128; ++i) { // Only ASCII characters
        // if (frequency[i] > 0) {
        //     cout << "Character: " << static_cast<char>(i) << ", Frequency: " << frequency[i] << endl;
        // }
        totalChars += frequency[i];
    }
    return totalChars;
}

// Function to free memory allocated for Huffman Tree nodes
void freeHuffmanTree(Node* root) {
    if (root == nullptr) return;

    // Recursively free memory for left and right subtrees
    freeHuffmanTree(root->left);
    freeHuffmanTree(root->right);

    // Free memory for the current node
    delete root;
}

// Function to generate Huffman codes with probabilities and output to a file
void generateHuffmanCodes(Node* root, string code, double totalChars, ofstream& outFile) {
    if (root == nullptr) return;

    // Leaf node: print character, probability, and code
    if (root->left == nullptr && root->right == nullptr) {
        // Handle space and newline characters differently
        if (root->data == ' ') {
            double probability = static_cast<double>(root->freq) / totalChars;
            
            /*
           1. space \\s will be represented as '*' 
           2. Line break \\n will be represented as '/'
            */
            
            outFile << "*" << " " << probability << " " << code << endl; // Represent space character
        } else if (root->data == '\n') {
            double probability = static_cast<double>(root->freq) / totalChars;
            outFile << "/" << " " << probability << " " << code << endl; // Represent newline character
        } else {
            double probability = static_cast<double>(root->freq) / totalChars;
            outFile << root->data << " " << probability << " " << code << endl;
        }
        return;
    }

    // Traverse left subtree with code "0"
    generateHuffmanCodes(root->left, code + "0", totalChars, outFile);

    // Traverse right subtree with code "1"
    generateHuffmanCodes(root->right, code + "1", totalChars, outFile);
}

// Function to generate Huffman codes for the characters in the training file
void HuffmanEncoding::generateAlphabetCode(char* trainFilePath, char* resultFilePath) {
 
    // Initialize frequency array
    int frequency[128] = {0}; // Assuming all characters are ASCII

    // Calculate character frequencies from the input file
    calcFrequency(trainFilePath, frequency);

    // Compute total number of characters
    int totalChars = calculateTotalCharacters(frequency);

    // Construct Huffman Tree
    Node* root = buildHuffmanTree(frequency);

    // Open the output file for writing
    ofstream outputFile(resultFilePath);

    // Generate Huffman codes recursively starting from the root
    generateHuffmanCodes(root, "", totalChars, outputFile);

    // Close the output file
    outputFile.close();

    // Free memory allocated for Huffman Tree nodes
    freeHuffmanTree(root);
}

// Function to read Huffman codes from file and store them in an array
void readHuffmanCodesForEncoding(const char* huffmanCodeFilePath, HuffmanNode huffmanCodes[]) {
    ifstream huffmanCodeFile(huffmanCodeFilePath);
    if (!huffmanCodeFile.is_open()) {
        cerr << "Error opening Huffman code file: " << huffmanCodeFilePath << endl;
        return;
    }

    char character;
    string probability, code;
    int index = 0;
    
    // while (huffmanCodeFile >> character >> probability >> code) {          
    //     // cout << character << " " << code << endl;        
    //     huffmanCodes[index++] = {character, code};
    // }

    while (huffmanCodeFile >> character) {
        // Read the rest of the line into probability and code strings
        huffmanCodeFile >> probability >> code;
        
        // cout << character << " " << code << endl;        
        huffmanCodes[index++] = {character, code};
    }

    huffmanCodeFile.close();
}

void readHuffmanCodesForDecoding(const char* huffmanCodeFilePath, HuffmanNode huffmanCodes[]) {
    ifstream huffmanCodeFile(huffmanCodeFilePath);
    if (!huffmanCodeFile.is_open()) {
        cerr << "Error opening Huffman code file: " << huffmanCodeFilePath << endl;
        return;
    }

    char character;
    string probability, code;
    while (huffmanCodeFile >> character >> probability >> code) {
        huffmanCodes[static_cast<int>(character)].character = character;
        huffmanCodes[static_cast<int>(character)].code = code;
        // cout << character << " " << code << endl;  
    }
    huffmanCodeFile.close();
}



void HuffmanEncoding::encodeText(char* testASCIIFilePath, char* huffmanCodeFilePath, char* resultFilePath) {
    // Step 1: Read Huffman codes from the input file
    HuffmanNode huffmanCodes[MAX_CHARACTERS];
    readHuffmanCodesForEncoding(huffmanCodeFilePath, huffmanCodes);

    // Step 2: Open the input and output files
    ifstream inputFile(testASCIIFilePath);
    ofstream outputFile(resultFilePath);
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening input or output file" << endl;
        return;
    }

    // Step 3: Encode characters and write encoded binary values to output file
    char character;
    while (inputFile.get(character)) {
        // Find the Huffman code for the current character
        for (int i = 0; i < MAX_CHARACTERS; ++i) {
            
            if (huffmanCodes[i].character == character) {
                // Write the Huffman code to the output file
                outputFile << huffmanCodes[i].code;
                break;
            }
            else if(character == ' '){
                // cout << huffmanCodes[0].code << endl;
                outputFile << huffmanCodes[0].code;
                break;
            }else if(character == '\n'){
                outputFile << huffmanCodes[20].code;
                break;
                // cout << huffmanCodes[20].code << endl;
            }
        }        
    }

     // Step 4: Close the input and output files
    inputFile.close();
    outputFile.close();
}

void HuffmanEncoding::decodeText(char* testEncodedFilePath, char* huffmanCodeFilePath, char* resultFilePath){
    // Step 1: Read Huffman codes from the input file
    HuffmanNode huffmanCodes[MAX_CHARACTERS];
    readHuffmanCodesForDecoding(huffmanCodeFilePath, huffmanCodes);

    // Step 2: Read the encoded text
    ifstream encodedFile(testEncodedFilePath);
    if (!encodedFile.is_open()) {
        cerr << "Error opening encoded text file: " << testEncodedFilePath << endl;
        return;
    }

    // Step 3: Decode the encoded text using Huffman codes
    string encodedText, decodedText;
    encodedFile >> encodedText;
    encodedFile.close();

    string currentCode;
    for (char c : encodedText) {
        currentCode += c;
        for (int i = 0; i < MAX_CHARACTERS; ++i) {
            if (huffmanCodes[i].code == currentCode) {
                if(huffmanCodes[i].character == '*'){
                    decodedText += ' ';
                }else if(huffmanCodes[i].character == '/'){
                    decodedText += '\n';
                }
                else{
                    decodedText += huffmanCodes[i].character;
                }                 
                currentCode = "";
                break;
            }
        }
    }

    // Step 4: Write the decoded text to the result file
    ofstream resultFile(resultFilePath);
    if (!resultFile.is_open()) {
        cerr << "Error opening result file: " << resultFilePath << endl;
        return;
    }
    resultFile << decodedText;
    resultFile.close();

}

int main() {
    char trainFilePath[] = "./../data/train_student_sample.txt";
    
    char resultFilePath[] = "./../data/in.txt.huffman.txt";

    // HuffmanEncoding::generateAlphabetCode(trainFilePath, resultFilePath);
    HuffmanEncoding::generateAlphabetCode(trainFilePath, resultFilePath);

    char huffmanCodeFilePath[] =  "./../data/in.txt.huffman.txt";
    char testASCIIFilePath[] = "./../data/test_student_sample_1.txt";
    char encodeResultFilePath[] = "./../data/test.txt.encode.txt";

    HuffmanEncoding::encodeText(testASCIIFilePath, huffmanCodeFilePath, encodeResultFilePath);

    char testEncodedFilePath[] = "./../data/test.txt.encode.txt";
    char decodedResultFilePath[] = "./../data/encoded.txt.ascii.txt";
    
   HuffmanEncoding::decodeText(testEncodedFilePath, huffmanCodeFilePath, decodedResultFilePath);

    return 0;
}
