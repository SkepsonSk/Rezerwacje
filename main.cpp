#include <iostream>
#include <string>
using namespace std;

struct danePasazera{
	string imie;
	string nazwisko;
	int wiek;
	string znizka;
};

int rezerwacjaMiejsc(unsigned short int a){
	cout<<"Ile miejsc w busie chcesz zarezerwowac? ";
	do {
        cin >> a;
        if (!(a > 0 && a < 9)) {
            cout << "Liczba pasazerów powinna byæ w przedziale od 0 do 8." << endl;
        }
	} while (!(a > 0 && a < 9));
	return a;
}
void wyswietlanieDanych(unsigned short int a, danePasazera *miejsca){
	for(int i=0; i<a; i++){
		cout<<"Pasazer "<<i+1<<": "<<miejsca[i].imie<<" "<<miejsca[i].nazwisko<<endl;
		cout<<"Wiek pasazera: "<<miejsca[i].wiek<<". Znizka: "<<miejsca[i].znizka<<"."<<endl<<endl;
	}
}

int main(){
	unsigned short int a;
	danePasazera *miejsca = new danePasazera[8];

	a=rezerwacjaMiejsc(a);

	for(int i=0; i<a; i++){
		cout<<"Podaj imie pasazera: ";
		cin.ignore();
		getline(cin, miejsca[i].imie);
		cout<<"Podaj nazwisko pasazera: ";
		getline(cin, miejsca[i].nazwisko);
		cout<<"Podaj wiek pasazera: ";
		cin>>miejsca[i].wiek;
		cout<<endl;

		if(miejsca[i].wiek<0){
			cout<<"Podane zle dane, prosze wprowadzic jeszcze raz."<<endl;
			cin>>miejsca[i].wiek;
		}

		if(miejsca[i].wiek<18 || miejsca[i].wiek>65){
			miejsca[i].znizka="TAK";
		}
		else{
			miejsca[i].znizka="NIE";
		}
	}
	wyswietlanieDanych(a, miejsca);
	cout<<"Pozostalo wolnych miejsc w busie: "<<8-a;
	delete [] miejsca;
	return 0;
}
