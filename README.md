# Longest-Compounded-Word

*//* Problem statement *//*

Write a program that:
1. Reads provided files (Input_01.txt and Input_02.txt) containing alphabetically sorted words list (one
word per line, no spaces, all lower case)
2. Identifies & display below given data in logs/console/output file
              o longest compounded word
              o second longest compounded word
              o time taken to process the input file

*//* Solution *//*

This C++ program utilizes a Trie data structure to find the longest and second longest compounded words within a given input file. Compound words are formed by concatenating two or more smaller words that also exist within the input set.

*//* Prerequisites *//*

1. C++ compiler (e.g., g++)
2. Input text file containing a list of words (e.g., "Input_01.txt")

*//* Usage *//*

1. Compilation:
->Compile the code using a C++ compiler.

2. Execution:
->Run the executable with the input file:
Replace "Input_01.txt" with the path to your desired input file.

*//* Code Structure *//*

1. Node class: Represents a node in the Trie structure.
2. Trie class: Implements Trie operations like insertion, search, and retrieval of prefixes.
3. Solution class: Uses the Trie to find the longest compound words from the input file.
4. main() function: Initializes Solution, builds the Trie, and displays the longest compound words found.

*//* Approach *//*

1. Trie Implementation: The program uses a Trie data structure for efficient word storage and retrieval.
2. Building the Trie: Words from the input file are inserted into the Trie, and prefixes are extracted to identify potential compound words.
3. Compound Word Search: The program then iterates through combinations of words and their suffixes, checking their existence in the Trie to identify the longest compound words.

*//* Design Decisions *//*

1. Trie Structure: The Trie facilitates quick prefix retrieval and word existence checks, optimizing the search for compound words.
2. Queue Usage: A deque (double-ended queue) is employed to manage word combinations efficiently during the search process.
