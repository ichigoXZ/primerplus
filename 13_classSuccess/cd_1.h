#ifndef PRIMERPLUS_CD_H
#define PRIMERPLUS_CD_H

namespace  Cd1 {
// base class
    class Cd {
    private:
        char performers[50];
        char label[20];
        int selections;     // number of selections
        double playtime;    // playing time in minutes
    public:
        Cd(char *s1, char *s2, int n, double x);

        Cd(const Cd &d);

        Cd();

        virtual void Report() const;    // reports all CD data
//    Cd & operator=(const Cd & d);
    };

    class Classic : public Cd {
    private:
        char hit[80];
    public:
        Classic(char *s1, char *s2, char *s3, int n, double x);

        Classic(const Classic &d);

        Classic();

        virtual void Report() const;    // reports all CD data
//    Classic & operator=(const Classic & d);
    };
}
#endif //PRIMERPLUS_CD_H
