#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;
/**
 * Function to handle user decisions to either return to the menu or quit the program.
 */
void GererDecisionUtilisateur(){
	char decision;
	bool sortir = false;
	
	while(!sortir){
		// Prompt the user for input
        cout << "> Entrez R pour revenir au menu | Q pour quitter : ";
        cin >> decision;
        
        // Handle the user's decision
        switch (decision) {
            case 'R':  // Return to the menu
            case 'r': {
                sortir = true;
                break;
            }
            case 'Q':  // Quit the program
            case 'q': {
                exit(0);
            }
            default: {
                cout << endl;
                cout << "Choix invalide, veuillez reessayer!!!" << endl;
                cout << endl;
            }
        }
	}
}
/**
 * Function to add a food product to the database.
 * 
 * @param conn - MySQL connection object
 */
void ajouterProduitAlimentaire(MYSQL *conn){
	
	string nom;
	string prix;
	string dateExpiration;

    // Collect product information from user input
    cout << "PRODUIT ALIMENTAIRE | Saisir les données suivantes : " << endl;
    cout << "> Nom : ";
    getline(cin, nom);
    fflush(stdin);
    cout << "> Prix : ";
    cin >> prix;
    fflush(stdin);
    cout << "> Date D'expiration : ";
    cin >> dateExpiration;
    fflush(stdin);

    // Build and execute the SQL insert query
    string insert_query = "INSERT INTO Alimentaire(nom, prix, dateexpiration) VALUES('" + nom + "', '" + prix + "', '" + dateExpiration + "')";
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error inserting data: " << mysql_error(conn) << endl;
    } else {
        cout << "Inserted data successfully." << endl;
    }
}
/**
 * Function to add an electronic product to the database.
 * 
 * @param conn - MySQL connection object
 */
void ajouterProduitElectronique(MYSQL *conn) {
    string nom, prix, garantie, couleur;

    // Collect product information from user input
    cout << "PRODUIT ELECTRONIQUE | Saisir les données suivantes : " << endl;
    cout << "> Nom : ";
    getline(cin, nom);
    fflush(stdin);
    cout << "> Prix : ";
    cin >> prix;
    fflush(stdin);
    cout << "> Garantie : ";
    getline(cin, garantie);
    fflush(stdin);
    cout << "> Couleur : ";
    getline(cin, couleur);
    fflush(stdin);

    // Build and execute the SQL insert query
    string insert_query = "INSERT INTO Electronique(nom, prix, garantie, couleur) VALUES('" + nom + "', '" + prix + "', '" + garantie + "', '" + couleur + "')";
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error inserting data: " << mysql_error(conn) << endl;
    } else {
        cout << "Inserted data successfully." << endl;
    }
}
/**
 * Function to add a computing product to the database.
 * 
 * @param conn - MySQL connection object
 */
void ajouterProduitInformatique(MYSQL *conn) {
    string nom, prix, processeur, RAM, ROM, garantie, couleur;

    // Collect product information from user input
    cout << "PRODUIT INFORMATIQUE | Saisir les données suivantes : " << endl;
    cout << "> Nom : ";
    getline(cin, nom);
    fflush(stdin);
    cout << "> Prix : ";
    cin >> prix;
    fflush(stdin);
    cout << "> Processeur : ";
    getline(cin, processeur);
    fflush(stdin);
    cout << "> RAM : ";
    getline(cin, RAM);
    fflush(stdin);
    cout << "> ROM : ";
    getline(cin, ROM);
    fflush(stdin);
    cout << "> Garantie : ";
    getline(cin, garantie);
    fflush(stdin);
    cout << "> Couleur : ";
    getline(cin, couleur);
    fflush(stdin);

    // Build and execute the SQL insert query
    string insert_query = "INSERT INTO Informatique(nom, prix, processeur, RAM, ROM, garantie, couleur) VALUES('" + nom + "', '" + prix + "', '" + processeur + "','" + RAM + "','" + ROM + "','" + garantie + "','" + couleur + "')";
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error inserting data: " << mysql_error(conn) << endl;
    } else {
        cout << "Inserted data successfully." << endl;
    }
}
/**
 * Function to add a clothing product to the database.
 * 
 * @param conn - MySQL connection object
 */
