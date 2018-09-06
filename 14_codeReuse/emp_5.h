#ifndef PRIMERPLUS_EMP_5_H
#define PRIMERPLUS_EMP_5_H

#include <iostream>
#include <string>

using std::string;

class abstr_emp
{
private:
    string fname;
    string lname;
    string job;
public:
    abstr_emp();
    abstr_emp(const string & fn, const string & ln,
            const string & j) :
            fname(fn), lname(ln), job(j){};
    virtual void ShowAll() const;
    virtual void SetAll();
    friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);
    virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp
{
public:
    employee() : abstr_emp() {};
    employee(const string & fn, const string & ln,
             const string & j): abstr_emp(fn, ln, j) {};
    virtual void ShowAll() const;
    virtual void SetAll();
};

class manager : virtual public abstr_emp
{
private:
    int inchargeof;
protected:
    int InChargeOf() const { return inchargeof;}
    int & InChargeOf() {return inchargeof;}
public:
    manager() : abstr_emp() {inchargeof = 0;};
    manager(const string & fn, const string & ln,
            const string & j, int ico = 0):
            abstr_emp(fn, ln ,j), inchargeof(ico) {};
    manager(const abstr_emp & e, int ico) :
            abstr_emp(e), inchargeof(ico){};
//    manager(const manager & m);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class fink : virtual  public abstr_emp
{
private:
    string reportsto;
protected:
    const string ReportsTo() const { return reportsto;}
    string & ReportsTo() {return reportsto;}
public:
    fink():abstr_emp() {};
    fink(const string & fn, const string & ln,
            const string & j, const string & rpo):
            abstr_emp(fn, ln, j), reportsto(rpo) {};
    fink(const abstr_emp & e, const string & rpo) :
            abstr_emp(e), reportsto(rpo) {};
//    fink(const fink & f);
    virtual void ShowAll() const;
    virtual void SetAll();
};

class highfink : public manager, public fink
{
public:
    highfink() : manager(), fink() {};
    highfink(const string & fn, const string & ln,
             const string & j, const string & rpo,
             int ico):
             manager(fn, ln,j, ico), fink(fn, ln,j,rpo) {};
    highfink(const abstr_emp & e, const std::string rpo, int ico):
             manager(e, ico), fink(e, rpo) {};
    highfink(const fink & f, int ico):
             manager((abstr_emp &)f, ico),fink(f) {};
    highfink(const manager & m, const std::string rpo):
             manager(m), fink((abstr_emp &)m,rpo) {};
    highfink(const highfink & h):
             manager((manager &) h), fink((fink &) h) {};
    virtual void ShowAll() const;
    virtual void SetAll();
};


#endif //PRIMERPLUS_EMP_5_H
