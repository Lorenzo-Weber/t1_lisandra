#include <string>
#include <iostream>
#include "../includes/sql.h"

using namespace std;

class Magazine {

    private:
        string title;
        string summary;
        string asin;
        float pages;
        string publisher;
        string genre;
    public:


        Magazine(string title, string summary, string asin, float pages, string publisher, string genre) {
            setTitle(title);
            setSummary(summary);
            setAsin(asin);
            setPages(pages);
            setPublisher(publisher);
            setGenre(genre);
        }

        Magazine(sql::ResultSet *res) {
            setTitle(res->getString("title"));
            setSummary(res->getString("summary"));
            setAsin(res->getString("asin"));
            setPages(res->getDouble("pages"));
            setPublisher(res->getString("publisher"));
            setGenre(res->getString("genre"));
        }

        void setTitle(string title) {
            this->title = title;
        }

        void setSummary(string summary) {
            this->summary = summary;
        }

        void setAsin(string asin) {
            this->asin = asin;
        }

        void setPages(float pages) {
            this->pages = pages;
        }

        void setPublisher(string publisher) {
            this->publisher = publisher;
        }

        void setGenre(string genre) {
            this->genre = genre;
        }

        string getTitle() {
            return title;
        }

        string getSummary() {
            return summary;
        }

        string getAsin() {
            return asin;
        }

        float getPages() {
            return pages;
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
            cout << "asin: " << asin << endl;
            cout << "Pages: " << pages << endl;
            cout << "Publisher: " << publisher << endl;
            cout << "Genre: " << genre << endl;
        }
};