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
        /* value of randomly generated number, width of each rectangle, max value of randomly generated number, 
        some separator between each rectangle*/
        int rectVal; 
        int width = 10;
        int max_val = 500;

        // Default constructor, makes a green rectangle of rand height and fixed width
        CustRect();

        ~CustRect(){};

        // Set height of rectangle
        // fixed width
        void SetSize(int temp);

        // function to create a vector of n CustRect objects spaced by some sep value CustRect objects (defaulted to 10)
        static std::vector<CustRect> vectRect(int numofrects, int sep = 10);
        
        // swap values fucntion
        static void swap(CustRect &x, CustRect &y);
};

#endif 