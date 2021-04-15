#include <SFML/Graphics.hpp>
#include <CustRect.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects
    std::vector<CustRect> test = CustRect::vectRect(100,10);
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // sort rectangles when spacebar is pressed
            if (event.key.code == sf::Keyboard::Space){
                // std::this_thread::sleep_for(std::chrono::milliseconds(3000));
                CustRect::bubbleSort(test);
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