Telephone Directory Management System

The Telephone Directory Management System is a desktop application developed in C++ that allows users to manage contacts stored in a MySQL database. It provides functionalities for creating, searching, updating, and deleting contacts.
Features

    Create Contacts: Add new contacts with details such as first name, last name, company, job title, email, and phone number.

    Search Contacts: Search for contacts based on keywords that match any part of their details (first name, last name, company, job title, email, phone number).

    Update Contacts: Modify existing contact details. Searches can be performed to locate the contact, and updates can be made to any of the fields.

    Delete Contacts: Remove contacts from the directory based on the phone number or other matching details.

    Interactive Console Interface: Utilizes a simple console-based interface for user interaction.

Requirements

    C++ Compiler
    MySQL Server
    MySQL C API (libmysqlclient-dev on Linux)

Dependencies

    MySQL C Connector: This project uses the MySQL C API for database connectivity.
Setup Instructions

    Clone the Repository:

    bash

git clone <repository_url>
cd telephone-directory-management-system

Database Setup:

    Ensure MySQL server is installed and running.
    Create a database named tdms:

    sql

    CREATE DATABASE tdms;

Import Database Schema:

    Use the provided SQL script (tdms.sql) to create the necessary table:

    bash

    mysql -u root -p tdms < tdms.sql

    Replace root with your MySQL username if different.

Build and Run:

    Compile the project using your C++ compiler (e.g., g++):

    bash

g++ main.cpp -o tdms -lmysqlclient

Run the executable:

bash

    ./tdms

Usage:

    Follow the on-screen instructions to navigate through the application menu.
    Use the respective menu options to create, search, update, delete contacts, or exit the program.
