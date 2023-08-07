#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <map>
#include "gerente.hpp"
using namespace std;
string remedio;
int preco;

//map para guardar o carrinho de compras
map <string,int> carrinho;

//ler o arquivo para salvar no map
void carregarRemedio(){

  //cria o arquivo
  fstream arquivoCreate;
  arquivoCreate.open("cliente.txt", ios::out | ios::app);
  arquivoCreate.close();

  //ler o arquivo
  fstream arquivoleitura;
  arquivoleitura.open("cliente.txt", ios::in);
  string l;
  vector<string> vetor;
  
  //salva linha por linha em um vector
  while(getline(arquivoleitura, l)){
    vetor.push_back(l);
  }
  arquivoleitura.close();

  //transfere do vector para o map carrinho
  for(int i = 0; i< vetor.size(); i+=2){
    remedio = vetor[i];
    carrinho[remedio]= stoll(vetor[i+1]);
  }
}

//abre o arquivo e adiciona o medicamento selecionado pelo cliente
void carrinhoCompras(string nome, int valor){
    fstream arquivo;
    arquivo.open("cliente.txt", ios::out | ios::app);
    arquivo << nome << endl;
    carrinho[nome] = valor;
    arquivo << valor << endl;
    arquivo.close();
}

//calcula o total das compras do carrinho
void total_compras(){
  carregarRemedio();
  int soma= 0;
  for(auto i: carrinho){
    soma += i.second;
  }
  cout << soma;
  cout << endl;
}
//atualiza o arquivo no map
void atualizarCliente(){
  fstream arquivo;
  arquivo.open("cliente.txt", ios::out);
  for(auto i: carrinho){
    arquivo << i.first << endl;
    arquivo << i.second << endl;
  }
}
//exclui um medicamento do carrinho
void excluir(string name){
  carregarRemedio();
  for(auto i: carrinho){
    if(i.first == name){
      carrinho.erase(name);
      atualizarCliente();
      cout << "Medicamento excluido do carrinho" << endl;
      break;
    }
  }
}