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
    string getName();
    //TODO: need to make this go back to ObjAbs class and increase availability by 1
    ~ObjetAtomique();
};

#endif
