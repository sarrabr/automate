#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main()
{
    int nb_symbole, nb_etat, nb_Trans, nb_Final;
    string symbole, transition, etat, mot, fiinal;
    vector <string> X,Q,Trans,F;
    char choice;
    cout<<" on va entrer l'automate"<<endl;
do{
    cout << "\nCombien de Symboles ?  ";
    cin >> nb_symbole;
  }while(nb_symbole < 0);
    cout << "Enter Les Symboles : ";
    for(int i = 0; i < nb_symbole; i++){
        cin >> symbole;
        X.push_back(symbole);
    }
do{
    cout << "Combien d' etats  : ";
    cin >> nb_etat;
  }while(nb_etat < 0);
    cout << "Enter Les Etats : ";
    for(int i = 0; i < nb_etat; i++){
        cin >> etat;
        Q.push_back(etat);
    }

do{
    cout << "\nCombien de Transitions: " ;
    cin >> nb_Trans;
  }while(nb_Trans < 0);
    cout << "   Entrer toutes les transations sous la forme suivante <etat,symbole,etat>: ";
    for(int i = 0; i < nb_Trans; i++){
        cin >> transition;
        Trans.push_back(transition);
    }
do{
    cout << "\nCombien d' Etats Finaux : " ;
    cin >> nb_Final;
  }while(nb_Final < 0);
    cout << "Entrer les etats finaux : ";
    for(int i = 0; i < nb_Final; i++){
        cin >> fiinal;
        if (fiinal.length()==2)
        {fiinal=fiinal[1]; F.push_back(fiinal);} else F.push_back(fiinal);
        cout << F[i];
    }

do{
    int k;
    if ((Trans[0][2]=='0') || (Trans[0][2]=='1' )) k=1;
    else k=0;
    etat = Trans[0][1+k];

    cout << "\n\t Le mot: ";
    cin >> mot;
    for (unsigned int i = 0; i < mot.length(); i++){
        for(unsigned int j = 0; j < Trans.size(); j++)
        {
            if(mot[i] == Trans[j][3+k] )
            {
                if (etat[0] == Trans[j][1+k])
                {
                    etat = Trans[j][5+k+k];
                    i++;
                    if(i == (mot.length()))
                    {
                        j=Trans.size();
                    }
                    else
                        j=0;
                }
                else
                {
                    if(j == (Trans.size() - 1))
                    {
                        etat=" ";
                        goto message;
                    }
                }
            }
            else
            {
                if(j == (Trans.size() - 1))
                {
                    etat=" ";
                    goto message;
                }
            }
        }
    }
    message :
   if (find(F.begin(), F.end(), etat) != F.end())
    cout <<"\n\tMot  accepte par l'automate" << endl;
   else
    cout << "\n\tMot non accepte par l'automate" << endl;

    cout << "Voulez vous un autre mot  ? (o/n) ";
    choice = getch();
  }while(choice == 'o');
    return 0;
}
