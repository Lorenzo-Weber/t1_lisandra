#include "conn.cpp"
#include "book.cpp"
#include "comic.cpp"
#include "magazine.cpp"
#include "review.cpp"
#include "string.cpp"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Library {

    public:
        vector<Book> books;
        vector<Comic> comics;
        vector<Magazine> magazines;
    
        Conn c = Conn();

        void addBook(Book newBook) {
            try {
                    sql::PreparedStatement *pstmt = c.con->prepareStatement(
                    "INSERT INTO book (title, summary, isbn, pages, author, publisher, genre) VALUES (?, ?, ?, ?, ?, ?, ?)"
                );
                pstmt->setString(1, newBook.getTitle());
                pstmt->setString(2, newBook.getSummary());
                pstmt->setString(3, newBook.getIsbn());
                pstmt->setDouble(4, newBook.getPages());
                pstmt->setString(5, newBook.getAuthor());
                pstmt->setString(6, newBook.getPublisher());
                pstmt->setString(7, newBook.getGenre());
                pstmt->execute();

                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error adding book: " << e.what() << endl;
            }
        }

        void addComic(Comic newComic) {
            try {
                sql::PreparedStatement *pstmt = c.con->prepareStatement(
                    "INSERT INTO comic (title, summary, asin, pages, publisher, genre) VALUES (?, ?, ?, ?, ?, ?)"
                );
                pstmt->setString(1, newComic.getTitle());
                pstmt->setString(2, newComic.getSummary());
                pstmt->setString(3, newComic.getAsin());
                pstmt->setDouble(4, newComic.getPages());
                pstmt->setString(5, newComic.getPublisher());
                pstmt->setString(6, newComic.getGenre());
                pstmt->execute();

                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error adding comic: " << e.what() << endl;
            }
        }

        void addMagazine (Magazine newMagazine) {
            try {
                sql::PreparedStatement *pstmt = c.con->prepareStatement(
                    "INSERT INTO magazine (title, summary, asin, pages, publisher, genre) VALUES (?, ?, ?, ?, ?, ?)"
                );
                pstmt->setString(1, newMagazine.getTitle());
                pstmt->setString(2, newMagazine.getSummary());
                pstmt->setString(3, newMagazine.getAsin()); 
                pstmt->setDouble(4, newMagazine.getPages());
                pstmt->setString(5, newMagazine.getPublisher());
                pstmt->setString(6, newMagazine.getGenre());
                pstmt->execute();

                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error adding magazine: " << e.what() << endl;
            }
        }

        void getBook(string query) {
            try {
                sql::PreparedStatement *pstmt = c.con->prepareStatement("SELECT * FROM book WHERE title LIKE ? OR author LIKE ? OR genre LIKE ?");
                query = "%" + query + "%";
                pstmt->setString(1, query);
                pstmt->setString(2, query );
                pstmt->setString(3, query);
                sql::ResultSet *res = pstmt->executeQuery();
                while (res->next()) {
                    Book newBook(res);
                    books.push_back(newBook);
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error retrieving book: " << e.what() << endl;
            }
        }

        void getComic(string search) {
            try {
                sql::PreparedStatement *pstmt = c.con->prepareStatement("SELECT * FROM comic WHERE title LIKE ? OR genre LIKE ?");
                search = "%" + search + "%";
                pstmt->setString(1, search);
                pstmt->setString(2, search);

                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    Comic newComic(res);
                    comics.push_back(newComic);
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error retrieving comic: " << e.what() << endl;
            }
        }

        void getMagazine (string search) {
            try {
                sql::PreparedStatement *pstmt = c.con->prepareStatement("SELECT * FROM magazine WHERE title LIKE ? OR genre LIKE ?");
                search = "%" + search + "%";
                pstmt->setString(1, search);
                pstmt->setString(2, search);
                sql::ResultSet *res = pstmt->executeQuery();

                while (res->next()) {
                    Magazine newMagazine(res);
                    magazines.push_back(newMagazine);
                }

                delete res;
                delete pstmt;
            } catch (sql::SQLException &e) {
                cout << "Error retrieving magazine: " << e.what() << endl;
            }
        }

        void getAll(string search) {
            clear();
            getBook(search);
            getComic(search);
            getMagazine(search);
        }

        void clear() {
            books.clear();
            comics.clear();
            magazines.clear();
        }

        void Search (string search) {
            clear();
            char type = tag(search);
            search = format(search);

            if(all(type)) getAll(search);
            if(book(type)) getBook(search);
            if(comic(type)) getComic(search);
            if(magazine(type)) getMagazine(search);

        }

        void insertReview (Review *r, string id) {
            int rating = r->rating;
            string review = r->text;

            sql::PreparedStatement * pstmt = c.con->prepareStatement("INSERT INTO review (rate, text, ID) VALUES (?, ?, ?)");
            pstmt->setInt(1, rating);
            pstmt->setString(2, review);
            pstmt->setString(3, id);
            pstmt->execute();
        }

        void printBooks() {
            for (int i = 0; i < books.size(); i++) {
                books[i].printInfo();
            }
        }   

};
