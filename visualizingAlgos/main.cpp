#include <SFML/Graphics.hpp>
#include <vector>

// create one rectangle, val is height of rectangle, sep is vertical location of the rectangle
sf::RectangleShape createRect(int val, float sep){
    sf::RectangleShape rect(sf::Vector2f(val,20));
    rect.setFillColor(sf::Color::White);
    rect.setOrigin(0,sep);
    return rect;
}

// create a vector of n evenly spaced rectangles
std::vector<sf::RectangleShape> vectRect(int numofrects, int val,float sep){
    std::vector<sf::RectangleShape> vRect; 
    for(int i = 1; i < numofrects; i++){
        sf::RectangleShape temp = createRect(val, sep*i*5);
        vRect.push_back(temp);
    }
    return vRect;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

    std::vector<sf::RectangleShape> test = vectRect(10,100,-5);

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