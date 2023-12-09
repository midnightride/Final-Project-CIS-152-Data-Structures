// Blake W Hausafus 2023 bwhausafus@dmacc.edu

#include <iomanip>
#include <iostream>
#include <string>
#include <random>
#include "node.cpp"
using namespace std;

class doubly_linked_list{
public:
    node* first;
    node* last;
    int size;// total items in a list


    doubly_linked_list(){// constructor
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }

    void create_node(shirt* item){// creates new node

        node* inv_node;

        if (this->size == 0){// if list is empty
            inv_node = new node(nullptr, item, nullptr);
            this->first = inv_node;
            this->last = inv_node;
            this->size++;
        }
        else{
            inv_node = new node(last, item, nullptr);
            last->add_invnext(inv_node);
            this->last = inv_node;
            this->size++;
        }
    }

    node* get_last(){
        return this->last;
    }

    node* get_first(){
        return this->first;
    }

    int get_size(){
        return this->size;
    }

    void print_all(){
        node* inv_node = first;
        int count = 1;

        while (inv_node != nullptr){
            cout << count << ": \n";
            cout << "Collar: " <<inv_node->inv_item->get_collar() << "\n";
            cout << "Cuff: " <<inv_node->inv_item->get_cuff() << "\n";
            cout << "Placket: " <<inv_node->inv_item->get_placket() << "\n";
            cout << "Color: " <<inv_node->inv_item->get_color() << "\n";
            cout << "Price: $" <<inv_node->inv_item->get_price() << "\n";
            cout << "\n";
            inv_node = inv_node->inv_next;// go to next node
            count++;// increment count
        }
    }

    void populate(int n, float rand_min, float rand_max){//populate an empty list
        if (this->size == 0){

            for(int i = 0; i < n; i++){

                random_device randomizer;// RNG
                uniform_real_distribution<float> dist(rand_min, rand_max);
                float ramdom_num = ceil(dist(randomizer)* 100.0) / 100.0;// Round to the nearest 100th

                shirt* new_shirt;

                if (i % 10 == 9){
                    new_shirt = new shirt("Point Collar", "Barrel Cuff", "Traditional", "White", 25 + ramdom_num);
                }
                else if (i % 10 == 8){
                    new_shirt = new shirt("Spread Collar", "Barrel Cuff", "Traditional", "White", 25 + ramdom_num);
                }
                else if (i % 10 == 7){
                    new_shirt = new shirt("Spread Collar", "Barrel Cuff", "Traditional", "Blue", 15 + ramdom_num);
                }
                else if (i % 10 == 6){
                    new_shirt = new shirt("Wing Collar", "French Cuff", "French", "White", 65 + ramdom_num);
                }
                else if (i % 10 == 5){
                    new_shirt = new shirt("Point Collar", "French Cuff", "Traditional", "White", 20 + ramdom_num);
                }
                else if (i % 10 == 4){
                    new_shirt = new shirt("Wing Collar", "French Cuff", "French", "White", 60 + ramdom_num);
                }
                else if (i % 10 == 3){
                    new_shirt = new shirt("Point Collar", "French Cuff", "French", "Red", 70 + ramdom_num);
                }
                else if (i % 10 == 2){
                    new_shirt = new shirt("Point Collar", "Barrel Cuff", "Traditional", "Blue", 20 + ramdom_num);
                }
                else if (i % 10 == 1){
                    new_shirt = new shirt("Spread Collar", "Barrel Cuff", "Traditional", "Blue", 20 + ramdom_num);
                }
                else {
                    new_shirt = new shirt("Point Collar", "Barrel Cuff", "Traditional", "Red", 25 + ramdom_num);
                }

                this->create_node(new_shirt);
            }
            cout << "Done! \n";
        }
        else{
            cout << "Error: This list is already populated! \n";
        }

    }

