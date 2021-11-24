#ifndef OBJETATOMIQUE_HPP
#define OBJETATOMIQUE_HPP

#include <iostream>
#include "ObjetAbst.hpp"


using namespace std;

class ObjetAtomique : public ObjetAbst {

private:
    ObjetAtomique(const string &name);
    friend ObjetAtomique* ObjetAbst::forge(const string& name);
    friend vector<pair<ObjetAtomique*,int>> initializeVector();

public:
    void setComment(const string&);
    string getName() const;
    ~ObjetAtomique();
};

#endif
