#include <iostream>

#include <fstream>
#include <string>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

void codificaLZW(string cod, map<string, int> &dic, int &cont);

// Aluno: Gabriel Barreto Calixto
// Matricula: 201865018AC
// Algoritmo implementado: LZW
// As strings serao lidas do arquivo "strings.txt" e as codificacoes serao mostradas no console.
// O dicionario final tambem sera imprimido, o unico problema eh que nao foi possivel colocar as novas entradas no fim do map, e ficou ordenado por ordem alfabetica.  

int main()
{
    map<string, int> dic;
    //preenchendo o dicionario com a tabela ASCII extendida
    string s;
    for(int i=0; i<=255; i++){
        s.push_back(char(i));
        dic.insert(pair<string, int>(s, i));
        s.clear();
    }
    //for (auto it = dic.begin(); it != dic.end(); ++it) cout << it->first << " = " << it->second << endl; 
    ifstream file;
    file.open("strings.txt");
    vector<string> vet;
    int cont = 256;
    while(!file.eof()){
        string a;
        getline(file, a);
        cout << a << endl;
        codificaLZW(a, dic, cont);
    }
    for (auto it = dic.begin(); it != dic.end(); ++it) cout << it->first << " = " << it->second << endl;
    file.close();
    return 0;
}

void codificaLZW(string cod, map<string, int> &dic, int &cont){
    string p="";
    string c;
    vector<int> v;
    for(int i = 0; i<= cod.size(); i ++){
        c.push_back(cod[i]);
        string aux = p+c;
        //cout << aux << endl;
        map <string, int>::iterator it;
        it = dic.find(aux);
        if (it == dic.end()){
            //cout << "Nao esta no dicionario" <<endl;
            dic.insert(it, pair<string, int>(aux, cont++));
            map <string, int>::iterator ite;
            ite = dic.find(p);
            v.push_back(ite->second);
            p = c;
        }
        else{
            p = aux;
        } 
        c.erase();
        aux.erase(); 
    }
    //cout << v.size() << endl;
    for(int i=0; i<v.size(); i++) cout << v[i] << "  ";
    cout <<endl;
    //for (auto iter = dic.begin(); iter != dic.end(); ++iter) cout << iter->first << " = " << iter->second << endl;
}