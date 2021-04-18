#ifndef SORTABLE
#define SORTABLE

#include <CustRect.h>

class Sortable{
    public:
        std::vector<CustRect> vCustRect;
        int jj;
        int ii;
        bool space_pressed;
        bool has_ended;

        Sortable(std::vector<CustRect> vector){
            this-> vCustRect = vector;
            this-> jj = 0;
            this-> ii = vector.size();
            this-> space_pressed = false;
            this-> has_ended = false;
        }
        ~Sortable(){};

        void bubbleSort(sf::Clock &clock, sf::Time elapsed){     
            if (space_pressed == true && elapsed.asSeconds() > .01 && has_ended == false){
                vCustRect[jj].setFillColor(sf::Color::Red);
                vCustRect[jj+1].setFillColor(sf::Color::Red);
                vCustRect[jj].setFillColor(sf::Color::Green);

                clock.restart();

                if (vCustRect[jj].rectVal > vCustRect[jj+1].rectVal){
                    CustRect::swap(vCustRect[jj],vCustRect[jj+1]);
                }

                std::cout << jj << "\n";

                jj++;

                if (jj == ii-1){
                    jj = 0;
                    ii--;
                } else if (ii == 1){
                    has_ended = true;
                    vCustRect[jj].setFillColor(sf::Color::Red);
                    vCustRect[jj-1].setFillColor(sf::Color::Red);
                }
            }
        }
};

#endif 