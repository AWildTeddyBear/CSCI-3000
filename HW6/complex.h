/*
Author: AWildTeddyBear
Filename: complex.h
Description: Houses the classes needed for complex number operations
*/

class complex{
    private:
        //Private Vars
        int real;
        int imag;    
    public:
        //Constructor function
        complex(int r = 0, int i = 0): real(r), imag(i) {};

        //Function Prototypes
        complex operator+(const complex& c);
        complex operator-(const complex& c);
        complex operator*(const complex& c);
        complex operator/(const complex& c);
     	bool operator==(const complex& c);
     	void print(void);
};