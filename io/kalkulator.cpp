#include <iostream>
#include <cmath>

using namespace std;

//dowolna liczba liczb pierwszych
namespace Kalkulator_{


 class LiczbaPierwsza{
    int liczba;
    LiczbaPierwsza *nastepna;

    public:
        LiczbaPierwsza(int liczba, LiczbaPierwsza *nastepna = nullptr){
            this->liczba = liczba;
            this->nastepna = nastepna;
        }

        int getLiczba(){
            return liczba;
        }

        LiczbaPierwsza *getNastepna(){
            return nastepna;
        }

        void setNastepna(LiczbaPierwsza *nastepna){
            this->nastepna = nastepna;
        }

        void wypisz(){
            cout << liczba << " ";
            if(nastepna != nullptr){
                nastepna->wypisz();
            }
        }

        void dodaj(int liczba){
            if(nastepna == nullptr){
                nastepna = new LiczbaPierwsza(liczba);
            }else{
                nastepna->dodaj(liczba);
            }
        }

        void usun(int liczba){
            if(nastepna != nullptr){
                if(nastepna->liczba == liczba){
                    LiczbaPierwsza *tmp = nastepna;
                    nastepna = nastepna->nastepna;
                    delete tmp;
                }else{
                    nastepna->usun(liczba);
                }
            }
        }

        bool czyPierwsza(int liczba){
            if(nastepna != nullptr){
                if(nastepna->liczba == liczba){
                    return true;
                }else{
                    return nastepna->czyPierwsza(liczba);
                }
            }
            return false;
        }

        int ilePierwszych(){
            if(nastepna != nullptr){
                return 1 + nastepna->ilePierwszych();
            }
            return 1;
        }

        int ilePodzielnych(int liczba){
            if(nastepna != nullptr){
                if(liczba % nastepna->liczba == 0){
                    return 1 + nastepna->ilePodzielnych(liczba);
                }else{
                    return nastepna->ilePodzielnych(liczba);
                }
            }
            return 0;
        }

        //funkcja do wypisywania liczb pierwszych z zakresu
        void wypiszPierwsze(int zakres){
            if(nastepna != nullptr){
                if(nastepna->liczba <= zakres){
                    cout << nastepna->liczba << " ";
                    nastepna->wypiszPierwsze(zakres);
                }
            }
        }
    };

};

int main(){
    using namespace Kalkulator_;
    LiczbaPierwsza *pierwsze = new LiczbaPierwsza(1);
    pierwsze->dodaj(3);
    pierwsze->dodaj(5);

    pierwsze->wypisz();

    return 0;
}