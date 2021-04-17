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
    std::vector<CustRect> test = CustRect::vectRect(100,10);

    std::vector<CustRect> test2;

    // thread
    sf::Thread thread(&newThread,std::ref(test));
    
    // Start the clock
    sf::Clock clock;

    // detect if space pressed
    bool spacepressed = false;

    bool has_ended = false;

    int jj = 0;
    int *jjpointer; 
    int ii = test.size();

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
        if (spacepressed == true && elapsed.asSeconds() > .001 && has_ended == false){
            test[jj].setFillColor(sf::Color::Red);
            test[jj+1].setFillColor(sf::Color::Red);
            test[jj].setFillColor(sf::Color::Green);

            clock.restart();

            if (jj == ii-1){
                int * ptr;
                ptr = &jj;
                *ptr = 0;
                ii--;
                std::cout << "reset loop";
            } else if (ii == 1){
                has_ended = true;
                test[jj].setFillColor(sf::Color::Red);
                test[jj-1].setFillColor(sf::Color::Red);
            }
            
            if (test[jj].rectVal > test[jj+1].rectVal){
                CustRect::swap(test[jj],test[jj+1]);
            }

            jj++;
            
            

            // for(int iter1 = 0; iter1 < test.size()-1; iter1++){
            //     bool hasSwapped = false;
            //     for(int iter2 = 0; iter2 < test.size()-iter1-1; iter2++){
                    
            //         if(test[iter2].rectVal > test[iter2+1].rectVal){
            //             CustRect::swap(test[iter2],test[iter2+1]);
            //             hasSwapped = true;
                        
            //             std::cout << "swap\n";
                        
            //         }
            //     }
            //     if (hasSwapped == true){
            //         std::cout << "display result";
            //         break;
            //     }
            // }
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