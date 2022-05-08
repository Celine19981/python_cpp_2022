
#include <iostream>
#include <pybind11/pybind11.h>

class Fact{
public:
    Fact(int n)
    :_n(n) {}

    static int calculate(int n) {
        if(n == 0) return 1;
        return n * calculate(n-1);
    }

    void print() {
        std::cout << "fact of " << _n << " is equal to: " << calculate(_n) << std::endl;
    }

private:
    int _n;
};

PYBIND11_MODULE(fact, m){
    m.doc() = "Calculate factorial of positif intigers";
    pybind11::class_<Fact>(m, "Fact" )
        .def( pybind11::init< int >() )
        .def( "print", &Fact::print );
}
