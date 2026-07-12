## Problem to Solve

For this problem, you'll implement a program that spell-checks a file, using a hash table, as fast as you possibly can. 

In a file called `dictionary.c` in a folder called `speller`, you will write the underlying logic to load a massive dictionary of words into a hash table in memory, and then check whether individual words from a text file exist in that dictionary.

This is famously one of the most challenging (and rewarding!) problem sets in CS50. You'll need to design a good hash function and carefully manage memory allocation and pointers.

*For the full background on hash tables, pointers, and a detailed walkthrough, read the official instructions here: [CS50 Speller Instructions](https://cs50.harvard.edu/x/psets/5/speller/)*

## How to Begin

You need to download the "distribution code" which contains the scaffolding for the `speller` program, the huge dictionary files, and many test texts. 

Open the terminal window at the bottom of your screen. Ensure your terminal is in the main workspace directory (it should look like `student@codespace:/workspaces/codingrabbit-cs50-week5$`). 

Run the following commands one by one to download the ZIP file, extract it, and clean up the ZIP:

```bash
curl -O https://cdn.cs50.net/2026/x/psets/5/speller.zip
unzip speller.zip
rm speller.zip
```

Extracting the ZIP will automatically populate this `speller` folder with the `dictionary.c` starter code, `speller.c`, a `dictionaries/` folder, and a `texts/` folder. Now, change your terminal directory into this folder:

```bash
cd speller
```

You can now use the `code` command to open the dictionary file in the editor:

```bash
code dictionary.c
```

## Instructions

The distribution code already handles reading the texts and formatting the output (in `speller.c`). All you need to do is implement the data structure logic in `dictionary.c`! 

Complete the following five functions:
1.  **`hash`**: Takes a string and returns an index (a bucket number) for your hash table. A better hash function will distribute words more evenly, reducing collisions and making your program faster!
2.  **`load`**: Opens the dictionary file, reads words one at a time, creates a new `node` for each word using `malloc`, hashes the word to find its bucket, and inserts the node into the linked list at that bucket in the hash table.
3.  **`size`**: Returns the total number of words that were successfully loaded into the dictionary.
4.  **`check`**: Returns true if a given word is in the dictionary (ignoring case!). You'll hash the word, go to that bucket in the hash table, and traverse the linked list looking for a match (using `strcasecmp`).
5.  **`unload`**: Frees all the memory you allocated in `load` by iterating over every bucket in the hash table, and then traversing every node in the linked list, calling `free` on each one.

## How to Test

Recall that you can compile your program by running:

```bash
make speller
```

If it compiles successfully, run your program on one of the texts (e.g. the movie script for La La Land):

```bash
./speller texts/lalaland.txt
```

You should also check for memory leaks using `valgrind`! 

```bash
valgrind ./speller texts/lalaland.txt
```
If you correctly implemented `unload`, valgrind should report `All heap blocks were freed -- no leaks are possible`.

If you get a segmentation fault, or if you're struggling to understand how to insert into a linked list, remember to **click the Coding Rabbit icon** on the left sidebar to ask your AI Teaching Assistant for hints!
