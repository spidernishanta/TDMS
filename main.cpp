#include <iostream>
#include <mysql/mysql.h>
using namespace std;

const char* HOST = "localhost";
const char* USER = "root";
const char* PW = "";
const char* DB = "tdms";

class Contact {
private:
    string First_name;
    string Last_name;
    string Company;
    string Job_title;
    string Email;
    string Phone;

public:
    Contact(string first_name,
        string last_name,
        string company,
        string job_title,
        string email,
        string phone) {
        First_name = first_name;
        Last_name = last_name;
        Company = company;
        Job_title = job_title;
        Email = email;
        Phone = phone;
    }

    string getFirstName() const {
        return First_name;
    }

    string getLastName() const {
        return Last_name;
    }

    string getCompany() const {
        return Company;
    }

    string getJobTitle() const {
        return Job_title;
    }

    string getEmail() const {
        return Email;
    }

    string getPhone() const {
        return Phone;
    }

    void setFirstName(string first_name) {
        First_name = first_name;
    }

    void setLastName(string last_name) {
        Last_name = last_name;
    }

    void setCompany(string company) {
        Company = company;
    }

    void setJobTitle(string job_title) {
        Job_title = job_title;
    }

    void setEmail(string email) {
        Email = email;
    }

    void setPhone(string phone) {
        Phone = phone;
    }
};

bool empty_fields(const Contact& c) {
    bool allEmpty = c.getFirstName().empty() && c.getLastName().empty() && c.getCompany().empty() && c.getJobTitle().empty() && c.getEmail().empty();
    bool phoneEmpty = c.getPhone().empty();
    
    return allEmpty || (!allEmpty && phoneEmpty);
}

