#include <iostream>
#include <csignal>

using namespace std;

void handler(int signum) {
    cout << "Para encerrar, pressione Ctrl + C novamente" << endl;
    signal(SIGINT, SIG_DFL);
}

int main() {
    signal(SIGINT, handler);
    while (true){}
    return 0;
}
