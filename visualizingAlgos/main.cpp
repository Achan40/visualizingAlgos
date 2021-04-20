#include <Sortable.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects. (number of objects, some separator)
    std::vector<CustRect> vCustRect = CustRect::vectRect(100);

    // create a Sortable object which takes in a vector of CustRect objects
    Sortable SortableV(vCustRect);

    while (window.isOpen())
    {
        // sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // sort rectangles using bubble sort when the B key is pressed
            if (event.key.code == sf::Keyboard::B){
                SortableV.begin_bubble = true;  
            }
            // sort rectangles using insertion sort when the I key is pressed
            if (event.key.code == sf::Keyboard::I){
                SortableV.begin_insertion_sort = true;  
            }
            // reset Sortable object when R key is pressed
            if (event.key.code == sf::Keyboard::R){
                SortableV.reset();
            }
        }
        /* The bubbleSort method updates the vector every swap/move. Since SFML output
        is in a permanant loop while the window is open, we had to accout for this in our
        implementation
        */
        SortableV.bubbleSort();
        SortableV.insertionSort();

        // begin drawing entire vector
        window.clear();

        for (int i = 0; i < SortableV.vCustRect.size(); i++){
            window.draw(SortableV.vCustRect[i]);
        }

        window.display();
    }

    return 0;
}