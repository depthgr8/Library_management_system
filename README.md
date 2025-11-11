# Library Management System in C

##  Overview
This project implements a simple **Library Management System** in the C programming language.  
It allows users to:
- Add a new book record
- Search for a book by its ID
- Update the number of copies
- Display all books

---

##  Problem-Solving Approach

1. **Problem Understanding:**
   We need a program that maintains a small database of books. Each book has:
   - Book ID (integer)
   - Title (string)
   - Number of copies (integer)

2. **Solution Design:**
   - Use a `struct` to represent each book.
   - Use an array of `struct` to store multiple books.
   - Implement functions for each operation (add, search, update, display).
   - Use manual trace to ensure logical correctness.

---

##  Manual Trace Example

| Step | Action | Result |
|------|---------|--------|
| 1 | Add Book: ID=1, Title="C Programming", Copies=5 | Book added |
| 2 | Add Book: ID=2, Title="Data Structures", Copies=3 | Book added |
| 3 | Update Copies for ID=1 → 7 | Copies updated |
| 4 | Display Books | Shows both records with updated copies |

---

##  Program Code

See [`library_system.c`](library_system.c)

---

##  How to Run

```bash
gcc library_system.c -o library_system
./library_system
```

---

##  License

MIT License

Copyright (c) 2025 Deepak Sharma

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
