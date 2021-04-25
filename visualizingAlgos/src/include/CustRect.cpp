#include "CustRect.h"
// Default constructor, makes a green rectangle of rand height and fixed width
CustRect::CustRect(){
    this->rectVal = rand() % max_val + 1;
    this->setSize(sf::Vector2f(rectVal,width));
    this->setFillColor(sf::Color::White);
}

// Set height of rectangle
// fixed width
void CustRect::SetSize(int temp){
    this->rectVal = temp;
    this->setSize(sf::Vector2f(rectVal,width));
}

// function to create a vector of n CustRect objects spaced by some sep value CustRect objects (defaulted to 10)
std::vector<CustRect> CustRect::vectRect(int numofrects, int sep) { 
    std::vector<CustRect> vRect; 
    for(int i = 0; i <= numofrects - 1; i++){
        CustRect temp;
        temp.setPosition(0,sep*i);
        vRect.push_back(temp);
    }
    return vRect;
}

// swap values fucntion
void CustRect::swap(CustRect &x, CustRect &y){
    // Store value(height of rectangle), then swap
    int temp = x.rectVal;
    x.SetSize(y.rectVal);
    y.SetSize(temp);
}
