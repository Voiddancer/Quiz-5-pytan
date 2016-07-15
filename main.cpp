#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;
char kategoria;
string nick, temat;
string pytania [5];
string odpA[5], odpB[5], odpC[5], odpD[5];
string poprawna[5];
string odpowiedz;
int pkt=0;
int nr_pytania;



int main()
{

    cout <<setw(70)<<setfill(' ')<<"*****Quiz 5 pytan*****" << endl;
    Sleep (1500);
    cout <<setw(77)<<setfill(' ')<<"Kiedy bêdziesz gotowy naciœnij ENETER"<<endl;
    getchar();
    cout <<setw(62)<<setfill(' ')<< "Zaczynamy!"<<endl;
    int nr_linii=1;
    int nr_pytania=0;
    string linia;
    fstream plik;
    plik.open("quiz.txt", ios::in);
    if (plik.good()==false)
    {
        cout<< "Bak pliku z pytaniami";
        exit(0);
    }
    while (getline(plik,linia))
    {
        switch(nr_linii)
        {
            case 1: temat      =    linia;        break;
            case 2: nick       =    linia;        break;
            case 3: pytania[nr_pytania] =    linia;        break;
            case 4: odpA[nr_pytania]    =    linia;        break;
            case 5: odpB[nr_pytania]    =    linia;        break;
            case 6: odpC[nr_pytania]    =    linia;        break;
            case 7: odpD[nr_pytania] =    linia;        break;
            case 8: poprawna[nr_pytania]=    linia;        break;

        }
        if (nr_linii==8) {nr_linii=2;nr_pytania++;}

        nr_linii++;

    }

       plik.close();
    for(int i=1;i<=4;i++)
    {
      cout << nr_pytania<<". " <<pytania[i]<< endl ;
      cout << "A."<< odpA[i] << endl ;
      cout << "B."<< odpB[i] << endl ;
      cout << "C." << odpC[i] << endl;
      cout << "D." << odpD[i] << endl;

      cout << endl<< "Twoja odpowiedz to :" ;
      cin >> odpowiedz ;
      transform(odpowiedz.begin(),odpowiedz.end(),odpowiedz.begin(),::tolower);
      if (odpowiedz==poprawna[i])
      {
          cout<<"udalo ci sie zdobyc pkt.";
          pkt++;
      }else {cout<<"wal sie !!"<<endl<<"LOOOZER SUCKER" <<endl;Sleep(1000);}




    }
    cout<<pkt<< " pkt. Gratulacje"<<endl;
    Sleep (3000);
    cout <<setw(70)<<setfill(' ')<<"Fiucior"<<endl;


  getchar();
    return 0;
}
