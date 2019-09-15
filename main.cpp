
//Including libraries
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
//#include "graphics.h"
#include <math.h>

using namespace std;

/*
void togli_slashn(string nome){
	nome.erase(nome.length()-1);
}
*/

//formato contatto
struct contatto {
    //vvvariabile nome
    char name[50];
    //... cognome
    char surname[50];
    string numerocell;
    string numerocasa;
};

//funzione per visualizzare i contatti
void visualizza() {
    string line;
    int n = 0;
    string invio;
    //per leggere il file presa da stack overflow
    ifstream myfile("contatti.txt");
    
    if (myfile.is_open()) {
        while ( getline (myfile,line)) {
            n++;
            cout <<n<<")"<< line << '\n';   
        }
        myfile.close();
    }
    else cout << "Non riesco ad aprire il file :-( ";
}

//funnzione per aggiungere il contatto...
void aggiungi_contatto() {
    //... utilizzando la struttura predefinita prima
    struct contatto contatto1; //Dichiaro il primo contatto
    char name[50], surname[50];
    string numerocell;
    string numerocasa;
    string scelta;
    
    cout << "Inserisci il nome del contatto: ";
    cin>>name;
    cout << "Inserisci il cognome del contatto: ";
    cin>>surname;
    cout << "Inserisci il numero del contatto (CELLULARE): ";
    cin>>numerocell;
    cout << "Inserisci il numero del contatto (CASA): ";
    cin>>numerocasa;
    //crea il contatto con la struttura definita precedentemente
    strcpy( contatto1.name, name);
    strcpy( contatto1.surname, surname);
    contatto1.numerocell = numerocell;
    contatto1.numerocasa = numerocasa;
    contatto cArray[4];
    cout<<"Sei sicuro di volere salvare questi dati? "<<endl;

    cout<<"-----------------------------------------------------\n";
		cout << "Nome contatto: " << name <<endl;
    cout << "Cognome contatto: " << surname <<endl;
    cout << "Numero cellulare: " << numerocell <<endl;
    cout << "Numero casa: " << numerocasa <<endl;
    cout<<"-----------------------------------------------------";
    cout << "\n\n" << endl;
    cout<<"Digita y per confermare o n per annullare: ";
    cin>>scelta;
    if (scelta == "y"){
    //funzione per scrivere i contatti sul file (stack overflow)
    ofstream myfile ("contatti.txt", fstream::app);
    if (myfile.is_open()) {
        myfile << "Nome: "<< name<< " ";
        myfile << "Cognome: "<< surname<< " ";
        myfile << "Numero (CELLULARE): "<< numerocell<< " ";
        myfile << "Numero (CASA): "<< numerocasa<<endl;
        myfile.close();
        system ("clear");
        system ("cls");
    }
    }

}

//funzione per eliminare una stringa... dato il numero della stringa in cui si trova --> utilizza un file temporaneo dove copia i contatti tranne quello da eliminare (stack overflow)
void delete_line(const char *file_name, int n) {
    // open file in read mode or in mode
    ifstream is(file_name);

    // open file in write mode or out mode
    ofstream ofs;
    ofs.open("tmp.txt", ofstream::out);
    
    // loop getting single characters
    char c;
    int line_no = 1;
    while (is.get(c))
    {
        // if a newline character
        if (c == '\n')
            line_no++;
        // file content not to be deleted
        if (line_no != n)
            ofs << c;
    }
    // closing output file
    ofs.close();
    // closing input file
    is.close();
    
    // remove the original file
    remove(file_name);
    
    // rename the file
    rename("tmp.txt", "contatti.txt");
    std::ofstream outfile ("tmp.txt");
    
}

//funzione per rimuovere il contatto
void rm_contatto() {
    int n;
    string scelta;
    cout << "Inserisci la posizione del contatto da eliminare [numero a sinistra della parentesi]: ";
    visualizza();
    cin >> n;
    cout<<"Sei sicuro di voler eliminare il contatto numero "<<n<<"?"<<endl;
    cout<<"Digita y per confermare o n per annullare: ";
    cin>>scelta;
    if (scelta == "y"){
    	delete_line("contatti.txt", n);
    }
    system ("clear");
    system ("cls");
}

//main
int main() {
    string comando;
    do {
        cout<<"#########################################################\n";
        cout<<"   -----------------------------------------\n";
        cout<<"   |Scrivi '+' per aggiungere un contatto  |\n";
        cout<<"   |Scrivi '-' per eliminare un contatto   |\n";
        cout<<"   |Scrivi 'v' per visualizzare un contatto|\n";
        cout<<"   |Scrivi 'q' per uscire dal programma    |\n";
        cout<<"   -----------------------------------------\n\n";
        cout<<"#########################################################\n";
        cout << "Cosa desideri fare? \n"<< endl;
        cin >> comando;
        if(comando == "+")
        {
            aggiungi_contatto();
        }
        else if(comando == "v")
        {
            visualizza();
        }
        else if(comando == "-")
        {
            rm_contatto();
        }
    } while (comando!="q");
    
    return 0;
}
