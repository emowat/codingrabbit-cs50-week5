## Problem to Solve

A person's blood type is determined by two alleles (i.e. different forms of a gene). The three possible alleles are A, B, and O, of which each person has two (one inherited from each of their parents).

In a file called `inheritance.c` in a folder called `inheritance`, you'll simulate the inheritance of blood types for each member of a family.

*For the full background on blood types, alleles, and a detailed walkthrough, read the official instructions here: [CS50 Inheritance Instructions](https://cs50.harvard.edu/x/psets/5/inheritance/)*

## How to Begin

You need to download the "distribution code" which contains the scaffolding for the `inheritance` program. 

Open the terminal window at the bottom of your screen. Ensure your terminal is in the main workspace directory (it should look like `student@codespace:/workspaces/codingrabbit-cs50-week5$`). 

Run the following commands one by one to download the ZIP file, extract it, and clean up the ZIP:

```bash
curl -O https://cdn.cs50.net/2026/x/psets/5/inheritance.zip
unzip inheritance.zip
rm inheritance.zip
```

Extracting the ZIP will automatically populate this `inheritance` folder with the `inheritance.c` starter code. Now, change your terminal directory into this folder:

```bash
cd inheritance
```

You can now use the `code` command to open the file in the editor:

```bash
code inheritance.c
```

## Instructions

The distribution code defines a `person` struct. Each person has an array of two `parents`, and an array of two `alleles`.
Your job is to complete the three TODOs:

1.  **`create_family`**: Recursively allocate memory for a new person and their parents. 
    *   If `generations > 1`, allocate memory for the person, recursively call `create_family` to set their `parents[0]` and `parents[1]`, and randomly assign one allele from each parent to the child.
    *   If `generations == 1` (the base case), simply allocate memory for the person, set their parents to `NULL`, and assign them random alleles using the `random_allele()` function.
2.  **`free_family`**: Recursively free the dynamically allocated memory for a person and their ancestors. 
    *   If `p == NULL` (base case), just return.
    *   Otherwise, recursively call `free_family` on both parents, and *then* free `p`.

## How to Test

Recall that you can compile your program by running:

```bash
make inheritance
```

If it compiles successfully, run your program:

```bash
./inheritance
```

You should also check for memory leaks using `valgrind`! 

```bash
valgrind ./inheritance
```
If you correctly implemented `free_family`, valgrind should report `All heap blocks were freed -- no leaks are possible`.

If you see an error message, get a segmentation fault, or have memory leaks, remember to **click the Coding Rabbit icon** on the left sidebar to ask your AI Teaching Assistant for hints!
