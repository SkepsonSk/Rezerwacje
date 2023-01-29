#include <iostream>
#include <string>
using namespace std;

struct danePasazera{
	string imie;
	string nazwisko;
	int wiek;
	string znizka;
};

struct autobus {
    danePasazera* pasazerowie;
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
	autobus bus;

	bus.pasazerowie = new danePasazera[8];

	a=rezerwacjaMiejsc(a);

	for(int i=0; i<a; i++){
		cout<<"Podaj imie pasazera: ";
		cin.ignore();
		getline(cin, bus.pasazerowie[i].imie);
		cout<<"Podaj nazwisko pasazera: ";
		getline(cin, bus.pasazerowie[i].nazwisko);
		cout<<"Podaj wiek pasazera: ";
		cin>>bus.pasazerowie[i].wiek;
		cout<<endl;

		if(bus.pasazerowie[i].wiek<0){
			cout<<"Podane zle dane, prosze wprowadzic jeszcze raz."<<endl;
			cin>>bus.pasazerowie[i].wiek;
		}

		if(bus.pasazerowie[i].wiek<18 || bus.pasazerowie[i].wiek>65){
			bus.pasazerowie[i].znizka="TAK";
		}
		else{
			bus.pasazerowie[i].znizka="NIE";
		}
	}
	wyswietlanieDanych(a, bus.pasazerowie);
	cout<<"Pozostalo wolnych miejsc w busie: "<<8-a;
	return 0;
}
