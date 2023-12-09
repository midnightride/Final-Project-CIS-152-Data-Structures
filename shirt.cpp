// Blake W Hausafus 2023 bwhausafus@dmacc.edu

#include <iostream>
#include <string>

using namespace std;


class shirt{
public:
    string collar;
    string cuff;
    string placket;
    string color;
    float price;

    shirt(string s_collar, string s_cuff, string s_placket, string s_color, float s_price){// constructor
        this->collar = s_collar;
        this->cuff = s_cuff;
        this->placket = s_placket;
        this->color = s_color;
        this->price = s_price;
    }
    //getters
    string get_collar(){
        return this->collar;
    }

    string get_cuff(){
        return this->cuff;
    }

    string get_placket(){
        return this->placket;
    }

    string get_color(){
        return this->color;
    }

    float get_price(){
        return this->price;
    }
    // setters
    void set_collar(string s){
        this->collar = s;
    }

    void set_cuff(string s){
        this->cuff = s;
    }

    void set_placket(string s){
        this->placket = s;
    }

    void set_color(string s){
        this->color = s;
    }

    void set_price(float s){
        this->price = s;
    }

};
