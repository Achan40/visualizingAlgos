#include <Sortable.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects
    std::vector<CustRect> x = CustRect::vectRect(50,10);

    Sortable test(x);
    
    // Start the clock
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // sort rectangles when spacebar is pressed
            if (event.key.code == sf::Keyboard::Space){
                test.space_pressed = true;  
            }
        }
        test.bubbleSort(clock,elapsed);

        // draw rectangles of random height upon opening exe
        window.clear();

        for (int i = 0; i < test.vCustRect.size(); i++){
            window.draw(test.vCustRect[i]);
        }
        window.display();
    }

    return 0;
}