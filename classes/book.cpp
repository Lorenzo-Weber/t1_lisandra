#include <string>
#include <iostream>
#include "../includes/sql.h"

using namespace std;

class Book {

    private:
        string title;
        string summary;
        string isbn;
        float pages;
        string author;
        string publisher;
        string genre;
    public:


        Book(string title, string summary, string isbn, float pages, string author, string publisher, string genre) {
            setTitle(title);
            setSummary(summary);
            setIsbn(isbn);
            setPages(pages);
            setAuthor(author);
            setPublisher(publisher);
            setGenre(genre);
        }

        Book(sql::ResultSet *res) {
            setTitle(res->getString("title"));
            setSummary(res->getString("summary"));
            setIsbn(res->getString("isbn"));
            setPages(res->getDouble("pages"));
            setAuthor(res->getString("author"));
            setPublisher(res->getString("publisher"));
            setGenre(res->getString("genre"));
        }

        void setTitle(string title) {
            this->title = title;
        }

        void setSummary(string summary) {
            this->summary = summary;
        }

        void setIsbn(string isbn) {
            this->isbn = isbn;
        }

        void setPages(float pages) {
            this->pages = pages;
        }

        void setAuthor(string author) {
            this->author = author;
        }

        void setPublisher(string publisher) {
            this->publisher = publisher;
        }

        void setGenre(string genre) {
            this->genre = genre;
        }

        string getTitle() {
            return this->title;
        }

        string getSummary() {
            return summary;
        }

        string getIsbn() {
            return isbn;
        }

        float getPages() {
            return pages;
        }

        string getAuthor() {
            return author;
        }

        string getPublisher() {
            return publisher;
        }

        string getGenre() {
            return genre;
        }

        void printInfo() {
            cout << "Title: " << title << endl;
            cout << "Summary: " << summary << endl;
            cout << "ISBN: " << isbn << endl;
            cout << "Pages: " << pages << endl;
            cout << "Author: " << author << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Genre: " << genre << endl;
        }
};