#include <functional>
#include <CustRect.h>

//thread testing
sf::Mutex mutex;
void newThread(std::vector<CustRect> &test){
    for(int i = 0; i < test.size(); i++){
        test[i].setFillColor(sf::Color::Red);
        std::cout << "THIS IS A THREAD" << "\n";
        // sf::sleep(sf::milliseconds(100));
        break;
    }
}

int main()
{
    // initialize random seed
    srand(time(NULL));

    // render window size and window heading
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "visualizingAlgos");

    // create a vector of CustRect objects
    std::vector<CustRect> test = CustRect::vectRect(10,10);

    std::vector<CustRect> test2;

    // thread
    sf::Thread thread(&newThread,std::ref(test));

    int loop = 0;
    int jj = 0;
    
    // Start the clock
    sf::Clock clock;

    // detect if space pressed
    bool spacepressed = false;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.getElapsedTime();
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            // sort rectangles when spacebar is pressed
            // function to implement bubble sort for vector of CustRect objects
            if (event.key.code == sf::Keyboard::Space){
                spacepressed = true;
                
                // CustRect::bubbleSort(test);

                // if (jj+1 == test.size()){
                //     jj = 0;
                // }

                // if (test[jj].rectVal > test[jj+1].rectVal){
                //     CustRect::swap(test[jj],test[jj+1]);
                //     std::cout << jj << "\n";
                // }
                // jj++;

                // janky code.. last resort if threads don't pan out...
                // for (loop; loop < test.size()-1; loop++){
                //     test[loop].setFillColor(sf::Color::Red);
                //     std::cout << loop << "\n";
                //     std::cout << "stop" << "\n";
                //     loop++;
                //     //sf::sleep(sf::milliseconds(170));
                //     break; 
                // }
                // sf::sleep(sf::milliseconds(170));
                
                // //thread object
                // sf::Thread thread(&newThread,std::ref(test));
                
            }
        }
        if (spacepressed == true && elapsed.asSeconds() > 3){
            std::cout << "Restart" << "\n";
            clock.restart();
        }
        // draw rectangles of random height upon opening exe
        window.clear();

        for (int i = 0; i < test.size(); i++){
            window.draw(test[i]);
        }
        window.display();
    }

    return 0;
}