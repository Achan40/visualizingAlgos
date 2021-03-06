#include "Sortable.h"

// Constructor
Sortable::Sortable(std::vector<CustRect> vector){
    this-> vCustRect = vector;
    this-> vResetCustRect = vector;
    this-> ii = vector.size();
}

// Reset object
void Sortable::reset(){
    // Reset vector
    vCustRect = vResetCustRect; 

    // Reset bubble sort variables
    jj = 0;
    ii = vCustRect.size();
    begin_bubble = false;

    // Reset Insertion sort variables
    i = 1;
    j = i - 1;
    key = vCustRect[i].rectVal;
    begin_insertion_sort = false;

    // Reset Shell sort variables
    ss_n = vCustRect.size()+1;
    ss_gap = ss_n/2;
    ss_i = ss_gap;
    ss_temp;
    ss_j = ss_i;
    ssinner = false;
    ssmiddle = false;
    begin_shell_sort = false;

    has_ended = false;
}

/* Implementing bubble sort. When the SFML window is open, the program is constantly looping.
Therefore, it is not possible implement bubble sort the usual way with a loop (otherwise SFML will
run through the bubble sort loop before displaying the CustRect objects).
*/
void Sortable::bubbleSort(){
    // create time object using the clock. This is so we can manage how fast each iteration occurs.
    sf::Time elapsed = clock.getElapsedTime();
    // If the a certain key is pressed, the length of time since the method was called is greater than n seconds, and the sort has not ended...
    if (begin_bubble == true && elapsed.asSeconds() > sort_speed && has_ended == false){
        // resart the clock so our n second timer can begin again
        clock.restart();

        // Set color, so that we can see which shape is being sorted at the moment
        vCustRect[jj].setFillColor(sf::Color::Green);
        vCustRect[jj+1].setFillColor(sf::Color::Green);
        vCustRect[jj].setFillColor(sf::Color::White);

        
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

// Implement insetion sort
void Sortable::insertionSort(){
    // create time object using the clock. This is so we can manage how fast each iteration occurs.
    sf::Time elapsed = clock.getElapsedTime(); 
    if (begin_insertion_sort == true && elapsed.asSeconds() > sort_speed && has_ended == false){
        // resart the clock so our n second timer can begin again
        clock.restart();

        // Set color, so that we can see which shape is being sorted at the moment
        vCustRect[j+1].setFillColor(sf::Color::Green);
        vCustRect[j].setFillColor(sf::Color::Green);
        vCustRect[j+1].setFillColor(sf::Color::White);

        // "Outer loop" of insertion sort. Boolean condition so this code doesn't execute while "inner loop" is ongoing
        if (inner_loop == false){
            // on start, store the value of the ith rectangle (where i = 1 at start)
            key = vCustRect[i].rectVal;
            // every time "Outer loop" occurs, set j to be 1 less than i.
            j = i - 1;
        }

        // if the jth rectangle is larger than the ith rectangle, swap the jth rectangle and the j+1 rectangle,
        // until the ith rectangle is the largest. (move smaller values down the chain)
        if ( j >= 0 && vCustRect[j].rectVal > key){
            CustRect::swap(vCustRect[j], vCustRect[j+1]);
            // move down the chain by one. Set inner_loop = true, so that "outer loop" code does not execute.
            j--;
            inner_loop = true;
            
            // j cannot be a negative value, if it is, set it to zero
            if (j<0){
                j = 0;
            }
        }
        // If the iteration of "inner loop" is fully sorted, increment outer loop by one
        else {
            inner_loop = false;
            i++;
        }

        // end condition
        if (i == vCustRect.size()){
            has_ended = true;
            inner_loop = false;
        }
        
    }
}

// implement shell sort
void Sortable::shellSort(){
    sf::Time elapsed = clock.getElapsedTime();
    if(begin_shell_sort == true && elapsed.asSeconds() > sort_speed && has_ended == false){
        clock.restart();

        // outer loop start condition
        if (ssmiddle == false && ssinner == false){
            // reset middle loop starting variable everytime the outerloop starts
            ss_i = ss_gap;                  

        // middle loop starts when inner loop has not started
        } if (ssinner == false){
            // set flag
            ssmiddle = true;
            // setting temp variable, which is used in the inner loop, this temp variable resets when
            // inner loop is finished and another iteration of the middle lopp is started
            ss_temp = vCustRect[ss_i].rectVal;
            
            // reset inner loop starting variable every iteration of a middle loop
            ss_j = ss_i;
        }

        // inner loop start condition, when a middle loop has begun
        if (ssmiddle == true){
            // set flag
            ssinner = true;
            // Set color, so that we can see which shape is being sorted at the moment
            
            // an insertion sort depending on a gap
            if (ss_j >= ss_gap && vCustRect[ss_j - ss_gap].rectVal > ss_temp) {
                CustRect::swap(vCustRect[ss_j],vCustRect[ss_j - ss_gap]);
                
                
            // inner loop ends if condition is not met
            } else {
                ssinner = false;
                // increment middle loop when inner loop ends
                ss_i += 1;
            }
            // increment outer loop
            ss_j -= ss_gap;
        }

        // middle loop end condition
        if (ss_i >= ss_n && ssinner == false) {
            // when middle loop ends, increment the outer loop
            ss_gap /= 2;
            // set flag
            ssmiddle = false;
        } 

        // outer loop end condition
        if (ss_gap <= 0 && ssmiddle == false ) {
            has_ended = true;
        } 
        
    }
}