#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>


// create one rectangle, sep is vertical location of the rectangle
sf::RectangleShape createRect(float sep){
    // random height value 1-100
    int val = rand() % 100 + 1;
    sf::RectangleShape rect(sf::Vector2f(val,10));
    rect.setFillColor(sf::Color::White);
    rect.setOrigin(0,sep);
    std::cout << val << "\n";
    return rect;
}

// create a vector of n evenly spaced rectangles
std::vector<sf::RectangleShape> vectRect(int numofrects,float sep){
    std::vector<sf::RectangleShape> vRect; 
    for(int i = 1; i <= numofrects + 1; i++){
        sf::RectangleShape temp = createRect(sep*i*5);
        vRect.push_back(temp);
    }
    return vRect;
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    std::vector<sf::RectangleShape> test = vectRect(100,-3);

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