void ajouterProduitVetement(MYSQL *conn) {
    string nom, prix, taille, couleur;

    // Collect product information from user input
    cout << "PRODUIT VESTIMENTAIRE | Saisir les données suivantes : " << endl;
    cout << "> Nom : ";
    getline(cin, nom);
    fflush(stdin);
    cout << "> Prix : ";
    cin >> prix;
    fflush(stdin);
    cout << "> Taille : ";
    getline(cin, taille);
    fflush(stdin);
    cout << "> Couleur : ";
    getline(cin, couleur);
    fflush(stdin);

    // Build and execute the SQL insert query
    string insert_query = "INSERT INTO Vetement(nom, prix, taille, couleur) VALUES('" + nom + "', '" + prix + "', '" + taille + "', '" + couleur + "')";
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error inserting data: " << mysql_error(conn) << endl;
    } else {
        cout << "Inserted data successfully." << endl;
    }
}
/**
 * Function to display all food products from the database.
 * 
 * @param conn - MySQL connection object
 */
void afficherProduitsAlimentaire(MYSQL *conn) {
    bool exist = true;

    // Execute SQL query to retrieve data from the Alimentaire table
    if (mysql_query(conn, "SELECT * FROM Alimentaire")) {
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;
        MYSQL_RES* res;
        MYSQL_FIELD *field;

        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);

        // Iterate through the rows of the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            if (exist) {
                cout << "-------------------PRODUIT ALIMENTAIRE-------------------" << endl;
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";
                }
                cout << endl;
                exist = false;
            }

            for (int i = 0; i < num_fields; i++) {
                cout << (row[i] ? row[i] : "NULL") << "\t\t";
            }
            cout << endl;
        }
        mysql_free_result(res);
    }
    if (!exist) {
        cout << endl << endl;
    }
}
/**
 * @brief This function displays all electronic products stored in the 'Electronique' table of the database.
 * 
 * It queries the 'Electronique' table for all products and prints each row in a tabular format.
 * If no electronic products are found, the function will not print anything.
 * 
 * @param conn A pointer to the MYSQL object representing the database connection.
 */
void afficherProduitsElectronique(MYSQL *conn){	
    bool exist = true;

    // Execute query to retrieve all electronic products
    if (mysql_query(conn, "SELECT * FROM Electronique")) {
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;
        MYSQL_RES* res;
        MYSQL_FIELD *field;

        // Store the result set
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);

        // Print each row of results
        while ((row = mysql_fetch_row(res)) != NULL) {
        	
            if (exist) {
                cout<<"-------------------PRODUIT ELECTRONIQUE-------------------"<<endl;

                // Print column names
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";
                }
                cout << endl;
                exist = false;
            }

            // Print each field in the row
            for (int i = 0; i < num_fields; i++) {
                cout << (row[i] ? row[i] : "NULL") << "\t\t";
            }
            cout << endl;
        }
        // Free the result set
        mysql_free_result(res);
    }
    
    // Add a line break if products were displayed
    if (!exist) {
        cout << endl << endl;
    } 
}

/**
 * @brief This function displays all computer-related products stored in the 'Informatique' table of the database.
 * 
 * It queries the 'Informatique' table for all products and prints each row in a tabular format.
 * If no computer-related products are found, the function will not print anything.
 * 
 * @param conn A pointer to the MYSQL object representing the database connection.
 */
void afficherProduitsInformatique(MYSQL *conn){	
    bool exist = true;

    // Execute query to retrieve all computer-related products
    if (mysql_query(conn, "SELECT * FROM Informatique")) {
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;
        MYSQL_RES* res;
        MYSQL_FIELD *field;

        // Store the result set
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);

        // Print each row of results
        while ((row = mysql_fetch_row(res)) != NULL) {
        	
            if (exist) {
                cout<<"-------------------PRODUIT INFORMATIQUE-------------------"<<endl;

                // Print column names
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";
                }
                cout << endl;
                exist = false;
            }

            // Print each field in the row
            for (int i = 0; i < num_fields; i++) {
                cout << (row[i] ? row[i] : "NULL") << "\t\t";
            }
            cout << endl;
        }
        // Free the result set
        mysql_free_result(res);
    }

    // Add a line break if products were displayed
    if (!exist) {
        cout << endl << endl;
    } 
}

/**
 * @brief This function displays all clothing products stored in the 'Vetement' table of the database.
 * 
 * It queries the 'Vetement' table for all products and prints each row in a tabular format.
 * If no clothing products are found, the function will not print anything.
 * 
 * @param conn A pointer to the MYSQL object representing the database connection.
 */
