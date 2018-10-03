#include "std_lib_facilities.h";
using namespace drill4;

int main(){
	double szam; //Ez lesz a az értek ami alapján számolunk
	string me; //Mértékegység változó rövidítve me
	vector<<double>> szamok

	while (me != "|"){ 	//Addig fog a cilumenni míg a "|" változót nem kapja meg.Ez a ciklusból való kimenési feltétel.
		cout << "\nAdjon meg egy mértékegséget(cm, m,  ft, in vagy | -t hogyha be szertné zárni a programot)" // <- bekérjük az me értékét.
		cin >> me;

		if (me == "|"){
			return 0;
		}
		//else?
		cout <<"\nAdjon meg egy értéket,"<< me <<  "melyet szerene átváltani méterbe"; //A számot  bekérem.
		if (me == "cm"){
			szam= szam/100;
			szamok.push_back(szam);
		}
		else if ( me == "m"){
			szamok.push_back(szam);
		}
		else if (me == "ft"){
			szam = szam/3.18;
			szamok.push_back(szam);
		}
		else if (me == "in"){
			szam ==  szam/39.37;
			szamok.push_back(szam);
		}
		else cout << (\n"Nem megfelelő formátum/mértékegység") //hibakód, ha egyik iffel sem végbe a művelet.
			sort(szamok); //Rendezés
			cout << string(50, '\n'); //esztétikai átrendezés
			cout << "Az ön értékei: " << a << '\n'; //Adatok kiírása
			cout << "A legkisebb érték: " << szamok.front() << '\n'; 
			cout << "a legnagyobb érték: " << szamok.back() << '\n';
			cout << "Az összes szám: " << szamok.size() << '\n';
			cout << "A számok növekvő sorrendben: ";

			for (int i = 0; i < szamok.size(); i++) {
			cout << szamok[i] << ", "; //Eddigi számok kiírása növekvő sorrendben, egymás után
	}
}