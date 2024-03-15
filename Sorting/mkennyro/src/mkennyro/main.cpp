/*
 Author: Kenny Roger Munyaneza
 */

/*
 Testing of the program:
 =======================
The code was tested using two test cases; whereby each
test case involves the program reading a scan-path of fixation points
until the fixation point with -1 and -1 for x and y respectively is reached.
 */

 /*
 Functionality of the program
 =============================
 Overview: My approach of sorting the scanpath is by adding the fixation points in an ascending manner such that each fixation point is appended 
 at a point in the linked list where the fixation points in front of it have lower coordinates and the fixation points behind it have higher coordinates. 
 ========
This program is executed starting from the main function. The function starts by reading a file called “input.txt” and reads the
 first line to determine the number of test cases to be run. Once the number of test cases is read, the first outer loop runs for the
 number of iterations equal to the number of test cases. Upon each iteration, the program runs a second loop to read a single scanpath.
 This nested loop checks whether the fixation point read doesn’t have -1, -1 coordinates for x and y and in the alternate case it adds
 the first fixation point as a node to a linked list data structure. On the next iteration the fixation points will be compared to fixation points already in the 
 linked list and will be appended at point where it respects the ascending order of the fixation points in the Linked List. 
 */

 /*
Format of input and output

Input:
======
The input is a list of fixation points that are split into 4 test cases; whereby each test case ends when the (-1, -1) coordinates are read.

Output:
=======
The out put is a list of scanpath equal to the number of test cases in the input file. Scanpaths are separated by ****************
Each scanpath contains sorted fixation points by the x-cordinates, y-cordinates or index. Below is a sample: 

*/

/*
Solution Strategy (pseudo-code)
===============================
1. Open input and output files.
2. Read the number of test cases from the input file.
3. Iterate over each test case:
    a. Initialize a linked list head.
    b. Open the output file in append mode.
    c. Iterate over the scanpath data until encountering (-1, -1).
        i. Read index, x, and y coordinates from the input.
        ii. If encountered (-1, -1), terminate the scanpath.
        iii. Add the node in ascending order based on x, y, and index.
    d. Write the sorted nodes to the output file.
    e. Close the output file.
4. Close the input file.
5. Output "Hello World!".

Pseudo-code: 
============

function AddInAscendingOrder(head, index, x, y):
    new_fp = create new fp_node
    new_fp.index = index
    new_fp.x = x
    new_fp.y = y
    new_fp.link = null
    
    if head is null or x < head.x:
        new_fp.link = head
        head = new_fp
    else if x == head.x and y < head.y:
        new_fp.link = head
        head = new_fp
    else if x == head.x and y == head.y and index < head.index:
        new_fp.link = head
        head = new_fp
    else:
        ptr = head
        while ptr.link is not null and (ptr.link.x < x or (ptr.link.x == x and ptr.link.y < y) or (ptr.link.x == x and ptr.link.y == y and ptr.link.index < index)):
            ptr = ptr.link
        new_fp.link = ptr.link
        ptr.link = new_fp
        
    return head

for each test case:
    open the output file for appending
    initialize head of linked list
    for each scanpath in the test case:
        read index, x, and y from the input file
        if (x, y) is (-1, -1):
            break from the loop
        add the node to the linked list in ascending order using AddInAscendingOrder function
    write the sorted nodes to the output file
    close the output file

 */

 /*
 
 Description of test cases:
 ==========================
 
1. Test case one is a scanpath that contains 11 fixation points that are not sorted. The lowest x-coordinate is -710

2. Test case two is a scanpath that contains 6 fixation points that are not sorted. Some fixation points are expected to be sorted by indices since they are duplicates

3. Test case three is a scanpath that contains 11 fixation points that are not sorted. 

4. Test case four is a scanpath that contains 11 fixation points that are not sorted. They are four duplicated fixation points that will be sorted basing on the y-coordinate

5. Test case five is a scanpath that contains 11 fixation points that are not sorted. They are duplicated fixation points with negative y-coordinates


1 0 0
2 1 1
3 2 2
4 1 1
5 0 0
6 4 4
7 -1 -1
 
*/

/*
 Complexity analysis of the essence of the algorithm
 ====================================================
 My algorithm applies 3 loops as described in the "Functionality of the program" section of this documention; whereby the outer loop
 loops for the number of test cases used, the second loop is nested inside the outer loop and loops thought the input file, and a the 
 third loop is nested inside the second loop and is applied in the function "AddInAscendingOrder" that loops throughout a linked list of 
 fixation points before appending a fixation point read to ensure the current fixation point is appended with respect to the ascending order of fixation points. 
 
    loop thoughout the scanpaths = O(n)
    loopping throughout the fixation points of a scanpath = O(m)
    looping throughout the linked list = O(m) - 1 = O(m)
 
 Answer: - The time complexity is O(n*m^2) 
		 
 */

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
#include "assignment2.h"

int main() {
    ifstream file;// Input file stream
    ofstream fout; // Output file stream
    
     // Open the input file
    file.open("../../data/input.txt");
    if (!file.is_open()) {
        cout << "Error opening file!" << std::endl;
        return 1;
    }

    // Open the output file
    fout.open("../../data/output.txt");
    if (!fout.is_open()) {
        cout << "Error opening output file!" << std::endl;
        return 1;
    }

    // Write my anderwId to the output file
    fout << "mkennyro" << std::endl;
    fout.close();// Close the output file

    std::string data;// String to store each line of input
    if (getline(file, data)) { // Read the number of cases from the input file
        int cases = stoi(data);
        int index, x, y;

        // Iterate over each test case
        for (int i = 0; i < cases; i++){
            struct fp_node* head = (struct fp_node*) malloc(sizeof(struct fp_node));
            head = nullptr;
            fout.open("../../data/output.txt", ios::app);
            cout << "=========" << i << "=============" << endl;

             // Loop to read scanpath data
            for (int n = 0; n < 1000; n++) {
                if (getline(file, data)) {
                    std::istringstream point(data);
                    point >> index >> x >> y;

                     // Check for end of scanpath
                    if (x == -1 && y == -1) {
                            cout << "end of scanpath" << endl;

                             // Pointer to traverse the linked list
                            struct fp_node* ptr = head;

                            // Loop through the sorted fixation points and write them the output file
                            while(ptr != nullptr){
                                fout << ptr->index << " " << ptr->x << " " << ptr->y << endl;
                                ptr = ptr->link;                            
                            }
                            fout << "**********" << endl;
                            fout.close(); // Close the output file
                            
                            break;
                        }
                    
                    // Add the node to the linked list in ascending order
                    head = AddInAscendingOrder(head, index, x, y);
                }                
            }
       }
    }
  
  return 0; // Exit the program with success status
}