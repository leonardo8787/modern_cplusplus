#include<bits/stdc++.h>
#include<thread>
using namespace std;

/*
Implemente uma função calcule a multiplicação entre duas matrizes. 
A função deverá receber como argumento duas matrizes (pode-se assumir que as matrizes possuem dimensões compatíveis). 
A multiplicação deverá usar os recursos de processamento paralelo de C++11 para calcular o resultado da multiplicação.
*/

// g++ main.cpp -o programa -std=c++11 -pthread

vector<vector<int>> multiplicarMatrizesComThread(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    if (matriz1[0].size() != matriz2.size())
        throw runtime_error("As dimensões das matrizes são incompatíveis para multiplicação!");

    vector<vector<int>> resultado(matriz1.size(), vector<int>(matriz2[0].size(), 0));

    vector<thread> threads;
    mutex mtx; // mutex para garantir acesso exclusivo à variável contador
    int contador = 0; // contador de threads ativas

    for (size_t i = 0; i < matriz1.size(); i++) {
        for (size_t j = 0; j < matriz2[0].size(); j++) {
            threads.emplace_back([i, j, &matriz1, &matriz2, &resultado, &mtx, &contador]() {
                for (size_t k = 0; k < matriz1[0].size(); k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
 				}
                {
                    lock_guard<mutex> lock(mtx);
                    contador++;
                }
                if (contador > 12) {
                    unique_lock<mutex> ulock(mtx);
                    contador--;
                    ulock.unlock();
                }
            });
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }

    return resultado;
}


vector<vector<int>> multiplicarMatrizes(const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    if (matriz1[0].size() != matriz2.size())
        throw runtime_error("As dimensões das matrizes são incompatíveis para multiplicação!");

    vector<vector<int>> resultado(matriz1.size(), vector<int>(matriz2[0].size(), 0));

    for (size_t i = 0; i < matriz1.size(); i++) {
        for (size_t j = 0; j < matriz2[0].size(); j++) {
            for (size_t k = 0; k < matriz1[0].size(); k++) {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    return resultado;
}

int main(){

	cout<<"==Tamanho das matrizes=="<<endl;
	int x,y; cin>>x>>y;
	// cout<<"Semente da função de aleatoriedade"<<endl;
	// int semente; cin>>semente;

    vector<vector<int>> matriz_1(x, vector<int>(y));
    vector<vector<int>> matriz_2(x, vector<int>(y));

    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> distribution(0, 100);

	for (int i = 0; i < x; i++) {
	    for (int j = 0; j < y; j++) {
	        int aux1 = distribution(generator);
	        int aux2 = distribution(generator);
	        matriz_1[i][j] = aux1;
	        matriz_2[i][j] = aux2;
	    }
	}

    auto start = std::chrono::high_resolution_clock::now();
    vector<vector<int>> resultado = multiplicarMatrizesComThread(matriz_1, matriz_2);
    auto end = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    double seconds = duration.count();
    cout << "Tempo de execução com threads: " << seconds << " segundos" <<endl;

    auto start2 = std::chrono::high_resolution_clock::now();
    vector<vector<int>> resultado2 = multiplicarMatrizes(matriz_1, matriz_2);
    auto end2 = std::chrono::high_resolution_clock::now();
    chrono::duration<double> duration2 = end2 - start2;
    double seconds2 = duration2.count();
    cout << "Tempo de execução sem threads: " << seconds2 << " segundos" <<endl;

    if(seconds < seconds2){
    	cout<<"Com threads é melhor para essa quantidade de dados!"<<endl; 
    }else{
    	cout<<"Sem threads é melhor para está quantidade de dados!"<<endl;
    }

	return 0;
}