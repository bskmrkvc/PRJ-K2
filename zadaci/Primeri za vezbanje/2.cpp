#include<iostream>
#include<string.h>
#include<fstream>
#include<ctype.h>

using namespace std;

int main(){
	fstream f1, f2;
	char c;
	f1.open("dat.txt", ios::in);
	if(!f1){
		cerr << "Doslo je do greske prilikom otvaranja fajla dat.txt\n";
		exit(1);
	}
	
	f2.open("dat2.txt", ios::out);
	if(!f2){
		cerr << "Doslo je do greske prilikom otvaranja fajla dat2.txt\n";
		exit(1);
	}
	
	while((c = f1.get()) > 0){
		if(c == '>'){
			f2.put(c);
			f2.put(c);
		}
		else if(c == '<'){
			f2.put(c);
			f2.put(c);
		}
		else f2.put(c);
	}
	f1.close();
	f2.close();
	cout << "Kraj programa.\n";
	system("pause");
	return 0;
}
