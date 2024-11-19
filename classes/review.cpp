#include <string>
#include <iostream>
using namespace std;

class Review {
    public:
        string text;
        int rating;

        void getReview() {
            string review;
            cout << "Write your review: " << endl;
            getline(cin, review);
            
            this->text = review;
        }

        void getRating() {
            int rate = -1;
            while (rate < 1 || rate > 5) {
                cout << "Rate the book from 1 to 5: " << endl;
                cin >> rate;
                cin.ignore();
            }
            this->rating = rate;
        }
};