#ifndef PRIMERPLUS_EXEC_MEAN_H
#define PRIMERPLUS_EXEC_MEAN_H

// exc_mean.h  -- exception classes for hmean(), gmean()
#include <iostream>
#include <stdexcept>

namespace bad_mean2 {

    class bad_hmean : public std::logic_error {
    public:
        bad_hmean(const std::string &s = "hmean() invalid arguments: a = -b") :
                std::logic_error(s) {}
    };

    class bad_gmean : public std::logic_error {
    public:
        double v1;
        double v2;

        bad_gmean(double a, double b, const std::string &s = "gmean() arguments should be >= 0") :
                v1(a), v2(b), std::logic_error(s) {}
    };

}

#endif //PRIMERPLUS_EXEC_MEAN_H
