#include <iostream>
#include "matrix.h"
#include <string>
#include <vector>


int main()
{
    matrix *A;
    char choice;
    double input;
    std::vector<double> v;
    bool valid = false;
    while (!valid)
    {
        std::cout << "(2)x2 or (3)x3 matrix\n";
        std::cin >> choice;
        if (choice == '2')
        {
            for (int i = 0; i < 4; i++)
            {
                std::cout << "Please input element " << twobytwoindex(i) << "\n";
                std::cin >> input;
                v.push_back(input);
            }
            A = new twobytwo(v[0], v[1], v[2], v[3]);
            valid = true;
        }
        if (choice == '3')
        {
            for (int i = 0; i < 9; i++)
            {
                std::cout << "Please input element " << threebythreeindex(i) << "\n";
                std::cin >> input;
                v.push_back(input);
            }
            A = new threebythree(v[0], v[1], v[2],
                                 v[3], v[4], v[5],
                                 v[6], v[7], v[8]);
            valid = true;
        }
        if (valid == false)
        {
            std::cout << "please insert choice again\n";
        }
    }

    valid = false;

    while (!valid)
    {
        std::cout << "Your matrix:\n";
        A->print();
        std::cout << "Do you want to:\n(t)ranspose the matrix\ncalculate the (d)eterminant\nChoice: ";
        std::cin >> choice;
        if (choice == 't')
        {
            A->transpose();
            std::cout << "Transposed matris is\n";
            A->print();
            valid = true;
        }
        if (choice == 'd')
        {
            std::cout << "The determinent of your matrix is "
                      << A->get_determinant() << "\n";
            valid = true;
        }
        if (valid == false)
        {
            std::cout << "invalid choice";
        }
    }
    delete A;
    return 0;
}