void afficherProduitsVetement(MYSQL *conn){	
    bool exist = true;

    // Execute query to retrieve all clothing products
    if (mysql_query(conn, "SELECT * FROM Vetement")) {
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;
        MYSQL_RES* res;
        MYSQL_FIELD *field;

        // Store the result set
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);

        // Print each row of results
        while ((row = mysql_fetch_row(res)) != NULL) {
        	
            if (exist) {
                cout<<"-------------------PRODUIT VESTIMENTAIRE-------------------"<<endl;

                // Print column names
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";
                }
                cout << endl;
                exist = false;
            }

            // Print each field in the row
            for (int i = 0; i < num_fields; i++) {
                cout << (row[i] ? row[i] : "NULL") << "\t\t";
            }
            cout << endl;
        }
        // Free the result set
        mysql_free_result(res);
    }

    // Add a line break if products were displayed
    if (!exist) {
        cout << endl << endl;
    } 
}

/**
 * @brief This function displays all products (alimentaire, electronique, informatique, and vestimentaire)
 * by calling their respective display functions.
 * 
 * @param conn A pointer to the MYSQL object representing the database connection.
 */
void afficherProduits(MYSQL *conn){
    afficherProduitsAlimentaire(conn);  // Display alimentaire products
    afficherProduitsElectronique(conn);  // Display electronic products
    afficherProduitsInformatique(conn);  // Display computer-related products
    afficherProduitsVetement(conn);  // Display clothing products
}

