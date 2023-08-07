#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
string nome;
int valor;
//map para guardar os medicamentos
map<string,int>medicamentos;
void carregarMedicamentos(){
  //cria o arquivo
  fstream arquivoCriar;
  arquivoCriar.open("gerentes.txt", ios::out | ios::app);
  arquivoCriar.close();

  //ler o arquivo
  fstream arquivoler;
  arquivoler.open("gerentes.txt", ios::in);
  string linha;
  vector<string> vetor;

  //ler todas as linhas do arquivo e salva em um vector
  while(getline(arquivoler, linha)){
    vetor.push_back(linha);
  }
  arquivoler.close();

  //transferindo do vector para o map
  for(int i = 0; i< vetor.size(); i+=2){
    nome = vetor[i];
    medicamentos[nome]= stoll(vetor[i+1]);
  }
}
//lista todos os medicamentos
void listarMedicamentos(){
  cout << "***** Medicamentos disponiveis *****\n";
  carregarMedicamentos();
  for(auto i: medicamentos){
    cout << i.first << endl;
    cout << i.second<< " reais" << endl;
  }
}
//adiciona os medicamentos
void adicionarMedicamento(string nome, int valor){
  fstream arquivo;
  arquivo.open("gerentes.txt", ios::out | ios::app);
  arquivo << nome << endl;
  medicamentos[nome] = valor;
  arquivo << valor << endl;

  arquivo.close();
}
//busca um medicamento pelo seu nome
void buscarMedicamento(string nome){
  carregarMedicamentos();
  for(auto i: medicamentos){
    if(i.first == nome){
      cout << "o Medicamento foi encontrado" << endl;
      cout << i.first << endl;
    }
  }
}
//altera o medicamento
void AlterarMedicamento(string nome, int valor){
  carregarMedicamentos();
  for(auto i: medicamentos){
    if(i.first == nome)
    medicamentos[nome] = valor;
  }
  cout << "Medicamento alterado com sucesso";
}
//atualiza o arquivo
void Atualizar(){
  fstream arquivo;
  arquivo.open("gerentes.txt", ios::out);
  for(auto i: medicamentos){
    arquivo << i.first << endl;
    arquivo << i.second << endl;
  }
}
//apagar um medicamento pelo seu nome
void apagarMedicamento(string nome){
  carregarMedicamentos();
  for(auto i: medicamentos){
    if(i.first == nome){
      medicamentos.erase(nome);
      Atualizar();
      cout << "Medicamento foi exluido" << endl;
    }
  }
}