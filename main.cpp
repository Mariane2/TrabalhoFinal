#include <iostream>
#include <fstream>

using namespace std;

class No
{
private:
	int valor;
	No* proximo;
public:
	No(int elemento) // constrói o objeto
	{
		this -> valor = elemento;
		this -> proximo = NULL;
	}

	int obterValor() // obtém o valor
	{
		return valor;
	}

	No* obterProx() // obtém o próximo No
	{
		return proximo;
	}

	void setProx(No* p) // seta o próximo No
	{
		proximo = p;
	}
};

class Lista
{
private:
	No* primeiro; // primeiro elemento
	No* ultimo; // último elemento

public:
	Lista()
	{
		// se não passar elemento, então cabeca e cauda são NULL
		primeiro = NULL;
		ultimo = NULL;
	}

	Lista(int valor)
	{
		// se passar elemento, então cria novo No
		primeiro = new No(valor);
		ultimo = primeiro;
	}

	void mostraElementos() // mostra todos os elementos da lista
	{ 
    ofstream Gravar("BancoDados.txt");
		No* i = primeiro;

		if(vazia())
			cout << "A lista NAO possui elementos!!\n";
		else
		{
			while(i) // percorre a lista
			{
        Gravar << i -> obterValor() << endl;
				i = i->obterProx();
			}

		}
	}

	bool vazia() // Verifica se a lista está vazia
	{
		return (primeiro == NULL);
	}

	// insere no início (semelhante a push_front da list)
	void inserir_inicio(int valor)
	{
		No* novo_no = new No(valor);

		if(vazia())
		{
			primeiro = novo_no;
			ultimo = novo_no;
		}
		else
		{
			novo_no->setProx(primeiro);
			ultimo = novo_no;
		}
	}

	// insere no final (semelhante a push_back da list)
	void inserir_final(int valor)
	{
		No* novo_no = new No(valor);

		if(vazia())
		{
			primeiro = novo_no;
			ultimo = novo_no;
		}
		else
		{
			ultimo->setProx(novo_no);
			ultimo = novo_no;
		}
	}

	// retorna o tamanho da lista
	int tamanho()
	{
		if(vazia()) // se for vazia, entã retorna 0
			return 0;

		No* i = primeiro;
		int tam = 0;
		
		// percorre a lista
		do
		{
			i = i->obterProx();
			tam++;
		}
		while(i);
		
		return tam;
	}

	// verifica se um elemento existe na lista
	bool existe(int valor)
	{
		No* i = primeiro;
		
		while(i)
		{
			if(i->obterValor() == valor)
				return true;
			i = i->obterProx();
		}
		return false;
	}


};

    void LerDados() {
    cout << "***************Entre com a iformação***************" << endl;
    cout << "1 - Gravar dados" << endl;
    cout <<"2 - Ler dados" << endl;
    cout <<"3 - Sair" << endl;
    }


int main()
{
	int ler_gravar; 
  int qtd_elementos;
  int elemento;
  int R1;
  int R2;
  int V1;
  Lista l;
  ifstream file ("BancoDados.txt");

   while(ler_gravar != 3){  // Enquanto for difente de "sair" fica no loop.
   
     LerDados(); 
     cin >> ler_gravar; // Armazena opção escolhida
   
      while((ler_gravar<0)&&(ler_gravar>3)){ // Assegura a opção correta
    
      cout << "Informação incorreta! Escolha:" <<endl;
      cout << "1 - Gravar dados" << endl;
      cout <<"2 - Ler dados" << endl;
      cout <<"0 - Sair" << endl;
      cin >> ler_gravar;
      }

      if(ler_gravar == 1){ 

      cout << "Entre com a quantidade de circuitos:" <<endl;
      cin >> qtd_elementos; // Armazena qtd de elementos pelo usuário.

          for(int i =0; i<qtd_elementos; i++){ // Recebe as iformações.
              cout << "Digite os valores do "<<i+1<<"º circuito:" <<endl;
              cout << "Respectivamente o valor de R1, R2 e V1:" <<endl;
              cin >> R1;
              cin >> R2;
              cin >> V1;

              l.inserir_final(R1);  // Armazena no final da lista
              l.inserir_final(R2);  // Armazena no final da lista
              l.inserir_final(V1);  // Armazena no final da lista   
          }

      l.mostraElementos();
    }

    if(ler_gravar == 2){ // Leitura do arquivo
    
      while(!file.eof()){
        
        file >> elemento;
        l.inserir_final(elemento);    
        cout << elemento << endl;
      }

    }

  }	

	return 0;
}