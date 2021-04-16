
#include <CustRect.h>

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects
    std::vector<CustRect> test = CustRect::vectRect(60,10);

    int ii = test.size()-1;
    int jj = 0;
    int loop = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // sort rectangles when spacebar is pressed
            // function to implement bubble sort for vector of CustRect objects
            if (event.key.code == sf::Keyboard::Space){
                // jj += 1;
                // // CustRect::bubbleSort(test);
                // if (test[jj].rectVal > test[jj+1].rectVal){
                //     CustRect::swap(test[jj],test[jj+1]);
                //     std::cout << jj << "\n";
                // }

                // janky code.. last resort if threads don't pan out...
                for (loop; loop < test.size()-1; loop++){
                    test[loop].setFillColor(sf::Color::Red);
                    std::cout << loop << "\n";
                    std::cout << "stop" << "\n";
                    loop++;
                    break;
                    // sf::sleep(sf::milliseconds(170));
                }
            }
        }
        window.clear();
        // draw rectangles of random height upon opening exe
        for(auto i: test){
            window.draw(i);
        }
        window.display();
    }

    return 0;
}