    void node_analytics(node* selected_node){
        node* inv_node = first;


        // total number of similar shirts
        int similar_total_collar = 0;
        int similar_total_cuff = 0;
        int similar_total_placket = 0;
        int similar_total_color = 0;

        // total prices
        float price_total_collar = 0;
        float price_total_cuff = 0;
        float price_total_placket = 0;
        float price_total_color = 0;

        // average prices
        float price_average_collar = 0;
        float price_average_cuff = 0;
        float price_average_placket = 0;
        float price_average_color = 0;

        while (inv_node != nullptr){// Collect data
            if (inv_node->inv_item->get_collar() == selected_node->inv_item->get_collar()){
                price_total_collar += inv_node->inv_item->get_price();
                similar_total_collar++;
            }
            if (inv_node->inv_item->get_cuff() == selected_node->inv_item->get_cuff()){
                price_total_cuff += inv_node->inv_item->get_price();
                similar_total_cuff++;
            }
            if (inv_node->inv_item->get_placket() == selected_node->inv_item->get_placket()){
                price_total_placket += inv_node->inv_item->get_price();
                similar_total_placket++;
            }
            if (inv_node->inv_item->get_color() == selected_node->inv_item->get_color()){
                price_total_color += inv_node->inv_item->get_price();
                similar_total_color++;
            }


            inv_node = inv_node->inv_next;// go to next node
        }


        if (similar_total_collar > 0){
            price_average_collar = price_total_collar / similar_total_collar;// Calculate average
            if(selected_node->inv_item->get_price() <= price_average_collar)
                {cout << "$" << setprecision(2) <<  price_average_collar - selected_node->inv_item->get_price()  << " below average price for " << selected_node->inv_item->get_collar() << "\n";}
            else{cout << "$" << setprecision(2) << selected_node->inv_item->get_price() - price_average_collar  << " above average price for " << selected_node->inv_item->get_collar() << "\n";}
        }
        if (similar_total_cuff > 0){
            price_average_cuff = price_total_cuff / similar_total_cuff;// Calculate average
            if(selected_node->inv_item->get_price() <= price_average_cuff)
                {cout << "$" << setprecision(2) <<  price_average_cuff - selected_node->inv_item->get_price()  << " below average price for " << selected_node->inv_item->get_cuff() << "\n";}
            else{cout << "$" << setprecision(2) << selected_node->inv_item->get_price() - price_average_cuff  << " above average price for " << selected_node->inv_item->get_cuff() << "\n";}
        }
        if (similar_total_placket > 0){
            price_average_placket = price_total_placket / similar_total_placket;// Calculate average
            if(selected_node->inv_item->get_price() <= price_average_placket)
                {cout << "$" << setprecision(2) <<  price_average_placket - selected_node->inv_item->get_price()  << " below average price for " << selected_node->inv_item->get_placket() << " plackets \n";}
            else{cout << "$" << setprecision(2) << selected_node->inv_item->get_price() - price_average_placket  << " above average price for " << selected_node->inv_item->get_placket() << " plackets \n";}
        }
        if (similar_total_color > 0){
            price_average_color = price_total_color / similar_total_color;// Calculate average
            if(selected_node->inv_item->get_price() <= price_average_color)
                {cout << "$" << setprecision(2) <<  price_average_color - selected_node->inv_item->get_price()  << " below average price for " << selected_node->inv_item->get_color() << "\n";}
            else{cout << "$" << setprecision(2) << selected_node->inv_item->get_price() - price_average_color  << " above average price for " << selected_node->inv_item->get_color() << "\n";}
        }
        else{
            cout << "Error: Insufficient data! \n";
        }
    }

