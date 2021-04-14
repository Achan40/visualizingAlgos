#include <SFML/Graphics.hpp>

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <string>

// custom rectangle object, inheriting from SFML RectangleShape class
class CustRect: public sf::RectangleShape{
    public:
        // Default constructor, makes a green rectangle of rand height w width of 10
        CustRect(){
            this->rectVal = rand() % 500 + 1;
            this->setSize(sf::Vector2f(rectVal,10));
            this->setFillColor(sf::Color::Green);
        }

        // Set y position, useful when creating a vector of our objects
        void SetPos(float somePos){
            this->somePos = somePos;
            this->setOrigin(0,somePos);
        }

        // Get the generated random value
        int GetRandVal(){return rectVal;}

        // Get the position value
        int GetPos(){return somePos;}

        int rectVal;
        int somePos;
};

// function to create a vector of n evenly spaced rectangles
std::vector<CustRect> vectRect(int numofrects,int sep){
    std::vector<CustRect> vRect; 
    for(int i = 0; i <= numofrects - 1; i++){
        CustRect temp;
        temp.SetPos(sep*i);
        vRect.push_back(temp);
    }
    return vRect;
}

// swap object values function for use in bubble sort function
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

// void swapPos(int *x, int *y, CustRect tempClass){
//     int temp = *x;
//     *x = *y;
//     *y = temp;
//     tempClass.SetPos(temp);
// }

// function to implement bubble sort for vector of CustRect objects
void bubbleSort(std::vector<CustRect> &someVect){
    int i, j;
    for(i = 0; i < someVect.size()-1; i++){
        for(j = 0; j < someVect.size()-i-1; j++){
            if(someVect[j].rectVal > someVect[j + 1].rectVal){
                swap(&someVect[j].rectVal, &someVect[j+1].rectVal);
                swap(&someVect[j].somePos, &someVect[j+1].somePos);
                someVect[j+1].SetPos(someVect[j].somePos);
            }
        }
    }
}


int main()
{
    // initialize random seed
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    std::vector<CustRect> test = vectRect(100,-10);

    for(int i = 0; i < test.size(); i++){
        printf("%d ", test[i].rectVal);
        printf("%d ", test[i].somePos);
    }
    std::cout << "\n";

    bubbleSort(test);

    for(int i = 0; i < test.size(); i++){
        printf("%d ", test[i].rectVal);
        printf("%d ", test[i].somePos);
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(int i = 0; i < test.size(); i++){
            window.draw(test[i]);
        }
        window.display();
    }

    return 0;
}