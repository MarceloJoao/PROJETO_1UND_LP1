#include <iostream>
#include "cliente.hpp"
#include "gerente.hpp"
using namespace std;
int main() {
  string senha;
  string gerente = "farmacia";
  cout << "******************************\n\n";
  cout << "Bem-vindos a farmacia bom amigo\n\n";
  cout << "******************************\n\n";
  //escolhendo perfil 
  cout << "Escolher perfil: " << endl;
  cout << "1- Cliente" << endl;
  cout << "2- Gerente" << endl;
  int perfil;
  cin >> perfil;
  cout << endl;
  //menu de opções para cliente
  if (perfil == 1) {
    while(true){
    cout << endl;
    cout << "******* AREA DO CLIENTE ******" << endl;
    cout << "1- Listar todos os medicamentos" << endl;
    cout << "2- buscar um medicamento" << endl;
    cout << "3- Guardar medicamento " << endl;
    cout << "4-ver o total das compras" << endl;
    cout << "5- excluir medicamento do carrinho" << endl;

    int opcao;
    cin >> opcao;
    //listar todos os medicamentos disponiveis
    if (opcao == 1) {
      listarMedicamentos();
  
      
    } else if (opcao == 2) {
      //buscar um medicamento 
      cout << "Digite o nome de um remedio" << endl;
      string med;
      cin >> med;
      buscarMedicamento(med); //chamando função em gerente.cpp
    } else if (opcao == 3) {
      //listando os medicamentos disponiveis para o cliente selecionar
      listarMedicamentos();
      cout << "Qual medicamento vc deseja" << endl;
      string n_med;
      cin >> n_med;
      cout << "Digite o valor do remedio" << endl;
      int v;
      cin >> v;
       //adicionando um medicamento no carrinho de compras
      carrinhoCompras(n_med, v);//chamando função em cliente.cpp
    } else if (opcao == 4){
      //verificando o total das compras do carrinho
      carregarRemedio();
      cout << "O valor total de compras no carrinho foi: ";
      total_compras();

     //excluir medicamento do carrinho
    }else if(opcao == 5){
      cout << "Digite o medicamento que deseja excluir" << endl;
      string a;
      cin >> a;
      excluir(a);
    }else{
      break;
    }
    }//menu de opções gerente
  } else if (perfil == 2){
    //solicita a senha do gerente
    //é necessário a senha apos cada ação, diferentemente do cliente
    while(true){
    cout << "Digite a senha de acesso: " << endl;
    cin >> senha;
    if(senha == gerente){
    cout << endl;
    cout << "******* AREA DO GERENTE ******" << endl;
    cout << "1- Listar todos os medicamentos" << endl;
    cout << "2- buscar " << endl;
    cout << "3- adicionar medicamentos " << endl;
    cout << "4- excluir medicamento" << endl;
    cout << "5- atualizar medicamento\n" << endl;

    int op;
    cin >> op;
     //listar medicamentos e seus valores
    if (op == 1) {
      listarMedicamentos();
      //buscar um medicamento
    } else if (op == 2) {
      string remedio;
      cin >> remedio;
      buscarMedicamento(remedio);//chamando função
      //adicionando um medicamento 
    } else if (op == 3) {
      cout << "Qual medicamento deseja adicionar na farmacia?"<< endl;
      string nome;
      cin >> nome;
      cout<< "Qual o preço dele?"<< endl;
      int valor;
      cin >> valor;
      adicionarMedicamento(nome, valor);//chamando função

      //apagar um medicamento 
    } else if (op == 4) {
      cout << "Digite o nome do medicamento" << endl;
      string name;
      cin >> name;
      apagarMedicamento(name);// chamando função
    }else if(op == 5){
      cout << "Qual medicamento deseja alterar?" << endl;
      string alterar;
      cin >> alterar;
      cout << "Qual o novo valor dele?"<< endl;
      int value;
      cin >> value;
      AlterarMedicamento(alterar, value);
    }else{
      break;
    }     
}else{
      cout << "acesso negado";
}    
  }
  }
  return 0;
}