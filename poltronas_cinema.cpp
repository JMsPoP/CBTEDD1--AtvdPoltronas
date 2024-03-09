#include <iostream>
#include <iomanip>
using namespace std;

#define LIN 15
#define COL 40

void mostra_matriz(int **p)
{
    for (int i = 1; i <= LIN; ++i)
    {
        for (int j = 1; j <= COL; ++j)
        {
            // Mostra "." se for 0, "#" se for 1
            cout << setw(2) << (p[i][j] == 0 ? "." : "#") << " |";
        }
        cout << endl;
    }
}

int main(int argc, char **argv)
{
    int i, j;
    int linha, coluna;
    int **mat;
    int valor_bilheteria = 0;
    int lugares_ocupados = 0;

    mat = new int *[LIN + 1];

    for (i = 1; i <= LIN; ++i)
    {
        mat[i] = new int[COL + 1];
    }

    for (i = 1; i <= LIN; ++i)
    {
        for (j = 1; j <= COL; ++j)
        {
            mat[i][j] = 0;
        }
    }

    int escolha;

    do
    {
        cout << "\nO que você deseja fazer?\n\n"
             << "0. Finalizar\n"
             << "1. Reservar poltrona\n"
             << "2. Mapa de ocupação\n"
             << "3. Faturamento e lugares ocupados\n"
             << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
            cout << "Informe a fileira onde deseja reservar a poltrona: ";
            cin >> linha;

            cout << "\nInforme a qual o número que deseja reservar a poltrona: ";
            cin >> coluna;

            // Verificando se as coordenadas estão dentro dos limites da matriz
            if (linha < 1 || linha > LIN || coluna < 1 || coluna > COL)
            {
                cout << "Poltrona nao pertencente a esta sala. Tente novamente." << endl;
                continue;
            }

            if (mat[linha][coluna] == 1)
            {
                cout << "Este local está ocupado, senhor(a). Tente novamente." << endl;
            }
            else
            {
                // Alocando o valor 1 nas coordenadas fornecidas pelo usuário
                mat[linha][coluna] = 1;
                cout << "Poltrona reservada com sucesso!" << endl;
            }
            break;

        case 2:
            cout << "\nMapa de Ocupação:\n";
            mostra_matriz(mat);
            break;

        case 3:
            lugares_ocupados = 0;
            for (i = 1; i <= LIN; ++i)
            {
                for (j = 1; j <= COL; ++j)
                {
                    if (mat[i][j] == 1)
                    {
                        if (i >= 1 && i <= 5)
                            valor_bilheteria += 50;
                        else if (i >= 6 && i <= 10)
                            valor_bilheteria += 30;
                        else if (i >= 11 && i <= 15)
                            valor_bilheteria += 15;

                        lugares_ocupados++;
                    }
                }
            }

            cout << "\nFaturamento atual: R$" << valor_bilheteria << endl;
            cout << "Quantidade de lugares ocupados: " << lugares_ocupados << endl;
            break;

        case 0:
            cout << "Encerrando o programa. O faturamento total foi de R$" << valor_bilheteria << endl;
            break;

        default:
            cout << "Opção inválida. Tente novamente.\n";
        }

    } while (escolha != 0);


    for (i = 1; i <= LIN; ++i)
    {
        delete[] mat[i];
    }

    delete[] mat;

    return 0;
}