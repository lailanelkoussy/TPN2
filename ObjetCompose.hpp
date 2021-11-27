#ifndef OBJETCOMPOSE_HPP
#define OBJETCOMPOSE_HPP

#include <iostream>
#include "ObjetAtomique.hpp"
#include <iostream>
using namespace std;
class ObjetCompose : public ObjetAbst {
private:
    vector<ObjetAtomique*> composants;
    vector<pair<string,u_int >> frequencies;
    void incrementFrequencies(string);
    friend ostream& operator <<(ostream & out, const ObjetCompose& objetCompose);

public:
    ObjetCompose(string);
    ~ObjetCompose();
    string getName() const;
    void setComment(const string&);
    void operator[](ObjetAtomique*&);

};



#endif /* OBJETCOMPOSÉ_HPP */

