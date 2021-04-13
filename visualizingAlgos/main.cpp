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

        // Set y position, useful when creating a vector of our objects
        void SetY(float someY){this->setOrigin(0,someY);}

        // Get the generated random value
        int GetRandVal(){return rectVal;}

    private:
        int rectVal;
};

// function to create a vector of n evenly spaced rectangles
std::vector<CustRect> vectRect(int numofrects,float sep){
    std::vector<CustRect> vRect; 
    for(int i = 1; i <= numofrects + 1; i++){
        CustRect temp;
        temp.SetY(sep*i);
        vRect.push_back(temp);
    }
    return vRect;
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    std::vector<CustRect> test = vectRect(100,-10);

    for(int i = 1; i < test.size(); i++){
        std::cout << test[i].GetRandVal() << "\n";
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i = 1; i < test.size(); i++){
            window.draw(test[i]);
        }
        window.display();
    }

    return 0;
}