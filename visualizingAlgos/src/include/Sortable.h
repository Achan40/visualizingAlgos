#ifndef SORTABLE
#define SORTABLE

#include <CustRect.cpp>

class Sortable{
    public:
        std::vector<CustRect> vCustRect;
        std::vector<CustRect> vResetCustRect;
        sf::Clock clock;
        // flag, has sorting ended or not
        bool has_ended = false;
        // speed of sorting
        float sort_speed = .01;

        // bubble sort variables
        int jj = 0;
        int ii;
        bool begin_bubble = false;

        // insertion sort variables
        int j;
        int i = 1;
        int key;
        bool inner_loop = false;
        bool begin_insertion_sort = false;

        // shell sort variables
        int ss_n = vCustRect.size();
        // using a gap size of n/2
        int ss_gap = ss_n/2;
        int ss_i = ss_gap;
        int ss_temp;
        int ss_j = ss_i;
        bool ssinner = false;
        bool ssmiddle = false;
        bool begin_shell_sort = false;

        // Constructor, requires a vector of CustRect objects
        Sortable(std::vector<CustRect> vector);

        // Destructor
        ~Sortable(){};

        // Reset object tp initial state
        void reset();

        // bubble sort algorithm
        void bubbleSort();

        // insertion sort algorithm
        void insertionSort();

        // shell sort algorithm
        void shellSort();

};

#endif 