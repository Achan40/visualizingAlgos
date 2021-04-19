#ifndef SORTABLE
#define SORTABLE

#include <CustRect.h>

class Sortable{
    public:
        std::vector<CustRect> vCustRect;
        std::vector<CustRect> vResetCustRect;
        sf::Clock clock;
        int jj = 0;
        int ii;
        bool begin_bubble = false;
        bool has_ended = false;
        float sort_speed = .01;

        Sortable(std::vector<CustRect> vector){
            this-> vCustRect = vector;
            this-> vResetCustRect = vector;
            this-> ii = vector.size();
        }

        ~Sortable(){};

        // Reset object if bubble sort has occured
        void resetBubble(){
            vCustRect = vResetCustRect; 
            jj = 0;
            ii = vCustRect.size();
            begin_bubble = false;
            has_ended = false;
        }

        /* Implementing bubble sort. When the SFML window is open, the program is constantly looping.
        Therefore, it is not possible implement bubble sort the usual way with a loop (otherwise SFML will
        run through the bubble sort loop before displaying the CustRect objects).
        */
        void bubbleSort(){
            // create time object using the clock. This is so we can manage how fast each iteration occurs.
            sf::Time elapsed = clock.getElapsedTime();
            // If the a certain key is pressed, the length of time since the method was called is greater than n seconds, and the sort has not ended...
            if (begin_bubble == true && elapsed.asSeconds() > sort_speed && has_ended == false){
                // Set color, so that we can see which shape is being sorted at the moment
                vCustRect[jj].setFillColor(sf::Color::Green);
                vCustRect[jj+1].setFillColor(sf::Color::Green);
                vCustRect[jj].setFillColor(sf::Color::White);

                // resart the clock so our n second timer can begin again
                clock.restart();

                // swap the current shape with next shape if the next shape is larger
                if (vCustRect[jj].rectVal > vCustRect[jj+1].rectVal){
                    CustRect::swap(vCustRect[jj],vCustRect[jj+1]);
                }

                // increment "inner loop" by one every time the method is called
                jj++;

                // decrease "outer loop" by one, if the inner loop is equal to one less than the size of the vector.
                // Then, decrease the "size" of the vector by one (since that item has been successfully sorted).
                if (jj == ii-1){
                    jj = 0;
                    ii--;
                // end condition. color remaining shapes.
                } else if (ii == 1){
                    has_ended = true;
                    vCustRect[jj].setFillColor(sf::Color::Green);
                    vCustRect[jj-1].setFillColor(sf::Color::Green);
                }
            }
        }
};

#endif 