#ifndef CUSTRECT
#define CUSTRECT

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <chrono>
#include <mingw-std-threads/mingw.thread.h>

// custom rectangle object, inheriting from SFML RectangleShape class
class CustRect: public sf::RectangleShape{
    public:
        // Default constructor, makes a green rectangle of rand height w width of 10
        CustRect(){
            this->rectVal = rand() % 500 + 1;
            this->setSize(sf::Vector2f(rectVal,10));
            this->setFillColor(sf::Color::Green);
        }

        // Set height of rectangle
        // fixed width of 10
        void SetSize(int temp){
            this->rectVal = temp;
            this->setSize(sf::Vector2f(rectVal,10));
        }

        // Get the generated random value
        int GetRandVal(){return rectVal;}

        // function to create a vector of n evenly spaced CustRect objects
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

        // function to implement bubble sort for vector of CustRect objects
        static void bubbleSort(std::vector<CustRect> &vector){
            int i, j;
            for(i = 0; i < vector.size()-1; i++){
                for(j = 0; j < vector.size()-i-1; j++){
                    if(vector[j].rectVal > vector[j+1].rectVal){
                        swap(vector[j],vector[j+1]);
                    }
                }
            }
        }

        int rectVal;
};

#endif 