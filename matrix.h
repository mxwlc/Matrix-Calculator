//matrix.hpp
#include <iostream>
#include <map>
#include <string>


typedef double elements;

class matrix
{
public:
    virtual void transpose(){};
    virtual elements get_determinant() const = 0;
    virtual void print(){};
    virtual ~matrix(){};
};

class twobytwo : public matrix
{
public:
    //|a11 a12|
    //|a21 a22|
    twobytwo(elements a1, elements b1, elements c1, elements d1) : a11(a1), a12(b1), a21(c1), a22(d1) {}

    elements get_determinant() const
    {
        return a11 * a22 - a12 * a21;
    }
    void print()
    {
        std::cout << "Matrix: \n"
                  << a11 << " , " << a12 << "\n"
                  << a21 << " , " << a22 << "\n";
    }

    void transpose()
    {
        elements tmp;
        tmp = a12;
        a12 = a21;
        a21 = tmp;
    }

private:
    elements a11, a12, a21, a22;
};

class threebythree : public matrix
{
public:
    threebythree(elements a11, elements a12, elements a13,
                 elements a21, elements a22, elements a23,
                 elements a31, elements a32, elements a33) : a11(a11), a12(a12), a13(a13),
                                              a21(a21), a22(a22), a23(a23),
                                              a31(a31), a32(a32), a33(a33) {}

    elements get_determinant() const
    {
        elements sub1, sub2, sub3;
        sub1 = a11 * (a22 * a33 - a23 * a32);
        sub2 = a12 * (a21 * a33 - a23 * a31);
        sub3 = a13 * (a21 * a32 - a22 * a31);

        return sub1 + sub2 + sub3;
    }

    void print()
    {
        std::cout << "Matrix:\n" << a11 << " , " << a12 << " , " << a13 << "\n"
                  << a21 << " , " << a22 << " , " << a23 << "\n"
                  << a31 << " , " << a32 << " , " << a33 << "\n";
    }

    void transpose(){
        elements tmp;
        tmp = a12;
        a12 = a21;
        a21 = tmp;

        tmp = a13;
        a13 = a31;
        a31 = tmp;

        tmp = a23;
        a23 = a32;
        a32 = tmp;
    }

private:
    elements a11, a12, a13, a21, a22, a23, a31, a32, a33;
};

std::string threebythreeindex(int index){
    std::map<int,std::string> table;
    table[0] = "1,1";
    table[1] = "1,2";
    table[2] = "1,3";
    table[3] = "2,1";
    table[4] = "2,2";
    table[5] = "2,3";
    table[6] = "3,1";
    table[7] = "3,2";
    table[8] = "3,3";

    return table[index];
}

std::string twobytwoindex(int index){
    std::map<int,std::string> table;
    table[0] = "1,1";
    table[1] = "1,2";
    table[2] = "2,1";
    table[3] = "2,2";
    return table[index];
}