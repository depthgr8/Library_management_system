#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    int id;
    char title[100];
    int copies;
};

void addBook(struct Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library full! Cannot add more books.\n");
        return;
    }
    struct Book newBook;
    printf("Enter Book ID: ");
    scanf("%d", &newBook.id);
    printf("Enter Title: ");
    getchar(); // consume newline
    fgets(newBook.title, 100, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;
    printf("Enter Number of Copies: ");
    scanf("%d", &newBook.copies);
    books[*count] = newBook;
    (*count)++;
    printf("Book added successfully!\n");
}

void searchBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("\nBook Found:\n");
            printf("ID: %d\nTitle: %s\nCopies: %d\n", books[i].id, books[i].title, books[i].copies);
            return;
        }
    }
    printf("Book not found.\n");
}

void updateBook(struct Book books[], int count) {
    int id;
    printf("Enter Book ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (books[i].id == id) {
            printf("Enter new number of copies: ");
            scanf("%d", &books[i].copies);
            printf("Copies updated successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

void displayBooks(struct Book books[], int count) {
    printf("\nAll Books in Library:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. ID: %d | Title: %s | Copies: %d\n", i + 1, books[i].id, books[i].title, books[i].copies);
    }
}

int main() {
    struct Book books[MAX_BOOKS];
    int count = 0, choice;
    while (1) {
        printf("\n===== Library Menu =====\n");
        printf("1. Add Book\n2. Search Book\n3. Update Book\n4. Display All Books\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addBook(books, &count); break;
            case 2: searchBook(books, count); break;
            case 3: updateBook(books, count); break;
            case 4: displayBooks(books, count); break;
            case 5: printf("Exiting...\n"); return 0;
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
