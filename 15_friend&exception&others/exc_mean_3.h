#ifndef PRIMERPLUS_EXC_MEAN_3_H
#define PRIMERPLUS_EXC_MEAN_3_H
#include <iostream>
#include <stdexcept>

namespace bad_mean3 {

    class bad_mean : public std::logic_error {
    private:
        double v1;
        double v2;
    public:
        bad_mean(double a, double b, const std::string &s) :
                v1(a), v2(b), std::logic_error(s) {};

        void report();
    };

    class bad_hmean : public bad_mean {
    public:
        bad_hmean(double a, double b, const std::string &s = "Bad hmean") :
                bad_mean(a, b, s) {}
    };

    class bad_gmean : public bad_mean {
    public:
        bad_gmean(double a, double b, const std::string &s = "Bad gmean") :
                bad_mean(a, b, s) {}
    };

    void bad_mean::report() {
        std::cout << what() <<std::endl;
        std::cout << "v1: " << v1 << "\tv2: " << v2 << std::endl;
    }

}

#endif //PRIMERPLUS_EXC_MEAN_3_H
