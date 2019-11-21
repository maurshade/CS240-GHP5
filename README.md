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
