/*
* CS 240, GHP 5
*
*
* Alternate Assignment (maximum 60 points)
*
* Modify the basic assignment so it queries the user for the name of a file containing one word
* per line. Open that file, process each word using basic stack and queue operations to determine
* if it is a palindrome, and if so, print it. At the end report the total number of palindromes
* found and the total number of words processed. Test your program on the dictionary file shown
* on Blackboard. Consider one letter words (e.g., I or a) to be a palindrome.
*
* The dictionary file can be found on the CS fileserver (gaben):   /usr/share/dict/american-english
*
* It contains 102305 words so your program should report that 102305 words were processed.
*
* 1. Introduce program to the user
* 2. Ask user for dictionary filename
* 3. Open file and validate that it is open
* 4. Import word from file (looping)
* 5. 5. Ensure letters are all lower case and push character onto stack
* 6. at the same time, push the word on to a queue
* 7. Remove letters off stack and queue one at a time.
* 7a. if the letters don't match, it is not a palindrome. Set the bool
* 7b. 7b. if all the letters match, it is a palindrome.  Set the bool, display word, and increase the counter.
* 8. After all words are compared, report the number of words and palindromes.
* 9. Terminate program
*
* Written by Sean Patterson with lifesaving help and a large chunk of code from Ron.
* Using Code::Blocks IDE and G++ compiler on Windows 10.
* November 13, 2019
*
*/

#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <cassert>
#include <fstream>

using namespace std;

int main(void)
{
    string inputFileName;   // define variables for words and ADTs for stack and queue using STL
    string word;            //
    stack <char> s;         //
    queue <char> q;         //
    ifstream fileIn;        // file stream
    bool palindrome = 1;    //
    int i = 0,              // counters
        wordLength = 0,     //
        palCount = 0,       //
        wordCount = 0;      //

//1. Introduce program to the user

    cout << "This program will open the dictionary file specified and check all word to determine if they are palindromes."  << endl;
    cout << "For the purpose of this program, one letter words are counted as palindromes." << endl << endl;


//2. Ask user for dictionary filename
    cout << "Please enter the name of the dictionary file to open: ";
    cin >> inputFileName;

//3. Open file and validate that it is open
    fileIn.open(inputFileName.data());
    assert(fileIn.is_open());
    cout<<"\nFile "<<inputFileName<<" successfully opened.\n"<<endl;

    cout <<"The following words are palindromes:" << endl << endl;

//4. Import word from file (looping)
    while((fileIn.good()))
    {
//        if (!(fileIn.eof()))
            fileIn >> word;
            if (fileIn.eof()) break;    //kill loop if eof is read
        wordCount++;
        palindrome = 1;                 //reinitialize palindrome counter

    wordLength = word.length();         //word length for loop

//5. Ensure letters are all lower case and push character onto stack
//6. at the same time, push the word on to a queue
    for ( i=0; i<wordLength; i++)
    {
        s.push(tolower(word[i]));
        q.push(tolower(word[i]));
    }

// 7. Remove letters off stack and queue one at a time.
// 7a. if the letters don't match, it is not a palindrome, set bool

    while(!(s.empty()) && !(q.empty()))
    {
        if(s.top() != q.front())
        {
            palindrome = 0;

        }
    s.pop();
    q.pop();

    }

//7b. if all the letters match, it is a palindrome.  Set the bool, display word, and increase the counter.
    if(palindrome == 1)
    {
        cout << word << endl ;
        palCount++;

    }
    }
//8. After all words are compared, report the number of words and palindromes.
    cout << endl << "The file contained " << wordCount << " words and " << palCount << " palindromes." << endl << endl;

//9. Terminate program
    return 0;
}
