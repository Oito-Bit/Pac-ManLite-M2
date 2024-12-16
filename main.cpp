#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void menuInicial (int&menu,string&nome)
{
    cout<<"\nBEM VINDO AO PAC-MAN LITE, \033[33m"<<nome<<"\033[0m!\n\nMENU\n\n[ 1 ] JOGAR\n[ 2 ] ESCOLHER A DIFICULDADE\n[ 3 ] SOBRE E COMO JOGAR\n[ 4 ] RANK TOP 5\n[ 5 ] SAIR\n"<< endl;
    cin>>menu;
}
///Função que salva as variáveis em um arquivo
void salvandoPontos(string nome,int dificuldade,int pontos,int vidas,int vidasAUX,int fase,int minutos,int segundos,int segundos2)
{
    ofstream arquivo("pontuacoes.txt", ios::app); // Abre o arquivo para adicionar dados
    if (arquivo.is_open())
    {
        // Salva todas as variáveis no arquivo
        arquivo<<nome<<" "<<dificuldade<<" "<<pontos<<" "<<vidas<<" "<<vidasAUX<< " "<<fase<<" "<<minutos<<" "<<segundos2<<" "<<segundos<<"\n\n";
        arquivo.close(); // Fecha o arquivo
    }
    else
    {
        cout<<"Erro, pontuação não salva!\nSinto muito, "<<nome<<"\n\n";
    }
}
///Struct para o ranked
struct Pontuacao   //Salva todas as variáveis que vão ser escritas no console
{
    string nome;
    int dificuldade;
    int pontos;
    int vidas;
    int vidasAUX;
    int fase;
    int minutos;
    int segundos;
    int segundos2;
    int valorRank; //(Ordem das pontuações)
};
///Bool para comparar pontuações
bool comparaPontuacoes(const Pontuacao&a,const Pontuacao&b)
{
    return a.valorRank>b.valorRank;//Maior primeiro
}
///Função que coloca mapas em "m"
void gerarMapas(int pontos,int&alvo,int dificuldade,int m[22][33],int fase)
{
    if (fase==1)
    {
        int a[22][33] =
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,
            1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,
            1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,
            1,2,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,2,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        };
        for (int i = 0; i < 22; ++i)
        {
            for (int j = 0; j < 33; ++j)
            {
                m[i][j]=a[i][j];///TRANSFERE A NOVA MATRIZ PARA A QUE VAI SER USADA NO JOGO
            }
        }
    }
    if (fase==2)
    {
        int a[22][33] =
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,1,1,2,1,2,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,2,1,2,1,1,1,2,1,
            1,2,1,1,1,2,1,2,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,2,1,2,1,1,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,2,1,1,1,2,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        };
        for (int i = 0; i < 22; ++i)
        {
            for (int j = 0; j < 33; ++j)
            {
                m[i][j]=a[i][j];///TRANSFERE A NOVA MATRIZ PARA A QUE VAI SER USADA NO JOGO
            }
        }
    }
    if (fase==3)
    {
        int a[22][33] =
        {
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,2,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,2,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,1,1,2,1,1,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,1,1,2,1,1,1,2,1,
            1,2,1,1,1,2,1,1,1,2,1,1,1,1,1,9,5,9,1,1,1,1,1,2,1,1,1,2,1,1,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,1,2,1,2,2,2,2,2,2,2,2,2,2,1,1,1,2,2,2,2,2,2,2,2,2,2,1,2,1,2,1,
            1,2,1,2,1,2,1,2,1,2,1,1,1,1,2,1,1,1,2,1,1,1,1,2,1,2,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,
            1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,
            1,2,1,2,1,2,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,
            1,6,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,6,1,
            1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        };
        for (int i = 0; i < 22; ++i)
        {
            for (int j = 0; j < 33; ++j)
            {
                m[i][j]=a[i][j];///TRANSFERE A NOVA MATRIZ PARA A QUE VAI SER USADA NO JOGO
            }
        }
    }
}
///Func. que checam derrota ou vitoria
bool checarJogo (int&vidas,bool dano,bool&perdeuVida)
{
    ///VERIFICA SE HOUVE GAME OVER
    if (dano==true) //Perde vida
    {
        if (vidas==1) //Última?
        {
            perdeuVida=true;
            return true;
        }
        else //Mais vidas?
        {
            vidas--; //Diminúi vida
            perdeuVida=true; //Sianaliza que perdeu vida
            return false;
        }
    }
    ///FIM GAME OVER
    return false;
}
bool checarJogo (int m [22][33])
{
    ///VERIFICA SE HOUVE VITÓRIA
    for (int i=0; i<22; ++i)
    {
        for (int j=0; j<33; ++j)
        {
            if (m[i][j]==2)
            {
                return false;
            }
        }
    }
    return true;
    ///FIM GAME OVER
}
///Gerencia posições e estado de fantasmas
struct Fantasma
{
    int x, y;//Posições
    bool vivo;//vivo ou morto
    DWORD tickSpeed;//Velocidade
};
///Fun.c da IA
char escolherDirecaoSegura(int pacX, int pacY, Fantasma fantasmas[], int m[22][33])
{
    std::srand(std::time(0));//
    int rand=std::rand()%7+6;
    // Movimentos: {cima,baixo,esquerda,direita}
    int movimentos[4][2] =
    {
        {-1,0},//Cima
        {1,0},//Baixo
        {0,-1},//Esquerda
        {0,1}//Direita
    };

    int melhorDirecao=-1;
    int menorPerigo=INT_MAX;
    static char ultimaDirecao='d';  // Direção padrão inicial
    static char opostaDirecao;// Direção oposta à última

    ///Define a direção oposta com base na última
    switch (ultimaDirecao)
    {
    case 'w':
        opostaDirecao = 's';
        break;
    case 's':
        opostaDirecao = 'w';
        break;
    case 'a':
        opostaDirecao = 'd';
        break;
    case 'd':
        opostaDirecao = 'a';
        break;
    default:
        opostaDirecao = 'd';
        break;
    }

    for (int i=0; i<4; i++)///Verifica todos os movimentos possíveis
    {
        int nx=pacX+movimentos[i][0];
        int ny=pacY+movimentos[i][1];

        ///Verifica célula válida
        if (m[nx][ny]==1||m[nx][ny]==5||m[nx][ny]==9)
        {
            continue; //Pula células bloqueadas
        }

        ///Calcula o perigo
        int perigo=0;
        for (int j=0; j<4; j++)
        {
            if (fantasmas[j].vivo)
            {
                int distancia=abs(fantasmas[j].x-nx)+abs(fantasmas[j].y-ny);
                if (distancia<rand)
                {
                    perigo+=(rand-distancia);//Quanto mais próximo, maior o perigo
                }
            }
        }

        ///Evita a direção oposta à última para prevenir movimentos de vai-e-volta
        char direcaoAtual;
        switch (i)
        {
        case 0:
            direcaoAtual='w';
            break;
        case 1:
            direcaoAtual='s';
            break;
        case 2:
            direcaoAtual='a';
            break;
        case 3:
            direcaoAtual='d';
            break;
        }
        if (direcaoAtual==opostaDirecao)
        {
            perigo+=5;//Penalidade para evitar loops
        }

        //Melhor direção
        if (perigo<menorPerigo)
        {
            menorPerigo=perigo;
            melhorDirecao=i;
        }
    }

    // Selecione a direção com base no índice `melhorDirecao`
    if (melhorDirecao!=-1)
    {
        switch (melhorDirecao)
        {
        case 0:
            ultimaDirecao='w';
            return 'w'; // Cima
        case 1:
            ultimaDirecao='s';
            return 's'; // Baixo
        case 2:
            ultimaDirecao='a';
            return 'a'; // Esquerda
        case 3:
            ultimaDirecao='d';
            return 'd'; // Direita
        }
    }

    //Se está encurralado volta
    return ultimaDirecao;
}
///Func. do Pac-Man
void pacMan (char tecla,int&pacX,int&pacY,int&direcaoX,int&direcaoY,int&direcao,int m[22][33],int&pontos,
             bool&jogando,bool&perdeuVida,bool&poderAtivo,bool maquinaJogando,Fantasma fantasmas[],bool&bonusPresente)
{
///FUNÇÃO DE PONTUAÇÃO
    if (m[pacX][pacY]==2)
    {
        pontos+=1;
        m[pacX][pacY]=0;
    }
    if (m[pacX][pacY]==4)
    {
        pontos+=5;
        m[pacX][pacY]=0;
        bonusPresente=false;
    }
    if (m[pacX][pacY]==6)
    {
        pontos+=2;
        poderAtivo=true;
        m[pacX][pacY]=0;
    }
///FIM DAS FUNÇÕES DE PONTUAÇÃO

///FUNÇÃO DE MOVIMENTO
    static char ultimo; //guarda os comandos
    if ( _kbhit()&&maquinaJogando==false) //Detecta comandos da direção do teclado
    {
        tecla = getch();
        switch(tecla)
        {
        case 72:
        case 'w': //cima
            if (m[pacX-1][pacY]!= 1&&m[pacX-1][pacY]!=5&&m[pacX-1][pacY]!=9)
            {
                direcao=4;
                direcaoX=-1;
                direcaoY=0;
                ultimo = tecla;
                return;
            }
            else
            {
                ultimo = tecla;
            }
            break;
        case 80:
        case 's': //baixo
            if (m[pacX+1][pacY]!=1&&m[pacX+1][pacY]!=5&&m[pacX+1][pacY]!=9)
            {
                direcao=3;
                direcaoX=1;
                direcaoY=0;
                ultimo = tecla;
                return;
            }
            else
            {
                ultimo = tecla;
            }
            break;
        case 75:
        case 'a': //esquerda
            if (m[pacX][pacY-1]!=1&&m[pacX][pacY-1]!=5&&m[pacX][pacY-1]!=9)
            {
                direcao=2;
                direcaoY=-1;
                direcaoX=0;
                ultimo = tecla;
                return;
            }
            else
            {
                ultimo = tecla;
            }
            break;
        case 77:
        case 'd': //direita

            if (m[pacX][pacY+1]!=1&&m[pacX][pacY+1]!=5&&m[pacX][pacY+1]!=9)
            {
                direcao=1;
                direcaoY=1;
                direcaoX=0;
                ultimo = tecla;
                return;
            }
            else
            {
                ultimo = tecla;
            }
            break;
        }
    }
    else if (maquinaJogando==true)
    {
        ultimo=escolherDirecaoSegura(pacX,pacY,fantasmas,m);
    }

    {
        //Detecta comandos da direção armazenados
        switch(ultimo)
        {
        case 72:
        case 'w': //cima
            if (m[pacX-1][pacY]!=1&&m[pacX-1][pacY]!=5&&m[pacX-1][pacY]!=9)
            {
                direcao=4;
                direcaoX=-1;
                direcaoY=0;
                return;
            }
            break;
        case 80:
        case 's': //baixo
            if (m[pacX+1][pacY]!=1&&m[pacX+1][pacY]!=5&&m[pacX+1][pacY]!=9)
            {
                direcao=3;
                direcaoX=1;
                direcaoY=0;
                return;
            }
            break;
        case 75:
        case 'a': //esquerda
            if (m[pacX][pacY-1]!=1&&m[pacX][pacY-1]!=5&&m[pacX][pacY-1]!=9)
            {
                direcao=2;
                direcaoY=-1;
                direcaoX=0;
                return;
            }
            break;
        case 77:
        case 'd': //direita

            if (m[pacX][pacY+1]!=1&&m[pacX][pacY+1]!=5&&m[pacX][pacY+1]!=9)
            {
                direcao=1;
                direcaoY=1;
                direcaoX=0;
                return;
            }
            break;
        }
    }
///FIM DA FUNÇÃO DE MOVIMENTO
}
///Verifica quem morre
void colisao (int pacX,int pacY,int fantasmaX,int fantasmaY,bool&vivo,bool poderAtivo,bool&dano,int&pontos)
{
    /// Verifica se o Pac-Man está perto do fantasma
    if ((((abs(fantasmaX-pacX)<=1)&&(abs(fantasmaY-pacY)==0))||((abs(fantasmaX-pacX)==0)&&(abs(fantasmaY-pacY)==1)))&&(vivo==true))
    {
        if (poderAtivo==true) //Pac-Man está com powerup
        {
            vivo=false; //O fantasma morre
            pontos+=10;
            return;
        }
        else //Se o Pac-Man não está com powerup
        {
            dano=true; //O Pac-Man morre
            return;
        }
    }
}
///Auxilia limites do mapa
int clamp(int value,int mini,int maxi)
{
    if (value<mini)
    {
        return (mini+1);
    }
    else if (value>maxi)
    {
        return (maxi-1);
    }
    else
    {
        return value;
    }
}
///Auxilia na perseguição do pacman
void perseguir (int pacX,int pacY,int&fantasmaX,int&fantasmaY,int alvoX,int alvoY,int m[22][33],bool&dano,bool poderAtivo,bool&vivo)
{
    alvoX=clamp(alvoX,0,22); //Ajusta o alvo dentro dos limites do mapa
    alvoY=clamp(alvoY,0,33);

    ///BUSCA EM LARGURA
    bool encontrou=false;//auxiliar para encontrar o caminho
    /// Verifica onde o alvo está, se pode mover-se na direção, e aplica o movimento
    //Calcula a próxima céula usando a "busca em largura"
    std::queue<std::pair<int,int>>fila; //Usa fila para explorar as células possíveis
    int visitado[22][33]= {0}; //Marca as células visitadas
    int dx[]= {-1,1,0,0}; //Direções possíveis
    int dy[]= {0,0,-1,1};
    std::pair<int, int>anterior[22][33];//De onde o fantasma veio
    fila.push({fantasmaX, fantasmaY});
    visitado[fantasmaX][fantasmaY] = 1;
    anterior[fantasmaX][fantasmaY] = {-1, -1}; //Do alvo até o ponto de partida
    while (!fila.empty())
    {
        auto [x,y]=fila.front();
        fila.pop();
        ///Interrompe a busca quand oencontra o alvo
        if (x==alvoX&&y==alvoY)
        {
            encontrou=true;
            break;
        }
        ///Explora células vizinhas
        for (int i=0; i<4; i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if ((m[nx][ny]!=1&&m[nx][ny]!=5&&m[nx][ny]!=9&&!visitado[nx][ny])||(vivo==false&&m[nx][ny]!=1&&m[nx][ny]!=5&&!visitado[nx][ny]))
            {
                fila.push({nx,ny});
                visitado[nx][ny]=1;
                anterior[nx][ny]= {x, y};
            }
        }
    }
    ///Encontrou o caminho, segue o próximo passo
    if (encontrou==true)
    {
        int cx=alvoX, cy=alvoY;
        //Volta até o próximo passo
        while (anterior[cx][cy]!=std::make_pair(fantasmaX, fantasmaY)) ///Loop de reconstrução
        {
            if (anterior[cx][cy]==std::make_pair(-1, -1))
            {
                return; //inválido
            }
            if (fantasmaX==alvoX&&fantasmaY==alvoY)
            {
                return; //O fantasma já está aqui
            }

            auto[px,py]=anterior[cx][cy];
            cx=px;
            cy=py;
        }

        ///Move o fantasma para o próximo passo
        fantasmaX=cx;
        fantasmaY=cy;
    }
}
///Gerencia as ações do fantasma quando morto
void estaMorto(int pacX,int pacY,int&fantasmaX,int&fantasmaY,int spawnX,int spawnY,int m[22][33],bool dano,bool poderAtivo,bool&vivo)
{
    static DWORD tempoMorto = 0;
    DWORD currentTime = GetTickCount();
    if (vivo==false)///Ainda não chegou
    {
        // Move para o spawn
        perseguir(pacX, pacY, fantasmaX, fantasmaY, spawnX, spawnY, m, dano, poderAtivo, vivo);

    }
    if (fantasmaX==spawnX&&fantasmaY==spawnY)   ///Chegou ao spawn
    {
        if (tempoMorto==0)
        {
            tempoMorto=currentTime;
        }
        if (currentTime-tempoMorto > 1999)   ///Espera 2 segundos
        {
            vivo=true; // Revive o fantasma
            tempoMorto = 0;
        }
        return;
    }
}
///Fantasma que persegue diretamente
void fantasma_shadow (int pacX,int pacY,int&shadowX,int&shadowY,int m[22][33],bool&dano,bool poderAtivo,bool&shadow)
{
    if (shadow==false) ///está morto
    {
        estaMorto (pacX,pacY,shadowX,shadowY,10,15,m,dano,poderAtivo,shadow); //persegue o spawn
        return;
    }
    if (poderAtivo==false&&shadow==true) ///está vivo e pacman está desprotegido
    {
        perseguir (pacX,pacY,shadowX,shadowY,pacX,pacY,m,dano,poderAtivo,shadow); //Persegue o pacman normalmente
    }
    if (poderAtivo==true&&shadow==true) ///está vivo e o pacman está protegido
    {
        perseguir (pacX,pacY,shadowX,shadowY,0,0,m,dano,poderAtivo,shadow); //Vai para o canto superior esquerdo do mapa
    }
}
///Fantasma que tenta passar á frente
void fantasma_pinky (int pacX,int pacY,int pacDX,int pacDY,int&pinkyX,int&pinkyY,int m[22][33],bool&dano,bool poderAtivo,bool&pinky)
{
    if (pinky==false) ///está morto
    {
        estaMorto (pacX,pacY,pinkyX,pinkyY,10,17,m,dano,poderAtivo,pinky); //persegue o spawn
        return;
    }
    if (poderAtivo==false&&pinky==true) ///está vivo e pacman está desprotegido
    {
        if (pacDX>0)
        {
            perseguir (pacX,pacY,pinkyX,pinkyY,pacX+2,pacY,m,dano,poderAtivo,pinky); //Tenta emboscar o pacman na direção que ele vai (baixo)
            return;
        }
        if (pacDX<0)
        {
            perseguir (pacX,pacY,pinkyX,pinkyY,pacX-2,pacY+2,m,dano,poderAtivo,pinky); //"""""""""""" (cima) ** propositalmente move para esquerda
            return;
        }
        if (pacDY<0)
        {
            perseguir (pacX,pacY,pinkyX,pinkyY,pacX,pacY-2,m,dano,poderAtivo,pinky); //"""""""""""" (esquerda)
            return;
        }
        if (pacDY>0)
        {
            perseguir (pacX,pacY,pinkyX,pinkyY,pacX,pacY+2,m,dano,poderAtivo,pinky); //"""""""""""" (direita)
            return;
        }
    }
    if (poderAtivo==true&&pinky==true) ///está vivo e o pacman está protegido
    {
        perseguir (pacX,pacY,pinkyX,pinkyY,0,33,m,dano,poderAtivo,pinky); //Vai para o canto superior direito do mapa
    }
}
///Fantasma com o cálculo maluco
void fantasma_inky (int pacX,int pacY,int pacDX,int pacDY,int&inkyX,int&inkyY,int m[22][33],bool&dano,bool poderAtivo,bool&inky,int shadowX,int shadowY)
{
    if (inky==false) ///está morto
    {
        estaMorto (pacX,pacY,inkyX,inkyY,11,15,m,dano,poderAtivo,inky); //persegue o spawn
        return;
    }
    if (poderAtivo==false&&inky==true) ///está vivo e pacman está desprotegido
    {
        int alvoX=((pacX*2)-shadowX); // Coordenada futura baseada em direção
        int alvoY=((pacY*2)-shadowY);
        perseguir(pacX,pacY,inkyX,inkyY,alvoX,alvoY,m,dano,poderAtivo,inky); //persegue normalmente
    }
    if (poderAtivo==true&&inky==true) ///está vivo e o pacman está protegido
    {
        perseguir (pacX,pacY,inkyX,inkyY,22,0,m,dano,poderAtivo,inky); //Vai para o canto inferior esquerdo do mapa
    }
}
///Fantasma que foge
void fantasma_clyde (int pacX,int pacY,int&clydeX,int&clydeY,int m[22][33],bool&dano,bool poderAtivo,bool&clyde)
{
    if (clyde==false) ///está morto
    {
        estaMorto (pacX,pacY,clydeX,clydeY,11,17,m,dano,poderAtivo,clyde); //persegue o spawn
        return;
    }
    if (poderAtivo==false&&clyde==true) ///está vivo, pacman está desprotegido
    {
        if (abs(clydeX-pacX)+abs(clydeY-pacY)<6) ///Está perto de clyde
        {
            perseguir(pacX,pacY,clydeX,clydeY,22,33,m,dano,poderAtivo,clyde); // Vai para o canto inferior direito
            return;
        }
        else ///Está longe
        {
            perseguir(pacX,pacY,clydeX,clydeY,pacX,pacY,m,dano,poderAtivo,clyde); //persegue normalmente
            return;
        }
    }
    if (poderAtivo==true&&clyde==true) ///está vivo e o pacman está protegido
    {
        perseguir (pacX,pacY,clydeX,clydeY,22,33,m,dano,poderAtivo,clyde); //Vai para o canto inferior direito do mapa
    }
}
///Func. que auxilia nas config. de dificuldade
void setarStatus (int menuVoid,int&velocidade,int&vidas,int&vidasAUX,int&dificuldade)
{
    if (menuVoid==1) ///dificuldade 1
    {
        velocidade=299;
        vidas=4;
        vidasAUX=vidas;//console
        dificuldade=1;//Seta dificuldade
        return;
    }
    else if (menuVoid==2) ///dificuldade 2
    {
        velocidade=324;
        vidas=3;
        vidasAUX=vidas;//console
        dificuldade=2;//Seta dificuldade
        return;
    }
    else if (menuVoid==3) ///dificuldade 3
    {
        velocidade=349;
        vidas=2;
        vidasAUX=vidas;//console
        dificuldade=3;//Seta dificuldade
    }
}
///Func. que gera o item bônus
void chanceBonus(int m[22][33],bool&bonusPresente)
{
    if (bonusPresente==false)///Se não há powerup
    {
        int l=(rand()%7); //D7
        int k=(rand()%7);
        if (l==k) //caiu
        {
            bool controle=false;
            do
            {
                int j=1+(rand()%33); //randomiza horizontalmente
                int i=1+rand()%22; //randomiza verticalmente
                if (m[i][j]==0)  ///Coloca um bônus no mapa se a célula aleatória estiver vazia
                {
                    m[i][j]=4; //Coloca bônus
                    return; //Sai da func.
                }
            }
            while (controle==false);
        }
    }
}
int main()
{
    int menu,submenu,dificuldade=1,pontos=0,alvo=346,vidas=3,vidasAUX=3,fase=1; ///Todas as variáveis de menu e de jogo
    bool jogando=false,perdeuVida=false,poderAtivo=false,maquinaJogando=false,desafioAtivo=false,bonusPresente=false;///Variáveis bool auxilaires

    /// Variáveis do Pac-Man
    int x=1,y=15;//Posição do Pac-Man
    int direcao=1;//Auxilia na animação do pacman
    int velocidade=299;//Velocidade do pacman
    bool close=true,dano=false;// ''''''''
    int direcaoX=0,direcaoY=1;//Variáveis de direção do Pac-Man

    /// Variáveis de Timer
    int segundos,segundos2,minutos,poderAtivoAUX=0,segundosFantasma=0;

    string nome;
    int m[22][33];///Matriz mapa
    cout<<"\nBEM VINDO AO PAC-MAN LITE!\n\nInsira seu \033[33mnome de jogador: \033[0m"<<endl;
    cin>>nome;
    system("cls");//limpa a tela
    menuInicial (menu,nome);//chama o menu
    while (menu!=5)
    {
        switch (menu)
        {
        case 1:
            /// Inicializa os fantasmas com suas posições iniciais e status
            Fantasma fantasma[4];
            fantasma[0]= {10,15,true,349}; // Shadow
            fantasma[1]= {10,17,false,349}; // Pinky
            fantasma[2]= {11,15,false,349}; // Inky
            fantasma[3]= {11,17,false,349}; // Clyde
            segundosFantasma=0;
            ///Inicializa outras variáveis do jogo
            fase=1;
            jogando=true;//jogando agora
            perdeuVida=false;
            poderAtivo=false;
            bonusPresente=false;
            dano=false; //seta bools para false
            pontos=0;
            vidas=3;
            vidasAUX=3;//seta variáveis de jogo para o padrão
            segundos2=0;
            segundos=0;
            minutos=0;//zera o timer
            gerarMapas(pontos,alvo,dificuldade,m,fase);//Organiza o mapa
            system("cls");//limpa a tela
///COMEÇA O JOGO
            do
            {
                // INICIO: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
                HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
                CONSOLE_CURSOR_INFO cursorInfo;
                GetConsoleCursorInfo(out, &cursorInfo);
                cursorInfo.bVisible = false; // set the cursor visibility
                SetConsoleCursorInfo(out, &cursorInfo);
                // FIM: COMANDOS PARA QUE O CURSOR NAO FIQUE PISCANDO NA TELA
                // INICIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA
                short int CX = 0, CY = 0;
                COORD coord;
                coord.X = CX;
                coord.Y = CY;
                // FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INICIO DA TELA

                // Inicializa o gerador de números aleatórios
                srand(static_cast<unsigned int>(time(0)));
                // Variável para tecla pressionada
                char tecla='d';

                /// COMEÇO DAS VARIÁVEIS DE TEMPO
                DWORD lastUpdate = GetTickCount(); //Contagem de ticks para pacman
                DWORD lastTimer = GetTickCount(); //Contagem de ticks para o timer
                /// FIM DAS VARIÁVEIS DE TEMPO

                ///Enquanto não houver game over:
                while (jogando==true)
                {
                    // Posiciona a escrita no início do console
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                    ///COMEÇO DE DWORD TIMER
                    DWORD currentTimer=GetTickCount();
                    if (currentTimer-lastTimer>999) ///Tick equivalente a um segundo
                    {
                        segundos++;///Unidade
                        segundosFantasma++;
                        if (segundos>9)
                        {
                            segundos=0;
                            segundos2++;///Dezena
                            chanceBonus(m,bonusPresente);
                        }
                        if (segundos2>5)
                        {
                            segundos2=0;
                            minutos++;///Minutos
                            if (desafioAtivo==true&&minutos>1)  //em dois minutos perde pontos
                            {
                                pontos-=25;
                            }
                        }
                        if (poderAtivo==true) ///Se o Pac-Man tem powerup
                        {
                            poderAtivoAUX++;//conta 1 segundo
                            if (poderAtivoAUX>5)//no sexto
                            {
                                poderAtivo=false;
                                poderAtivoAUX=0;
                            }
                        }
                        lastTimer=currentTimer;
                    }
                    ///FIM DWORD TIMER

                    ///COMEÇO DWORD PARA CHAMAR ENTIDADES
                    DWORD currentTick=GetTickCount();
                    //Chama as entidades em seus próprios ticks
                    ///pac-man
                    if (currentTick-lastUpdate>velocidade)///Tick para Pac-Man
                    {
                        //Checa se algum fantasma colidiu ou matou Pac-Man
                        if (checarJogo(vidas,dano,perdeuVida)==true)
                        {
                            jogando=0; //Para o jogo
                            menu=7; //Menu de derrota
                        }
                        //Checa se ainda há bolinhas no mapa
                        if (checarJogo(m)==true) ///Verifica a condição de vitória
                        {
                            if (fase==3)  //Se é a última fase
                            {
                                jogando=false; // Para o jogo e retorna ao menu
                                menu=6;
                            }
                            fase++;//Se não, apenas passa a fase
                            x=1,y=15;//Posição do Pac-Man
                            direcaoY=1,direcaoX=0;//Direcao do Pac-Man
                            fantasma[0]= {10,15,true,349}; // Shadow
                            fantasma[1]= {10,17,false,349}; // Pinky
                            fantasma[2]= {11,15,false,349}; // Inky
                            fantasma[3]= {11,17,false,349}; // Clyde
                            segundosFantasma=0;
                            gerarMapas(pontos,alvo,dificuldade,m,fase);//Organiza o mapa e reseta os fantasmas
                            Sleep(1500);
                        }
                        //Checa se o caminho do Pac-Man é valido
                        if (m[x+direcaoX][y+direcaoY]!=1&&m[x+direcaoX][y+direcaoY]!=5&&m[x+direcaoX][y+direcaoY]!=9)
                        {
                            x+=direcaoX;
                            y+=direcaoY;//Aplica os movimentos
                        }
                        ///Requisita o próximo paço
                        pacMan (tecla,x,y,direcaoX,direcaoY,direcao,m,pontos,jogando,
                                perdeuVida,poderAtivo,maquinaJogando,fantasma,bonusPresente);
                        close=!close; ///Animação
                    }
                    if (currentTick-lastUpdate>349)///Tick para Fantasmas
                    {
                        ///Analisa colisão de todos os fantasmas e define suas velocidades
                        for (int k = 0; k < 4; k++)
                        {
                            colisao (x,y,fantasma[k].x,fantasma[k].y,fantasma[k].vivo,poderAtivo,dano,pontos);
                            if (fantasma[k].vivo==true)
                            {
                                if(poderAtivo==true)
                                {
                                    fantasma[k].tickSpeed=499;// Velocidade reduzida durante o power-up
                                }
                                else
                                {
                                    fantasma[k].tickSpeed=349;// Velocidade padrão
                                }
                            }
                            else
                            {
                                fantasma[k].tickSpeed=99; // Fantasmas mortos se movem mais rápido para retornar ao spawn
                            }
                        }
                        //fantasmas
                        ///Shadow
                        if (currentTick-lastUpdate>fantasma[0].tickSpeed&&segundosFantasma>0)///Chama shadow
                        {
                            fantasma_shadow(x,y,fantasma[0].x,fantasma[0].y,m,dano,poderAtivo,fantasma[0].vivo);
                        }
                        ///Pinky
                        if ((currentTick-lastUpdate>fantasma[1].tickSpeed)&&segundosFantasma>4)///Chama pinky aos 5s
                        {
                            fantasma_pinky(x,y,direcaoX,direcaoY,fantasma[1].x,fantasma[1].y,m,dano,poderAtivo,fantasma[1].vivo);
                        }
                        ///Inky
                        if ((currentTick-lastUpdate>fantasma[2].tickSpeed)&&segundosFantasma>9)///Chama Inky aos 10s
                        {
                            fantasma_inky(x,y,direcaoX,direcaoY,fantasma[2].x,fantasma[2].y,m,dano,poderAtivo,fantasma[2].vivo,fantasma[0].x,fantasma[0].y);
                        }
                        ///Clyde
                        if ((currentTick-lastUpdate>fantasma[3].tickSpeed)&&segundosFantasma>14)///Chama Clyde aos 15s
                        {
                            fantasma_clyde(x,y,fantasma[3].x,fantasma[3].y,m,dano,poderAtivo,fantasma[3].vivo);
                        }
                        lastUpdate=currentTick; //Finaliza o tick
                    }
                    ///FIM DWORD PARA CHAMAR ENTIDADES

                    /// Imprime o jogo
                    for (int i=0; i<22; i++)
                    {
                        for (int j=0; j<33; j++)
                        {
                            if (i==x&&j==y) ///Primeiro o Personagem
                            {
                                if (perdeuVida==false) ///Player vivo
                                {
                                    if (close==true) //Pacman fechado
                                    {
                                        if (direcao<=2) //Esquerda ou direita
                                        {
                                            cout<<"\033[33m"<<"-"<<"\033[0m";
                                        }
                                        else //Cima ou baixo
                                        {
                                            cout<<"\033[33m"<<"|"<<"\033[0m";
                                        }
                                    }
                                    else
                                    {
                                        if (direcao==1) //Direita
                                        {
                                            cout<<"\033[33m"<<"<"<<"\033[0m";
                                        }
                                        else if (direcao==2) //Esquerda
                                        {
                                            cout<<"\033[33m"<<">"<<"\033[0m";
                                        }
                                        else if (direcao==3) //Baixo
                                        {
                                            cout<<"\033[33m"<<"^"<<"\033[0m";
                                        }
                                        else //Cima
                                        {
                                            cout<<"\033[33m"<<"V"<<"\033[0m";
                                        }
                                    }
                                }
                                else   //Morto
                                {
                                    cout<<"\033[31m"<<char(206)<<"\033[0m"; ///Morreu
                                    Sleep(1500); //Espera
                                    x=1; // Retorna a posição inicial dos personagens no console
                                    y=16;
                                    fantasma[0]= {10,15,true,324}; // Shadow
                                    fantasma[1]= {10,17,false,324}; // Pinky
                                    fantasma[2]= {11,15,false,324}; // Inky
                                    fantasma[3]= {11,17,false,324}; // Clyde
                                    segundosFantasma=0;
                                    perdeuVida=false; //garante que não resete novamente
                                    poderAtivo=false; //remove powerups
                                    dano=false; //seta dano para false
                                }
                            }
                            else if (i==fantasma[0].x&&j==fantasma[0].y&&fantasma[0].vivo==false) ///SHADOW
                            {
                                ///Inimigo shadow morto
                                cout << "\033[32m" << "@" << "\033[0m";
                                // Fantasma morto em verde
                            }
                            else if (i==fantasma[0].x&&j==fantasma[0].y&&poderAtivo==false)  ///Inimigo shadow vivo
                            {
                                if (desafioAtivo==false||((abs(fantasma[0].x-x))+(abs(fantasma[0].y-y))<7))
                                {
                                    cout <<"\033[31m"<<"W"<<"\033[0m";
                                    //Fantasma vermelho
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }
                            else  if (i==fantasma[0].x&&j==fantasma[0].y&&poderAtivo==true)  ///Inimigo shadow medroso
                            {
                                if (desafioAtivo==false||((abs(fantasma[0].x-x))+(abs(fantasma[0].y-y))<7))
                                {
                                    cout <<"w";
                                    //Fantasma amedrontado
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }
                            else if (i==fantasma[1].x&&j==fantasma[1].y&&fantasma[1].vivo==false) ///PINKY
                            {
                                ///Inimigo pinky morto
                                cout<<"\033[32m"<<"@"<<"\033[0m";
                            }//Fantasma morto em verde
                            else if (i==fantasma[1].x&&j==fantasma[1].y&&poderAtivo==false)  /// Inimigo pinky vivo
                            {
                                if (desafioAtivo==false||((abs(fantasma[1].x-x))+(abs(fantasma[1].y-y))<7))
                                {
                                    cout << "\033[35m" << "W" << "\033[0m";
                                    //Fantasma rosa
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }
                            else if (i==fantasma[1].x&&j==fantasma[1].y&&poderAtivo==true)  /// Inimigo pinky medroso
                            {
                                if (desafioAtivo==false||((abs(fantasma[1].x-x))+(abs(fantasma[1].y-y))<7))
                                {
                                    cout<<"w";
                                    //Fantasma amedrontado
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }
                            else if (i==fantasma[2].x&&j==fantasma[2].y&&fantasma[2].vivo==false)  ///INKY
                            {
                                ///Inimigo inky morto
                                cout<<"\033[32m"<<"@"<<"\033[0m";
                            }//Fantasma morto em verde
                            else if (i==fantasma[2].x&&j==fantasma[2].y&&poderAtivo==false)   /// Inimigo inky vivo
                            {
                                if (desafioAtivo==false||((abs(fantasma[2].x-x))+(abs(fantasma[2].y-y))<7))
                                {
                                    cout<< "\033[36m"<<"W"<<"\033[0m";
                                }
                                else    //Fantasma ciano
                                {
                                    cout<<" ";
                                }
                            }
                            else if (i==fantasma[2].x&&j==fantasma[2].y&&poderAtivo==true)   /// Inimigo inky medroso
                            {
                                if (desafioAtivo==false||((abs(fantasma[2].x-x))+(abs(fantasma[2].y-y))<7))
                                {
                                    cout<<"w";
                                    //Fantasma amedrontado
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }//Clyde
                            else if (i==fantasma[3].x&&j==fantasma[3].y&&fantasma[3].vivo==false)  ///CLYDE
                            {
                                ///Inimigo clyde morto
                                cout<<"\033[32m"<<"@"<<"\033[0m";
                            }//Fantasma morto em verde
                            else if (i==fantasma[3].x&&j==fantasma[3].y&&poderAtivo==false)   /// Inimigo clyde vivo
                            {
                                if (desafioAtivo==false||((abs(fantasma[3].x-x))+(abs(fantasma[3].y-y))<7))
                                {
                                    cout<<"\033[33m"<<"W"<<"\033[0m";
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }//Fantasma laranja
                            else if (i==fantasma[3].x&&j==fantasma[3].y&&poderAtivo==true)   /// Inimigo clyde medroso
                            {
                                if (desafioAtivo==false||((abs(fantasma[3].x-x))+(abs(fantasma[3].y-y))<7))
                                {
                                    cout<<"w";//Fantasma amedrontado
                                }
                                else
                                {
                                    cout<<" ";
                                }
                            }
                            else
                            {
                                switch (m[i][j])///Mapa
                                {
                                case 0:
                                    cout<<" ";
                                    break; // caminho
                                case 1:
                                    cout<<"\033[34m"<<char(219)<<"\033[0m";
                                    break; //Parede Azul
                                case 2:
                                    if (desafioAtivo==false||((abs(i-x))+(abs(j-y))<7))
                                    {
                                        cout<<"\033[37m"<<"*"<<"\033[0m";
                                    }
                                    else
                                    {
                                        cout<<" ";
                                    }
                                    break;//Bolinhas brancas
                                case 4:
                                    if (desafioAtivo==false||((abs(i-x))+(abs(j-y))<7))
                                    {
                                        cout<<"\033[33m"<<"$"<<"\033[0m";
                                    }
                                    else
                                    {
                                        cout<<" ";
                                    }
                                    break;//Bônus Amarelo
                                case 6:
                                    if (desafioAtivo==false||((abs(i-x))+(abs(j-y))<7))
                                    {
                                        cout<<"\033[33m"<<"o"<<"\033[0m";
                                    }
                                    else
                                    {
                                        cout<<" ";
                                    }
                                    break;//Powerup Amarelo
                                case 5:
                                case 9:
                                    cout<<"\033[90m"<<char(206)<<"\033[0m";
                                    break;//Cela Cinza
                                default:
                                    cout<<"X";
                                    break; //Debug
                                }
                            }
                        }
                        cout<<"\n";
                    }
                    if (maquinaJogando==false)///Se não é a maquina, mostra o nome
                    {
                        cout<<nome;
                    }
                    else
                    {
                        cout<<"CPU";
                    }
                    cout<<"\n\033[33mVidas: "<<vidas<<"/"<<vidasAUX; //Vidas X de Y
                    cout<<"\nPontos: "<<pontos; //Pontos
                    if (desafioAtivo==true)
                    {
                        cout<<"X2";
                    }
                    cout<<"\nTempo: "<<minutos<<" : "<<segundos2<<segundos<<"\033[0m"; //Timer
                    if (poderAtivo==true) ///Se o pac-man está modificado
                    {
                        cout<<"\nTempo de bonus: 0:0"<<6-poderAtivoAUX; //mostra o timer do bônus
                    }
                    else
                        cout<<"\n                       "; //se não apaga
                }
            }
            while (jogando==1);
            break;
        case 2:
            do
            {
                system("cls");
                cout<<"\nDificuldade atual: ";///Mostra a dificuldade atual
                if (dificuldade==1)
                {
                    cout<<"Facil\n";
                }
                else if (dificuldade==2)
                {
                    cout<<"Medio\n";
                }
                else if (dificuldade==3)
                {
                    cout<<"Dificil\n";
                }
                cout<<"Maquina VS Maquina: ";
                if (maquinaJogando==true)///Mostra se a CPU vs CPU está ativa
                {
                    cout<<"Habilitado\n";
                }
                else
                {
                    cout<<"Desabilitado\n";
                }
                cout<<"Desafio: ";
                if (desafioAtivo==true)///Mostra se desafio está ativo
                {
                    cout<<"Habilitado\n";
                }
                else
                {
                    cout<<"Desabilitado\n";
                }
                cout<<"\nSELECIONAR NOVA DIFICULDADE?\n" << endl; //menu
                cout<<"[ 1 ] FACIL\n";
                cout<<"[ 2 ] MEDIO\n";
                cout<<"[ 3 ] DIFICIL\n";
                cout<<"[ 4 ] MAQUINA VS MAQUINA\n";
                cout<<"[ 5 ] DESAFIO\n";
                cout<<"[ 0 ] SALVAR E SAIR\n";
                cin>>submenu;
                if ((submenu>0)&&(submenu<4))///Se a opção escolhida é de dificuldade
                {
                    setarStatus (submenu,velocidade,vidas,vidasAUX,dificuldade);//puxa func.
                    submenu=99;//reseta esse menu
                }
                if (submenu==4) ///Se é para ativar a CPU
                {
                    maquinaJogando=!maquinaJogando;
                    submenu=99;//reseta esse menu
                }
                if (submenu==5) ///Se é para ativar o desafio
                {
                    desafioAtivo=!desafioAtivo;
                    submenu=99;//reseta esse menu
                }
            }
            while (submenu!=0);///Sai se ==0
            system("cls");
            menuInicial (menu,nome);///Mostra menu inicial
            break;

        case 3: ///MENU SOBRE
            system("cls");//Quem precisa de enter e endl;?
            cout<<"\033[33m"<<"COMO JOGAR PAC-MAN:\n"<<"\033[0m";
            cout<<"1) Utilize 'WASD' ou setas para mover.\n2) Coma todos os pontos no labirinto para vencer.\n3) Evite os fantasmas!\n4) Pegue os Grandes Pontos para ganhar poder temporario contra os fantasmas!\n";
            cout<<"\033[34m"<<"\nPAC-MAN\nFoi lancado pela Namco em 1980.\nE um dos jogos mais iconicos e populares da historia dos videogames.\nO objetivo e simples: coletar pontos enquanto evita fantasmas.\n";
            cout<<"\nPAC-MAN LITE\nEsta e minha versao simplificada do classico.\nCom labirinto, fantasmas e jogabilidade baseada no original.\nDesenvolvido em C++ no Code::Blocks.\n\033[0m";
            menuInicial (menu,nome);//chama o menu inicial
            break;
        case 4:  ///RANKED
        {
            system("cls");
            ifstream arquivo("pontuacoes.txt");///Abre o arquivo
            vector<Pontuacao> pontuacoes;///Coloca as pontuações num vetor (obrigado GPT)
            if (arquivo.is_open())
            {
                Pontuacao p;//struct
                /// Lê todo o arquivo
                while (arquivo>>p.nome>>p.dificuldade>>p.pontos>>p.vidas>>p.vidasAUX>>p.fase>>p.minutos>>p.segundos2>>p.segundos)
                {
                    p.valorRank=p.dificuldade*p.pontos; ///O rank é ordenado pelos pontos multiplicados pela dificuldade
                    pontuacoes.push_back(p); //Adiciona à lista
                }
                arquivo.close();
                /// Ordenar as pontuações pelo valorRank
                sort(pontuacoes.begin(), pontuacoes.end(), comparaPontuacoes);//Bruxaria do GPT
                cout << "Top 5 Rank local:\n";
                for (size_t i=0; i<min(pontuacoes.size(),size_t(5)); ++i)
                {
                    const Pontuacao&p=pontuacoes[i];
                    cout<<p.nome<<", dificuldade: "<<p.dificuldade<<", pontos: "<<p.pontos<<", "<<p.vidas<<"/"<<p.vidasAUX<<", fase: "<<p.fase<<", "<<p.minutos<<":"<<p.segundos2<<p.segundos<<"\n";
                }
            }
            else
            {
                cout<<"Erro ao abrir o Rank local!\nSinto muito, "<<nome<<"\n\n";
            }
            cout<<"\n";
            menuInicial (menu,nome);
        }
        break;
        case 5: ///SAIR
            return 0;
            break;
        case 6: /// VITÓRIA
            system("cls");
            if (maquinaJogando==false)
            {
                cout << "\n\nVOCE VENCEU! PARABENS, "<<nome<<"!\nOBRIGADO POR JOGAR!\n"<< endl;
                salvandoPontos(nome,dificuldade,pontos,vidas,vidasAUX,fase,minutos,segundos,segundos2);
            }
            else if (desafioAtivo==true)
            {
                cout << "\n\nVOCE VENCEU! PARABENS, "<<nome<<"!\nOBRIGADO POR JOGAR!\n"<< endl;
                salvandoPontos(nome,dificuldade,(2*pontos),vidas,vidasAUX,fase,minutos,segundos,segundos2);
            }
            menuInicial (menu,nome);
            break;
        case 7: /// DERROTA
            system("cls");
            if (maquinaJogando==false)
            {
                cout << "\n\nVOCE PERDEU!\nPARABENS, "<<nome<<", PELOS "<<pontos<<" PONTOS!\n"<< endl;
                salvandoPontos(nome,dificuldade,pontos,vidas,vidasAUX,fase,minutos,segundos,segundos2);
            }
            else if (desafioAtivo==true)
            {
                cout << "\n\nVOCE PERDEU!\nPARABENS, "<<nome<<", PELOS "<<(2*pontos)<<" PONTOS!\n"<< endl;
                salvandoPontos(nome,dificuldade,(2*pontos),vidas,vidasAUX,fase,minutos,segundos,segundos2);
            }
            menuInicial (menu,nome);
            break;
        default: /// INVÁLIDO
            system("cls");
            menuInicial (menu,nome);//chama menu
            break;
        }
    }
}
