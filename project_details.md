
# **Problem solving approach**

**Goal:** build a small library system that supports:

*   Add a book (Book ID int, Title string, Number of Copies int)
*   Search by Book ID and display details
*   Update number of copies for a Book ID
*   Display all book records

**High-level plan (structured problem solving):**

1.  **Clarify & constrain requirements**

*   Max number of records? (we pick a constant, e.g. MAX\_BOOKS = 100  easy to change)
*   Should Book IDs be unique? → yes (enforce uniqueness when adding)
*   How to store records? → struct Book { int id; char title\[...\]; int copies; } stored in an array
*   Input/Output: console menu for operations (appropriate for a small system / classroom use)

3.  **Design data structures**

*   struct Book with fields id, title, copies.
*   Book books\[MAX\_BOOKS\]; int n\_books = 0; to track current count.

5.  **Define operations / functions** (single responsibility):

*   int find\_book\_index\_by\_id(int id) → returns index or \-1 if not found.
*   int add\_book(Book books\[\], int \*n\_books, Book newbook) → checks for space and unique id.
*   void display\_book(const Book \*) and void display\_all\_books(...).
*   int update\_copies(Book books\[\], int n\_books, int id, int new\_copies).

7.  **Algorithm details**

*   For search and update, we do a linear search through the array (O(n)). For small systems this is fine.
*   If scaling up: use sorted array + binary search, or hash table / balanced tree for faster lookup.

9.  **User interface**

*   Menu loop: prompt user to pick operation until they exit.
*   Input validation: check non-negative copies, integer IDs, non-empty title.

11.  **Error handling**

*   Adding when array full → show message.
*   Adding with duplicate ID → reject.
*   Searching/updating nonexistent ID → show message.

13.  **Testing**

*   Unit tests / manual tests: add duplicate ID, search existing + nonexisting, update existing + nonexisting, add until full.

15.  **Team / collaboration**

*   Split tasks: one person writes data model & functions; another writes I/O/menu; third writes testing harness and documentation.
*   Use pair programming for tricky input sanitization and concurrency considerations (if later adding file/DB persistence).

## **Flowchart**

![Library Management System Flowchart](https://raw.githubusercontent.com/depthgr8/Library_management_system/940645efcf151af49792b044e34813c5d5403600/Flowchart.svg "Flowchart of Library system")
Loop back to Menu until Exit

## **Manual trace**

Assume MAX\_BOOKS = 100.

Initial state:

*   n\_books = 0
*   books array is empty

**Operation A  Add Book 1**

*   Input: ID = 101, Title = "C Programming", Copies = 3
*   Check n\_books < MAX\_BOOKS → 0 < 100 OK.
*   Check find\_book\_index\_by\_id(101) → returns \-1 (not found).
*   Insert at books\[0\] = {101, "C Programming", 3}.
*   n\_books becomes 1.

**State after A:**

*   n\_books = 1
*   books\[0\] = { id:101, title:"C Programming", copies:3 }

**Operation B  Add Book 2**

*   Input: ID = 205, Title = "Data Structures", Copies = 5
*   Check n\_books < MAX\_BOOKS → 1 < 100 OK.
*   find\_book\_index\_by\_id(205) → \-1.
*   Insert at books\[1\] = {205, "Data Structures", 5}.
*   n\_books becomes 2.

**State after B:**

*   n\_books = 2
*   books\[0\] = {101, "C Programming", 3}
*   books\[1\] = {205, "Data Structures", 5}

**Operation C  Update copies for Book ID 101**

*   Input: ID = 101, new\_copies = 7
*   find\_book\_index\_by\_id(101) → scans:

*   index 0 has id 101 → found at index 0.

*   Update books\[0\].copies = 7.

**Final state:**

*   n\_books = 2
*   books\[0\] = {101, "C Programming", 7}
*   books\[1\] = {205, "Data Structures", 5}

**Manual trace output (what the user would see):**

*   After adding Book 1: "Book added: ID=101, Title=C Programming, Copies=3"
*   After adding Book 2: "Book added: ID=205, Title=Data Structures, Copies=5"
*   After update: "Book updated: ID=101, Copies set to 7"
*   Display all:

*   ID: 101, Title: C Programming, Copies: 7
*   ID: 205, Title: Data Structures, Copies: 5

## **Example session (test run)**

Welcome to the Small Library System

Menu:

1) Add a new book

2) Search for a book by ID

3) Update number of copies by ID

4) Display all books

5) Exit

Choose option (1-5): 1

Enter Book ID (integer): 101

Enter Title: C Programming

Enter Number of Copies: 3

Book added: ID=101, Title=C Programming, Copies=3

Choose option (1-5): 1

Enter Book ID (integer): 205

Enter Title: Data Structures

Enter Number of Copies: 5

Book added: ID=205, Title=Data Structures, Copies=5

Choose option (1-5): 3

Enter Book ID to update: 101

Enter new number of copies: 7

Updated book ID 101 to 7 copies.

Choose option (1-5): 4

All books (2):

\------------

ID: 101

Title: C Programming

Copies: 7

\------------

ID: 205

Title: Data Structures

Copies: 5

\------------

Choose option (1-5): 5

Exiting. Goodbye!

## **Complexity and design notes**

*   **Storage:** O(MAX\_BOOKS) memory.
*   **Add:** O(n) time for checking duplicate (linear scan). Insertion O(1).
*   **Search/Update:** O(n) using linear search.
*   **Display all:** O(n).

**If you want better performance** for large n:

*   Use a hash table mapping id -> index for O(1) lookups.
*   Or keep array sorted by id, use binary search (O(log n)) but insertion becomes O(n) unless you use dynamic arrays or linked lists.

## **Test cases**

*   Adding book with duplicate ID → rejected.
*   Adding with negative copies → rejected.
*   Searching/updating nonexisting ID → proper message.
*   Add until library full → error.
*   Titles with long length → truncated safely.
*   Non-integer input for ID/copies → handled by read\_int.

## **Collaborative coding & team building ideas**

*   **Roles**:

*   _Data modeler_: defines structs and validation rules.
*   _I/O/UX developer_: builds menu and input sanitization.
*   _Tester_: writes test cases & executes them (including boundary tests).
*   _Integrator/Documenter_: writes comments, documentation, and demo scenario.

*   **Pair-programming tasks**: pair to implement and test add\_book while the other writes unit tests.
*   **Group exercise**: one subgroup converts array to file persistence (save/load), another implements hash-based lookup.