    void display_main_menu(){
        char response = '?';
        int response_number = -255;
        bool response_number_flag = true;// reset response_number_flag

        while (response != 'A' or response != 'a' or response != 'B' or response != 'b' or response != 'C' or response != 'c' or response != 'D' or response != 'd' or response != 'E' or response != 'e'){
            cout << "A) Quit \n"
                 << "B) Display all \n"
                 << "C) Populate List\n"
                 << "D) Analytics Menu \n"
                 << "E) Create New Shirt \n";

            cin >> response;


            if (response == 'A' or response == 'a'){// Quit
                abort();
            }

            else if (response == 'B' or response == 'b'){// Display all
                if (this->size > 0){
                    this->print_all();
                    this->display_main_menu();
                }
                else{// Don't display if list is empty.
                    cout << "Error: This list is empty! \n";
                    this->display_main_menu();
                }

            }

            else if (response == 'C' or response == 'c'){// Populate List
                while(response_number <= 0 and response_number_flag == true){// Don't accept negative numbers or 0s
                cout << "How many? \n";
                cin >> response_number;

                if (cin.good() and response_number > 0){// Makes sure it can read the user input
                        this->populate(response_number, 0.03, 10);
                        response_number_flag = false;
                        this->display_main_menu();
                    }
                    else{
                        cin.clear();// clear input
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        cout << "Error: Invalid input! \n";
                        response_number_flag = true;
                    }
                }
            }

            else if (response == 'D' or response == 'd'){// Analytics Menu
                if (this->size > 0){
                    this->display_analytics_menu(1, this->first);
                }
                else{// Don't open if list is empty.
                    cout << "Error: This list is empty! \n";
                    this->display_main_menu();
                }
            }

            else if (response == 'E' or response == 'e'){// Create New Shirt
                    shirt* new_shirt;
                    string new_collar;
                    string new_cuff;
                    string new_placket;
                    string new_color;
                    float new_price = -1;

                        cout << "\n Collar: ";
                        cin >> new_collar;
                        cout << "\n Cuff: ";
                        cin >> new_cuff;
                        cout << "\n Placket: ";
                        cin >> new_placket;
                        cout << "\n Color: ";
                        cin >> new_color;
                        while (new_price <= 0 and response_number_flag == true){// Don't accept negative numbers or 0s
                            cout << "\n Price: $";
                            cin >> new_price;
                            if (cin.good() and new_price > 0){// Makes sure it can read the user input
                                new_shirt = new shirt(new_collar, new_cuff, new_placket, new_color, new_price);
                                this->create_node(new_shirt);// add shirt to list
                                response_number_flag = false;
                                this->display_main_menu();
                            }
                            else{
                                cin.clear();// clear input
                                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                                cout << "Error: Invalid input! \n";
                                response_number_flag = true;
                            }
                        }
                }
            }

        }



    void display_analytics_menu(int count, node* start){
        char response = '?';
        node* inv_node = start;


        cout << count << ": \n";// Display current item
        cout << "Collar: " <<inv_node->inv_item->get_collar() << "\n";
        cout << "Cuff: " <<inv_node->inv_item->get_cuff() << "\n";
        cout << "Placket: " <<inv_node->inv_item->get_placket() << "\n";
        cout << "Color: " <<inv_node->inv_item->get_color() << "\n";
        cout << "Price: $" <<inv_node->inv_item->get_price() << "\n";
        cout << "\n";

        while (response != 'A' or response != 'a' or response != 'B' or response != 'b' or response != 'C' or response != 'c' or response != 'D' or response != 'd'){
            cout << "A) Main Menu \n"
                 << "B) Previous \n"
                 << "C) Analyze\n"
                 << "D) Next \n";

            cin >> response;


            if (response == 'A' or response == 'a'){// Main Menu
                this->display_main_menu();
            }

            else if (response == 'B' or response == 'b'){// Previous
                if(inv_node->inv_prev != nullptr){
                    count--;// decrement count
                    this->display_analytics_menu(count, inv_node->inv_prev);// go to previous node
                }
                else{
                    count = this->size;// adjust count
                    this->display_analytics_menu(count, this->last);// loop around
                }
            }

            else if (response == 'C' or response == 'c'){// Analyze
                this->node_analytics(inv_node);
            }

            else if (response == 'D' or response == 'd'){// Next
                if(inv_node->inv_next != nullptr){
                    count++;// increment count
                    this->display_analytics_menu(count, inv_node->inv_next);// go to next node
                }
                else{
                    count = 1;// reset count
                    this->display_analytics_menu(count, this->first);// loop around
                }
            }

        }

    }

};