// Function to search for food products by name in the Alimentaire table
bool RechercherProduitsAlimentaireParNom(MYSQL *conn, string nom) {
    bool exist = false;  // Flag to check if the product exists
    
    // Execute SQL query to select all records from the Alimentaire table
    if (mysql_query(conn, "SELECT * FROM Alimentaire")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product name matches the specified name
            if (row[1] == nom) {  
                // Print header for the product details
                cout << "-------------------PRODUIT ALIMENTAIRE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for electronic products by name in the Electronique table
bool RechercherProduitsElectroniqueParNom(MYSQL *conn, string nom) {
    bool exist = false;  // Flag to check if the product exists
    
    // Execute SQL query to select all records from the Electronique table
    if (mysql_query(conn, "SELECT * FROM Electronique")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product name matches the specified name
            if (row[1] == nom) {  
                // Print header for the product details
                cout << "-------------------PRODUIT ELECTRONIQUE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for IT products by name in the Informatique table
bool RechercherProduitsInformatiqueParNom(MYSQL *conn, string nom) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Informatique table
    if (mysql_query(conn, "SELECT * FROM Informatique")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product name matches the specified name
            if (row[1] == nom) {  
                // Print header for the product details
                cout << "-------------------PRODUIT INFORMATIQUE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for clothing products by name in the Vetement table
bool RechercherProduitsVetementParNom(MYSQL *conn, string nom) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Vetement table
    if (mysql_query(conn, "SELECT * FROM Vetement")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product name matches the specified name
            if (row[1] == nom) {  
                // Print header for the product details
                cout << "-------------------PRODUIT VETEMENT-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for products by name across different categories
void RechercherProduitsParNom(MYSQL *conn) {
    bool found = false;    // Flag to indicate if any product was found
    bool notFound = true;  // Flag to indicate if no products were found
    string nom;            // Variable to hold the product name entered by the user
    cout << "> Entrez le nom : ";  // Prompt user for product name
    cin >> nom;  // Read the product name from input
    
    // Search in different product categories
    found = RechercherProduitsAlimentaireParNom(conn, nom);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsElectroniqueParNom(conn, nom);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsInformatiqueParNom(conn, nom);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsVetementParNom(conn, nom);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    
    // If no products were found, print a message
    if (notFound) {
        cout << "Pas de produits avec le nom : " << nom << endl << endl;  // Message for no products found
    }
}

// Function to search for food products by price in the Alimentaire table
bool RechercherProduitsAlimentaireParPrix(MYSQL *conn, string prix) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Alimentaire table
    if (mysql_query(conn, "SELECT * FROM Alimentaire")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product price matches the specified price
            if (row[2] == prix) {  
                // Print header for the product details
                cout << "-------------------PRODUIT ALIMENTAIRE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for electronic products by price in the Electronique table
bool RechercherProduitsElectroniqueParPrix(MYSQL *conn, string prix) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Electronique table
    if (mysql_query(conn, "SELECT * FROM Electronique")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product price matches the specified price
            if (row[2] == prix) {  
                // Print header for the product details
                cout << "-------------------PRODUIT ELECTRONIQUE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for IT products by price in the Informatique table
bool RechercherProduitsInformatiqueParPrix(MYSQL *conn, string prix) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Informatique table
    if (mysql_query(conn, "SELECT * FROM Informatique")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product price matches the specified price
            if (row[2] == prix) {  
                // Print header for the product details
                cout << "-------------------PRODUIT INFORMATIQUE-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for clothing products by price in the Vetement table
bool RechercherProduitsVetementParPrix(MYSQL *conn, string prix) {
    bool exist = false;  // Flag to indicate if the product exists
    
    // Execute SQL query to select all records from the Vetement table
    if (mysql_query(conn, "SELECT * FROM Vetement")) {
        // Print error message if the query fails
        cerr << "Error executing query: " << mysql_error(conn) << endl;
    } else {
        MYSQL_ROW row;        // To hold each row of the result
        MYSQL_RES* res;      // To hold the result set
        MYSQL_FIELD *field;  // To hold field information
        
        // Store the result set from the query
        res = mysql_store_result(conn);
        int num_fields = mysql_num_fields(res);  // Get the number of fields in the result

        // Iterate through each row in the result set
        while ((row = mysql_fetch_row(res)) != NULL) {
            // Check if the product price matches the specified price
            if (row[2] == prix) {  
                // Print header for the product details
                cout << "-------------------PRODUIT VETEMENT-------------------" << endl;

                // Print column names for the result set
                while ((field = mysql_fetch_field(res))) {
                    cout << field->name << "\t\t";  // Print each field name
                }
                cout << endl;  // New line after printing field names

                // Print the details of the found product
                for (int i = 0; i < num_fields; i++) {
                    cout << (row[i] ? row[i] : "NULL") << "\t\t";  // Print each field value or "NULL"
                }
                cout << endl;  // New line after printing the row data
                exist = true;  // Set exist flag to true
            }
        }
        // Free the result set to prevent memory leaks
        mysql_free_result(res);
    }
    // Print new lines if the product was found
    if (exist) {
        cout << endl << endl;
    }
    return exist;  // Return whether the product was found
}

// Function to search for products by price across different categories
void RechercherProduitsParPrix(MYSQL *conn) {
    bool found = false;    // Flag to indicate if any product was found
    bool notFound = true;  // Flag to indicate if no products were found
    string prix;           // Variable to hold the price entered by the user
    cout << "> Entrez le prix : ";  // Prompt user for price
    cin >> prix;  // Read the price from input
    
    // Search in different product categories
    found = RechercherProduitsAlimentaireParPrix(conn, prix);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsElectroniqueParPrix(conn, prix);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsInformatiqueParPrix(conn, prix);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    found = RechercherProduitsVetementParPrix(conn, prix);
    if (found) {
        notFound = false;  // Set notFound to false if a product is found
    }
    
    // If no products were found, print a message
    if (notFound) {
        cout << endl << "Pas de produits avec le prix : " << prix << " MAD" << endl << endl;  // Message for no products found
    }
}

// Function to delete products from different categories based on price
void supprimerProduitParPrix(MYSQL *conn) {
    bool found = false;  // Flag to indicate if any product was deleted
    string prix;         // Variable to hold the price entered by the user

    cout << "> Entrez le prix : ";  // Prompt user for price
    cin >> prix;  // Read the price from input

    // Construct SQL query to delete records from the Alimentaire table based on the specified price
    string insert_query = "DELETE FROM Alimentaire WHERE prix = " + prix;
    if (mysql_query(conn, insert_query.c_str())) {
        // Print error message if the query fails
        cerr << "Error deleting data: " << mysql_error(conn) << endl;
    } else {
        // Indicate successful deletion for Alimentaire products
        cout << "deleted data successfully." << endl;
        found = true;  // Set found flag to true if deletion was successful
    }

    // Repeat the process for the Electronique table
    insert_query = "DELETE FROM Electronique WHERE prix = " + prix;
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error deleting data: " << mysql_error(conn) << endl;  // Print error message if the query fails
    } else {
        found = true;  // Set found flag to true if deletion was successful
    }

    // Repeat the process for the Informatique table
    insert_query = "DELETE FROM Informatique WHERE prix = " + prix;
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error deleting data: " << mysql_error(conn) << endl;  // Print error message if the query fails
    } else {
        found = true;  // Set found flag to true if deletion was successful
    }

    // Repeat the process for the Vetement table
    insert_query = "DELETE FROM Vetement WHERE prix = " + prix;
    if (mysql_query(conn, insert_query.c_str())) {
        cerr << "Error deleting data: " << mysql_error(conn) << endl;  // Print error message if the query fails
    } else {
        found = true;  // Set found flag to true if deletion was successful
    }
    
    // If at least one product was found and deleted, inform the user
    if (found) {
        cout << "Produit supprimee." << endl;  // Message for successful deletion
    } else {
        // If no products were found with the specified price, inform the user
        cout << "Pas de produits avec le prix : " << prix << endl << endl;  // Message for no products found
    }
}

// Main function that serves as the entry point of the program
int main() {
    
    MYSQL* conn;  // Pointer to hold MySQL connection object
    conn = mysql_init(0);  // Initialize the MySQL connection

    // Check if the connection initialization failed
    if (conn == 0) {
        cerr << "Error initializing MySQL connection." << endl;  // Print error message
        exit(0);  // Exit the program
    }

    // Attempt to connect to the MySQL database
    if (mysql_real_connect(conn, "localhost", "root", "root", "Magasin", 3306, 0, 0) == 0) {
        cerr << "Error connecting to database: " << mysql_error(conn) << endl;  // Print error message if connection fails
        mysql_close(conn);  // Close the connection
        exit(0);  // Exit the program
    }

    cout << "Successfully connected to the database!" << endl;  // Print success message
    
    MYSQL_ROW row;  // Variable to hold a row of data retrieved from the database
    MYSQL_RES* res; // Variable to hold the result set of a query
    int choix;      // Variable to store the user's menu choice
    bool quitter = false; // Flag to indicate if the user wants to exit

    // Main loop for the menu
    while (!quitter) {
        cout << endl;
        cout << "===== MENU GESTION MAGASIN =====" << endl;  // Display menu header
        cout << "1. Ajouter un produit" << endl;  // Option to add a product
        cout << "2. Afficher tous les produits" << endl;  // Option to display all products
        cout << "3. Rechercher un produit par nom" << endl;  // Option to search for a product by name
        cout << "4. Rechercher un produit par prix" << endl;  // Option to search for a product by price
        cout << "5. Supprimer un produit par prix" << endl;  // Option to delete a product by price
        cout << "6. Quitter" << endl << endl;  // Option to exit the program
        cout << "Entrez votre choix : ";  // Prompt user for input
        cin >> choix;  // Read the user's choice
        cout << endl;     
        fflush(stdin);  // Clear the input buffer

        // Switch statement to handle the user's choice
        switch (choix) {
            case 1: {  // Case for adding a product
                int typeProduit;  // Variable to store the type of product
                
                cout << endl;
                cout << "> CHOISISSEZ LE TYPE DE PRODUIT" << endl;  // Prompt for product type
                cout << "1. Produit Alimentaire" << endl;
                cout << "2. Produit Electronique" << endl;
                cout << "3. Produit Informatique" << endl;
                cout << "4. Produit Vestimentaire" << endl;
                cout << "Autre chiffre pour ignorer l'ajout du produit" << endl << endl;
                cout << "Entrez votre choix : ";  // Prompt for product type choice
                cin >> typeProduit;  // Read the product type
                cout << endl;
                fflush(stdin);  // Clear the input buffer
                   
                // Switch statement to handle product type
                switch (typeProduit) {
                    case 1: {
                        ajouterProduitAlimentaire(conn);  // Function to add food product
                        break;
                    }
                    case 2: {
                        ajouterProduitElectronique(conn);  // Function to add electronic product
                        break;
                    }
                    case 3: {                        
                        ajouterProduitInformatique(conn);  // Function to add IT product
                        break;
                    }
                    case 4: {
                        ajouterProduitVetement(conn);  // Function to add clothing product
                        break;
                    }
                    default: {
                        break;  // Ignore if the choice is not valid
                    }
                }               
                GererDecisionUtilisateur();  // Function to handle user decision after adding product
                break;
            }  // End of case 1       
            case 2: {  // Case for displaying all products
                afficherProduits(conn);  // Function to display products
                GererDecisionUtilisateur();  // Function to handle user decision
                break;
            }
            case 3: {  // Case for searching a product by name
                RechercherProduitsParNom(conn);  // Function to search products by name
                GererDecisionUtilisateur();  // Function to handle user decision
                break;
            }
            case 4: {  // Case for searching a product by price
                RechercherProduitsParPrix(conn);  // Function to search products by price
                GererDecisionUtilisateur();  // Function to handle user decision
                break;
            }
            case 5: {  // Case for deleting a product by price
                supprimerProduitParPrix(conn);  // Function to delete products by price
                GererDecisionUtilisateur();  // Function to handle user decision
                break;
            }
            case 6: {  // Case for quitting the program
                cout << endl;
                cout << "Merci d'avoir utilise le systeme de gestion du magasin." << endl;  // Thank the user
                quitter = true;  // Set the flag to exit the loop
                break;
            }
            default: {  // Handle invalid choice
                cout << endl;
                cout << "Choix invalide, veuillez reessayer!!!" << endl;  // Print error message for invalid choice
            }
        }
    }
    
    mysql_close(conn);  // Close the MySQL connection before exiting
    
    return 0;  // Return 0 to indicate successful completion
}

