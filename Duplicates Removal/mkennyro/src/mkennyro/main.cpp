/*
 Author: Kenny Roger Munyaneza
 */

/*
 Testing of the program:
 =======================
The code was tested using four test cases; whereby each
 test case involves the program reading a scan-path of fixation points
 until the fixation point with -1 and -1 for x and y respectively is reached.
 */

/*
 Functionality of the program
 =============================
This program is executed starting from the main function. The function starts by reading a file called “input.txt” and reads the
 first line to determine the number of test cases to be run. Once the number of test cases is read, the first outer loop runs for the
 number of iterations equal to the number of test cases. Upon each iteration, the program runs a second loop to read a single scanpath.
 The first nested loop checks whether the fixation point read doesn’t have -1, -1 coordinates for x and y and in the alternate case it adds
 the first fixation point as a node to a linked list data structure  and writes the first fixation point to a file. The second nested loop reads the whole scanpath
 until -1, -1 coordinates for x and y are reached. Inside this loop, another nested loop is run throughout the linked list data structure and compares each
 value in the linked list against the read fixation point. If the fixation point is not already existing in the linked list, a node capturing the index, x, and y coordinates 
 will be added at the end of the linke list data structure and written to the output file. This process will be repeated for all scanpaths in the file and once the end of the file is reached,
 the program ends.

 */

/*
Format of input and output

Input:
======
The input is a list of fixation points that are split into 4 test cases; whereby each test case ends when the (-1, -1) coordinates are read.

Output:
=======
The out put is a list of scanpath equal to the number of test cases in the input file. Scanpaths are separated by ****************
Each scanpath contains unique fixation points, no duplicates. Below is a sample: 

mkennyro
1 382 353
2 484 328
3 695 241
4 715 242
5 710 245
**********
1 0 0
2 1 1
3 2 2
4 4 4
**********

*/

/*
Solution Strategy (pseudo-code)
===============================

file = open("../../data/input.txt", "r");

output = open("../../data/output.txt", "w");

if output is not null:
	writeln(output, "mkennyro");
	close(output);
else:
	print("Error: Unable to open the file for writting");

if file is not null:

  scanpaths = readline(file);

  for every scanpath in scanpaths:
	output = open("../../data/output.txt", "a")
	vector f_points;

	fix_point = readline(file);
	f_points.push(fix_point);
	writeln(output, fix_point);

	while fix_point is not End_of_scanpath
		for every point in f_points:
			if point != fix_point:
				f_points.push(fix_point);
				writeln(output, fix_point);
			else:
				break;
		fix_point = readline(file);
	close(output);
  close(file)
else:
	print("Error: Unable to open the file in read mode");

 */

 /*
 
 Description of test cases:
 ==========================
 
 1. Test case one is a scanpath that contains 5 duplicates in 10 fixation points. 
 2. Test case two is a scanpath that contains 7 duplicates in 13 fixation points. 
 3. Test case two is a scanpath that contains 3 duplicates in 7 fixation points. 
 4. Test case four is a scanpath that contains 995 duplicates in 1000 fixation points.
 
 */

 /*
 Complexity analysis of the essence of the algorithm
 ====================================================
 My algorithm applies 3 loops as described in the "Functionality of the program" section of this documention; whereby the outer loop
 loops for the number of test cases used, the second loop is nested inside the outer loop and loops thought the input file, and a the 
 third loop is nested inside the second loop and is applied in the function "append node" that loops throughout a linked list of 
 fixation points before appending a fixation point read to ensure the current fixation point is not already existing. 

 Answer: - The time complexity is O(n*m*k)
		 
 */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Include the header file
#include "list_man.h"


// Main function of the program
int main() {
    std::ifstream file;
    std::ofstream fout;

    // open the input file
    file.open("../../data/input.txt");
    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }

    // Open the out put file
    fout.open("../../data/output.txt");
    if (!fout.is_open()) {
        std::cout << "Error opening output file!" << std::endl;
        return 1;
    }

    fout << "mkennyro" << std::endl;
    fout.close();

    std::string data;
    if (getline(file, data)) {
        int cases = std::stoi(data);
        int index, x, y;

        // The outer loop the loops for the number of test cases given
        for (int i = 0; i < cases; i++) {
            struct fp_node* head = new struct fp_node;

            int counter = 1;

            fout.open("../../data/output.txt", std::ios::app);

            // First inner Loop that reads the first fixation point and adds it as the first node of the fixation points linked list
            while (getline(file, data)) {
                std::istringstream line1(data);

                line1 >> index >> x >> y;

                if (x == -1 && y == -1) {
                    break;
                }

                head->index = index;
                head->x = x;
                head->y = y;
                head->link = nullptr;

                struct fp_node* ptr = head;

                std::string val = std::to_string(x) + ' ' + std::to_string(y);

                fout << counter << " " << head->x << " " << head->y << std::endl;

                break;
            }
            // Second inner Loop that reads the whole fixation points and append them to the fixation points linked list
            for (int n = 0; n < 1000; n++) {
                if (getline(file, data)) {
                    std::istringstream point(data);

                    point >> index >> x >> y;

                    if (x == -1 && y == -1) {
                        fout << "**********" << std::endl;
                        break;
                    }

                    // Appending fixation points to the linked list
                    bool nodupl = append_node(head, index, x, y);

                    std::string val;

                    if (nodupl) {
                        fout << counter + 1 << " " << x << " " << y << std::endl;
                        counter++;
                    }
                } else {
                    std::cout << "end of file" << std::endl;
                }
            }
            fout.close();
        }

    } else {
        std::cout << "File is empty." << std::endl;
    }
    file.close();
    return 0;
}