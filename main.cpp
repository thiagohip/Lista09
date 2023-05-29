#include <iostream>


using namespace std;

class Veiculo{
    protected:
        int cd_veiculo;
        double dia_valor;

    public:
        Veiculo(){

        }

        Veiculo(int cd_veiculo, double dia_valor){
            this->cd_veiculo = cd_veiculo;
            this->dia_valor = dia_valor;
        }

        int getCd(){
            return cd_veiculo;
        }

        double getValor(){
            return dia_valor;
        }

        double valorLocacao(int dia){
            return dia*dia_valor;
        }

};

class Carro : public Veiculo{
    private:
        string cor, modelo, tipo_de_combustivel;

    public:
        Carro() : Veiculo(){
            this->cd_veiculo = 0;
            this->dia_valor = 0;
        }

        Carro(string cor, string modelo, string tipo_de_combustivel, int cd_veiculo, double dia_valor) : Veiculo(cd_veiculo, dia_valor){
            this->cor = cor;
            this->modelo = modelo;
            this->tipo_de_combustivel = tipo_de_combustivel;
        }

        string getCor(){
            return cor;
        }

        string getModelo(){
            return modelo;
        }

        string get_tipo_de_combustivel(){
            return tipo_de_combustivel;
        }
};

void opcoes(){
        system("cls");
        cout << "----------------------------" << endl;
        cout << "[1]Cadastrar carro" << endl;
        cout << "[2]Listar carros cadastrados" << endl;
        cout << "[3]Calcular valor de locacao" << endl;
        cout << "[4]Sair do programa" << endl;
        cout << "----------------------------" << endl;
}

void listar_carros(Carro *carros, int qtd_carros, int max_carros){
    system("cls");
    cout << qtd_carros << "/" << max_carros << " carros cadastrados" << endl;
    for(int i=0; i < qtd_carros; i++){
        cout << carros[i].getCd();
        cout << " | " << carros[i].getModelo();
        cout << " | " << carros[i].getCor() << " | ";
        cout << carros[i].get_tipo_de_combustivel();
        cout << " | " << "R$" << carros[i].getValor() << "/dia" << endl;
    }
    cout<<endl;
}

int main()
{
    int max_carros, op;
    cout << "Qual a capacidade de carros? ";
    cin >> max_carros;
    Carro* carros = new Carro[max_carros];
    int qtd_carros = 0;
    do{
        opcoes();
        cin >> op;
        switch(op){
            case 1:
                if(qtd_carros < 10){
                    system("cls");
                    string cor, modelo, tipo_de_combustivel;
                    int cd_veiculo;
                    double dia_valor;
                    cout << "----------------------------" << endl;
                    cout << " Cadastrando um novo carro " << endl;
                    cout << "----------------------------" << endl;
                    cout << "Cor: ";
                    cin >> cor;
                    cout << "Modelo: ";
                    cin >> modelo;
                    cout << "Tipo de combustivel: ";
                    cin >> tipo_de_combustivel;
                    cout << "Codigo de veiculo: ";
                    cin >> cd_veiculo;
                    cout << "Valor por dia: ";
                    cin>> dia_valor;
                    carros[qtd_carros] = Carro(cor, modelo, tipo_de_combustivel, cd_veiculo, dia_valor);
                    qtd_carros++;
                }else{
                    cout << "Ja atingiu a capacidade máxima de carros." << endl;
                }
                break;
            case 2:
                cout << "----------------------------" << endl;
                cout << " Listando carros cadastrados " << endl;
                cout << "----------------------------" << endl;
                listar_carros(carros, qtd_carros, max_carros);
                system("pause");
                break;
            case 3:
                cout << "----------------------------" << endl;
                cout << " Calcular valor de locação " << endl;
                cout << "----------------------------" << endl;
                listar_carros(carros, qtd_carros, max_carros);
                cout << "----------------------------" << endl;
                int dias, carro;
                cout << "Dias: ";
                cin >> dias;
                cout << "Carro: ";
                cin >> carro;
                cout << endl;
                for(int i=0; i<qtd_carros; i++){
                    if(carro == carros[i].getCd()){
                        cout << "A locação do " << carros[i].getModelo() << " " << carros[i].getCor() << " para " << dias << " dias " << " e de R$" << carros[i].valorLocacao(dias) << endl;
                    }
                }
                system("pause");
            case 4:
                delete[] carros
        }
    }while (op != 4);
    return 0;
}
