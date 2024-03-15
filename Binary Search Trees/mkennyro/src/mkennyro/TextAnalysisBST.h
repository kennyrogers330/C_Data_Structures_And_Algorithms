#ifndef ASSIGNMENT3_H
#define ASSIGNMENT3_H
using namespace std;
#include <string>

struct node {
    string word;
    int count;
    node *left;
    node *right;
    node(const string& val) : word(val), count(1), left(nullptr), right(nullptr) {}
};

struct probes {
    int probe;
    probes *next;
    probes(int val): probe(val), next(nullptr){}
};

node* insertNode(node* root, const string& value);
int getLevelFn(node* root, const string& word, int level);
int getLevel(node* root, const string& word);
int treeHeight(node* root);
int searchNode(node* root, const string& word);
probes* add_probe_at_end(probes* head, int probe);
void Determineprobes(node* root, node* ptr, probes** head);
double getProbesAverage(probes* head);
void inOrder(node* root, node* ptr, ofstream& outFile);
string removeAfterApostrophe(string word);

#endif