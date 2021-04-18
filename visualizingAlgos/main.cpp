#include <Sortable.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects. (number of objects, some separator)
    std::vector<CustRect> x = CustRect::vectRect(100,10);

    // create a Sortable object which takes in a vector of CustRect objects
    Sortable test(x);

    while (window.isOpen())
    {
        // sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // sort rectangles when the B key is pressed
            if (event.key.code == sf::Keyboard::B){
                test.begin_bubble = true;  
            }
            // reset Sortable object when R key is pressed
            if (event.key.code == sf::Keyboard::R){
                test.vCustRect = test.vResetCustRect; 
                test.begin_bubble = false;
                test.has_ended = false;
            }
        }
        /* The bubbleSort method updates the vector every swap/move. Since SFML output
        is in a permanant loop while the window is open, we had to accout for this in our
        implementation
        */
        test.bubbleSort();

        // begin drawing entire vector
        window.clear();

        for (int i = 0; i < test.vCustRect.size(); i++){
            window.draw(test.vCustRect[i]);
        }

        window.display();
    }

    return 0;
}