#include "../includes/sql.h"
#include <iostream>
#include <string>

using namespace std;

class Conn {
    public:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;

        Conn() {
            try {

                driver = sql::mysql::get_mysql_driver_instance();
                con = driver->connect("tcp://127.0.0.1:3306", "root", "admin123");
                con->setSchema("library");

            }catch (sql::SQLException &e) {
                cout << "Error: " << e.what() << endl;
            }
        }
};