#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>

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

        int rectVal;
};

// function to create a vector of n evenly spaced rectangles
std::vector<CustRect> vectRect(int numofrects,int sep){
    std::vector<CustRect> vRect; 
    for(int i = 0; i <= numofrects - 1; i++){
        CustRect temp;
        temp.setPosition(0,sep*i);
        vRect.push_back(temp);
    }
    return vRect;
}

// function to implement bubble sort for vector of CustRect objects
void bubbleSort(std::vector<CustRect> &someVect){
    int i, j;
    for(i = 0; i < someVect.size()-1; i++){
        for(j = 0; j < someVect.size()-i-1; j++){
            if(someVect[j].rectVal > someVect[j+1].rectVal){
                // Store value(height of rectangle), then swap
                int temp = someVect[j].rectVal;
                someVect[j].SetSize(someVect[j+1].rectVal);
                someVect[j+1].SetSize(temp);
            }
        }
    }
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    // create a vector of CustRect objects
    std::vector<CustRect> test = vectRect(100,10);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // sort rectangles when spacebar is pressed
            if (event.key.code == sf::Keyboard::Space){
                
                bubbleSort(test);
                
            }
        }
        window.clear();
        // draw rectangles of random height upon opening exe
        for(int i = 0; i < test.size(); i++){
            window.draw(test[i]);
        }
        window.display();
    }

    return 0;
}