Store Management System
Overview
The Store Management System is a C++ application that allows users to manage a store's inventory efficiently. It provides functionalities for adding, searching, displaying, and deleting products in various categories, including food, electronics, IT products, and clothing. The system utilizes MySQL as the database backend for storing product information.

Features
Add Products: Users can add new products to the inventory, categorized by type.
Search Products: Allows users to search for products by name or price.
Display Products: Users can view all products in the inventory.
Delete Products: Products can be deleted from the inventory based on their price.
User-friendly Interface: The application presents a clear menu for easy navigation.
Technologies Used
Programming Language: C++
Database: MySQL
Libraries: MySQL C API
Installation
Clone the Repository:

bash
git clone https://github.com/Hamdaoui-Ali/Store-Management-System/tree/main
cd store-management-system
Set Up MySQL:

Ensure you have MySQL installed on your machine.
Create a database named Magasin.
Run the provided SQL scripts to set up the required tables (e.g., Alimentaire, Electronique, Informatique, Vetement).
Compile the Application:

Make sure you have a C++ compiler and MySQL development libraries installed.
Compile the code using the following command:

bash
g++ main.cpp -o store_management -lmysqlclient
Run the Application:

Execute the compiled binary:
bash
./store_management
Usage
Start the application, and you will be presented with a menu.
Follow the prompts to add, search, display, or delete products.
Enter the corresponding number to select an action.
To exit the application, choose the option to quit.
Contributing
Contributions are welcome! If you have suggestions or improvements, please feel free to fork the repository and submit a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Contact
For any inquiries or issues, please reach out to:
alihamdaoui000@gmail.com
