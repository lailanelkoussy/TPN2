#ifndef OBJETCOMPOSE_HPP
#define OBJETCOMPOSE_HPP

#include <iostream>
#include "ObjetAtomique.hpp"

class ObjetCompose : public ObjetAbst {
private:
    vector<ObjetAtomique*> composants;
public:
    ObjetCompose(string);
    ~ObjetCompose();
    string getName() const;
    void setComment(const string&);
    void operator[](ObjetAtomique*&);

};


#endif /* OBJETCOMPOSÉ_HPP */

