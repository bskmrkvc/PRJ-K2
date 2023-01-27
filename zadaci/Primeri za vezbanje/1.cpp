#include<iostream>
#include<fstream>
#include<string.h>
#define MAX 80

using namespace std;

int main(){
	fstream f;
	char pom[MAX+1];
	double srVr=0;
	int suma=0, br=0;
	
	f.open("dat.txt", ios::in);
	if(!f){
		cerr<<"Greska pri otvaranju fajla!\n";
		exit(1);
	}
	
	while(f.getline(pom, MAX+1)){
		br++;
		suma+=strlen(pom);
	}
	
	srVr=(float)suma/br;
	
	cout << "Srednja duzina redova: " << srVr << endl;
	cout << "Broj redova: " << br << endl;
	
	f.close();
	
	system("pause");
	return 0;
}
