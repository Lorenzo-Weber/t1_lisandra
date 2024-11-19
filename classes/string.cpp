#include <string>
#include <iostream>

using namespace std;

char tag(string query) {
    if(query[0] == '@') {
        return query[1];
    }
    else return ' ';
}

string format(string query) {
    if(query[0] == '@') {
        if(query[2] == ' ') {
            query = query.substr(3);  
        }
        else {
            query = query.substr(2); 
        }
    }
    return query;  
}

bool all(char type) {
    return type == ' ';
}

bool book(char type) {
    return type == 'b';
}

bool comic(char type) {
    return type == 'c';
}

bool magazine(char type) {
    return type == 'm';
}

