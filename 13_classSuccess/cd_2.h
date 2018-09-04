#ifndef PRIMERPLUS_CD_2_H
#define PRIMERPLUS_CD_2_H

namespace Cd2 {
// base class
    class Cd {
    private:
        char *performers;
        char *label;
        int selections;     // number of selections
        double playtime;    // playing time in minutes
    public:
        Cd(char *s1, char *s2, int n, double x);
        Cd(const Cd &d);
        Cd();
        ~Cd();
        virtual void Report() const;    // reports all CD data
        Cd & operator=(const Cd & d);
    };

    class Classic : public Cd {
    private:
        char * hit;
    public:
        Classic(char *s1, char *s2, char *s3, int n, double x);
        Classic(const Classic &d);
        Classic();
        ~Classic();
        virtual void Report() const;    // reports all CD data
        Classic & operator=(const Classic & d);
    };
}
#endif //PRIMERPLUS_CD_2_H
