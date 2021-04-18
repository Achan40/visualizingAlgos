#ifndef CUSTRECT
#define CUSTRECT

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>

// custom rectangle object, inheriting from SFML RectangleShape class
class CustRect: public sf::RectangleShape{
    public:
        //value of randomly generated number
        int rectVal; 

        // Default constructor, makes a green rectangle of rand height and fixed width
        CustRect(){
            this->rectVal = rand() % 500 + 1;
            this->setSize(sf::Vector2f(rectVal,10));
            this->setFillColor(sf::Color::Green);
        }

        ~CustRect(){};

        // Set height of rectangle
        // fixed width
        void SetSize(int temp){
            this->rectVal = temp;
            this->setSize(sf::Vector2f(rectVal,10));
        }

        // Get the generated random value
        int GetRandVal(){return rectVal;}

        // function to create a vector of n CustRect objects spaced by some sep value CustRect objects
        static std::vector<CustRect> vectRect(int numofrects,int sep){
            std::vector<CustRect> vRect; 
            for(int i = 0; i <= numofrects - 1; i++){
                CustRect temp;
                temp.setPosition(0,sep*i);
                vRect.push_back(temp);
            }
            return vRect;
        }

        // swap values fucntion
        static void swap(CustRect &x, CustRect &y){
            // Store value(height of rectangle), then swap
            int temp = x.rectVal;
            x.SetSize(y.rectVal);
            y.SetSize(temp);
        }

        // return object
        CustRect operator()() {return *this;}
};

#endif 