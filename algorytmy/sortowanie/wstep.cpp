//ALGORYTMY : Sortowanie - wstep - dla niektorych algorytmow wazne jest jaka mamy strukturze danych, np. tablica, lista, drzewo, itd.
//
//O(N^2):
//1. Bubble sort : sortowanie bąbelkowe - porównuje pary sąsiadujących elementów i zamienia je jeśli są w złej kolejności.
//
//2. Insertion sort: sortowanie przez wstawianie - wstawia kolejne elementy do posortowanej części tablicy.
//   Dobrze działa w przypadku prawie posortowanych struktur.
//
//3. Selection sort: sortowanie przez wybieranie - idzie po tablicy i wybiera najmniejszy element i wstawia go na koniec
//   posortowanej części tablicy.
//
//O(N*log(N)):
//1. Quick sort: sortowanie szybkie -Dziel i zwyciężaj. Wybiera element podziałowy i dzieli tablicę na dwie części, w której 
//   elementy są mniejsze lub większe od podziałowego. Następnie sortuje te dwie części. Problem z implementacją tego algorytmu
//   w listach i drzewach. Bardzo zle dziala na prawie posortowanych strukturach.
//
//2. Merge sort: sortowanie przez scalanie - wymaga dodatkowej pamieci. Dzielimy tablice na 2 czesci, nastepnie znow na pol itd. do
//   momentu gdy zostania tylko pojedyncze tablice. Nastepnie porownujemy te pojedyncze tablice i scalamy je w jedna podwojna tablice.
//   Nastepnie porownujemy te podwojne tablice i scalamy je w jedna czterokrotna tablice itd. do momentu gdy zostanie jedna posortowna tablica.
//   Dobrze działa w przypadku list i drzew.
//
//3. Heap sort: sortowanie przez kopcowanie - Kopiec - drzewo binarne w ktorym rodzic jest zawsze wiekszy od swoich dzieci.
//   Kopiec jest reprezentowany przez tablice. Korzen jest na pozycji 0. Dzieci rodzica na pozycjach 2*i+1 i 2*i+2.
//   Heap sort nie funkcjonuje w przypadku list i drzew. Jego zlozonosc w tym przypadku to O(N^2)log(N).






#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(){

    return 0;
}