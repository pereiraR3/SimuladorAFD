#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

class AFD {
private:
    int numEstados;
    int estadoInicial;
    set<int> estadosFinais;
    set<char> alfabeto;
    map<pair<int, char>, int> tabelaTransicoes;

public:
    AFD() {};

    void lerAFD() {
        cin >> numEstados >> estadoInicial;

        int numEstadosFinais;
        cin >> numEstadosFinais;
        estadosFinais.clear();
        for (int i = 0; i < numEstadosFinais; ++i) {
            int estadoFinal;
            cin >> estadoFinal;
            estadosFinais.insert(estadoFinal);
        }

        int numSimbolos;
        cin >> numSimbolos;
        alfabeto.clear();
        for (int i = 0; i < numSimbolos; ++i) {
            char simbolo;
            cin >> simbolo;
            alfabeto.insert(simbolo);
        }

        int numTransicoes;
        cin >> numTransicoes;
        tabelaTransicoes.clear();
        for (int i = 0; i < numTransicoes; ++i) {
            int estadoAtual, proximoEstado;
            char simbolo;
            cin >> estadoAtual >> simbolo >> proximoEstado;
            tabelaTransicoes[{estadoAtual, simbolo}] = proximoEstado;
        }
    };

    bool aceita(string entrada) {
        int estadoAtual = estadoInicial;
        for (char simbolo : entrada) {
            if (alfabeto.find(simbolo) == alfabeto.end()) {
                // Se o símbolo não pertence ao alfabeto, rejeita imediatamente
                return false;
            }
            estadoAtual = tabelaTransicoes[{estadoAtual, simbolo}];
        }

        return estadosFinais.find(estadoAtual) != estadosFinais.end();
    };
};

int main() {
    AFD automato;
    automato.lerAFD();

    // Leitura da cadeia de entrada
    string entrada;
    cin >> entrada;

    // Teste se a cadeia é aceita pelo AFD
    if (automato.aceita(entrada)) {
        cout << "Aceito" << endl;
    } else {
        cout << "Rejeitado" << endl;
    }

    return 0;
}