int main() {
    MYSQL* conn;
    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PW, DB, 3306, NULL, 0)) {
        cout << "Error: " << mysql_error(conn);
        return 1;
    }

    bool exit = false;
    string fname, lname, company, job, email, phone, keyword;
    int choice;

    while (!exit) {
        cout << "\nTELEPHONE DIRECTORY MANAGEMENT SYSTEM\n" << endl;
        cout << "**************************************" << endl;
        cout << "1. Create" << endl;
        cout << "2. Search" << endl;
        cout << "3. Update" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Exit" << endl;
        cout << "\nEnter your choice : ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            system("clear");
            cout << "Enter First name : ";
            getline(cin, fname);
            cout << "Enter Last name : ";
            getline(cin, lname);
            cout << "Enter Company : ";
            getline(cin, company);
            cout << "Enter Job title : ";
            getline(cin, job);
            cout << "Enter Email : ";
            getline(cin, email);
            cout << "Enter Phone : ";
            getline(cin, phone);

            {
                Contact c(fname, lname, company, job, email, phone);
                if (empty_fields(c)) {
                    cout << "\nError: All fields are required" << endl;
                    break;
                }
                string insert = "INSERT INTO contacts (First_name, Last_name, Company, Job_title, Email, Phone) VALUES ('" +
                    c.getFirstName() + "', '" + c.getLastName() + "', '" + c.getCompany() + "', '" +
                    c.getJobTitle() + "', '" + c.getEmail() + "', '" + c.getPhone() + "')";

                if (mysql_query(conn, insert.c_str())) {
                    cout << "\nError: " << mysql_error(conn) << endl;
                }
                else {
                    cout << "\nContact saved" << endl;
                }
            }
            break;

        case 2:
            cout << "\nEnter any keyword to search : ";
            getline(cin, keyword);
            {
                string search = "SELECT * FROM contacts WHERE First_name LIKE '%" + keyword + "%' OR Last_name LIKE '%" + keyword + "%' OR Company LIKE '%" + keyword + "%' OR Job_title LIKE '%" + keyword + "%' OR Email LIKE '%" + keyword + "%' OR Phone LIKE '%" + keyword + "%'";
                if (mysql_query(conn, search.c_str())) {
                    cout << "\nError: " << mysql_error(conn) << endl;
                }
                else {
                    MYSQL_RES* res = mysql_store_result(conn);
                    if (res == NULL) {
                        cout << "\nError: " << mysql_error(conn) << endl;
                    }
                    else {
                        int num_rows = mysql_num_rows(res);
                        if (num_rows == 0) {
                            cout << "\nNo contact found" << endl;
                        }
                        else {
                            int num_fields = mysql_num_fields(res);
                            MYSQL_ROW row;
                            cout << "\n";
                            while ((row = mysql_fetch_row(res))) {
                                for (int i = 0; i < num_fields; i++) {
                                    cout << row[i] << " | ";
                                }
                                cout << "\n\n";
                            }
                        }
                        mysql_free_result(res);
                    }
                }
            }
            break;

        case 3:
            cout << "\nEnter any keyword related to the contact : ";
            getline(cin, keyword);
            {
                string search = "SELECT * FROM contacts WHERE First_name LIKE '%" + keyword + "%' OR Last_name LIKE '%" + keyword + "%' OR Company LIKE '%" + keyword + "%' OR Job_title LIKE '%" + keyword + "%' OR Email LIKE '%" + keyword + "%' OR Phone LIKE '%" + keyword + "%'";
                if (mysql_query(conn, search.c_str())) {
                    cout << "\nError: " << mysql_error(conn) << endl;
                }
                else {
                    MYSQL_RES* res = mysql_store_result(conn);
                    if (res == NULL) {
                        cout << "\nError: " << mysql_error(conn) << endl;
                    }
                    else {
                        int num_rows = mysql_num_rows(res);
                        if (num_rows == 0) {
                            cout << "\nNo contact found" << endl;
                        }
                        else {
                            int num_fields = mysql_num_fields(res);
                            MYSQL_ROW row = mysql_fetch_row(res);
                            if (row) {
                                cout << "\n";
                                for (int i = 0; i < num_fields; i++) {
                                    cout << row[i] << " | ";
                                }
                                cout << "\n\n";

                                cout << "Enter First name : ";
                                getline(cin, fname);
                                cout << "Enter Last name : ";
                                getline(cin, lname);
                                cout << "Enter Company : ";
                                getline(cin, company);
                                cout << "Enter Job title : ";
                                getline(cin, job);
                                cout << "Enter Email : ";
                                getline(cin, email);
                                cout << "Enter Phone : ";
                                getline(cin, phone);

                                fname = fname.empty() ? row[0] : fname;
                                lname = lname.empty() ? row[1] : lname;
                                company = company.empty() ? row[2] : company;
                                job = job.empty() ? row[3] : job;
                                email = email.empty() ? row[4] : email;
                                phone = phone.empty() ? row[5] : phone;

                                string upd = "UPDATE contacts SET First_name = '" + fname + "', Last_name = '" + lname + "', Company = '" + company + "', Job_title = '" + job + "', Email = '" + email + "', Phone = '" + phone + "' WHERE Phone = '" + row[5] + "'";
                                if (mysql_query(conn, upd.c_str())) {
                                    cout << "\nError: " << mysql_error(conn) << endl;
                                }
                                else {
                                    cout << "\nContact updated" << endl;
                                }
                            }
                        }
                        mysql_free_result(res);
                    }
                }
            }
            break;

        case 4:
            cout << "\nEnter any keyword to delete : ";
            getline(cin, keyword);
            {
                string search = "SELECT * FROM contacts WHERE First_name LIKE '%" + keyword + "%' OR Last_name LIKE '%" + keyword + "%' OR Company LIKE '%" + keyword + "%' OR Job_title LIKE '%" + keyword + "%' OR Email LIKE '%" + keyword + "%' OR Phone LIKE '%" + keyword + "%'";
                if (mysql_query(conn, search.c_str())) {
                    cout << "\nError: " << mysql_error(conn) << endl;
                }
                else {
                    MYSQL_RES* res = mysql_store_result(conn);
                    if (res == NULL) {
                        cout << "\nError: " << mysql_error(conn) << endl;
                    }
                    else {
                        int num_rows = mysql_num_rows(res);
                        if (num_rows == 0) {
                            cout << "\nNo contact found" << endl;
                        }
                        else {
                            int num_fields = mysql_num_fields(res);
                            MYSQL_ROW row;
                            cout << "\n";
                            while ((row = mysql_fetch_row(res))) {
                                for (int i = 0; i < num_fields; i++) {
                                    cout << row[i] << " | ";
                                }
                                cout << "\n";
                            }

                            cout << "\nEnter Phone number to delete : ";
                            getline(cin, phone);

                            string del = "DELETE FROM contacts WHERE Phone = '" + phone + "'";
                            if (mysql_query(conn, del.c_str())) {
                                cout << "\nError: " << mysql_error(conn) << endl;
                            }
                            else {
                                cout << "\nContact deleted" << endl;
                            }
                        }
                        mysql_free_result(res);
                    }
                }
            }
            break;

        case 5:
            exit = true;
            break;

        default:
            cout << "\nInvalid choice. Please try again..." << endl;
            break;
        }
    }

    mysql_close(conn);
    return 0;
}
