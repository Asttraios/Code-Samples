#include "Headers/Admin.h"
#include <SFML/Audio.hpp>


#include <iostream>
using namespace std;

Admin::Admin() : m_window(sf::VideoMode(800, 600), "Space Invaders"), Milano_Player(375.0f, 500.0f), Gameover(m_window)
{
    srand(time(NULL));      //umowzliwienie losowania liczb
    int enemyRowCount = 3;  //liczba rzedow
    int enemyColumnCount = 7;       //liczba kolumn
    float enemySpacing = 60.0f;     //przerwa miedzy przeciwnikami

    float startX = (m_window.getSize().x - enemyColumnCount * enemySpacing) / 2.0f;     //wpolrzedna startowa x
    float startY = 50.0f;       //wspolrzedna startowa y

    for (int row = 0; row < enemyRowCount; row++)
    {
        for (int col = 0; col < enemyColumnCount; col++)
        {
            float x = startX + col * enemySpacing;      //dodawanie kolejnych przeciwnikow w rownych rzedach
            float y = startY + row * enemySpacing;
            InvadersArmy.push_back(Invaders(x, y, 0.07f));
        }
    }
    PlayerPointer = &Milano_Player;     //wskaznik polimorficzny
    hit = false;
    Statistics();                       //wyswietlenie info o statku
}

ostream &operator<<(ostream &COUT, Player &gracz)       //przeciazenie operatora
{

    COUT << "--------Ship name: \"Milano\"--------" << endl;
    COUT<<"--------Crew: Cpt. Tytus B.--------"<<endl;
    COUT<<"-------ARMAMENT: 30mm AUTOCANNON";
    COUT<<"OBJECTIVE: DON'T GET HIT AND ELIMINATE ALL ENEMIES"<<endl<<endl;
    COUT<<"CONTROLS: HOLD SPACEBAR-SHOOT; ARROW KEYS LEFT/RIGHT- MOVEMENT"<<endl;
    COUT<<"REMEMBER- ONE HIT AND YOU'RE DEAD!"<<endl<<endl;


    return COUT;
}

   bool operator>=(Player &position1, Invaders&position2){

    if(position1.getPosition().y>=600||position2.getShape().getPosition().y>=600||position1.getPosition().x>=800||position2.getShape().getPosition().x>=60)
    {
    return true;

    }
    else return false;

   }

int operator-(Player &gracz, Invaders &kosmita){

    int distance= gracz.getPosition().y-kosmita.getShape().getPosition().y;
    return distance;


}

void Admin::Statistics()            //wyswietlenie info o statku
{
    cout <<  Milano_Player;
    int odl=Milano_Player-InvadersArmy[0];
    int odl2=Milano_Player-InvadersArmy[10];
    int odl3=Milano_Player-InvadersArmy[19];
    
    cout<<"ANALIZA KOMPUTERA BALISTYCZNEGO:"<<endl;
    cout<<"Odleglosc statku od 1 rzedu przeciwnika: "<<odl<<endl;   //dzieki przeciazeniu jest to mozliwe
     cout<<"Odleglosc statku od 2 rzedu przeciwnika: "<<odl2<<endl;
      cout<<"Odleglosc statku od 3 rzedu przeciwnika: "<<odl3<<endl;
      
}

Admin::~Admin()
{
    cout << "gra zniszczona";
        //destruktor gry
}

void Admin::run()
{
    sf::Music music;
    if (!music.openFromFile("SpaceInvadersOST.wav"))
        int b = 9; // error             nie wykorzytana funkcja
    music.play();
    music.setLoop(true);

    while (m_window.isOpen())       //glowna petla gry
    {
        processEvents();
        updateGameplay();
        renderGame();
    }
}

void Admin::processEvents()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            m_window.close();
    }
}

void Admin::invaderHitCheck()
{
    for (int i = 0; i < InvadersArmy.size(); i++)
    {
        for (int j = 0; j < PlayerAmmo.size(); ++j)
        {
            if (PlayerAmmo[j].getShape().getGlobalBounds().intersects(InvadersArmy[i].getShape().getGlobalBounds()))    //czy hitboxy pocisku gracza koliduja ze statkiem wroga
            {
                // Pocisk trafil wroga- usun pocisk i statek
                InvadersArmy.erase(InvadersArmy.begin() + i);
                PlayerAmmo.erase(PlayerAmmo.begin() + j);
                --i;

                break;
            }
        }
    }
}

void Admin::playerHitCheck()
{
    for (int z = 0; z < InvaderAmmo.size(); z++)
    {
        if (InvaderAmmo[z].getShape().getGlobalBounds().intersects(Milano_Player.getPlayerShape().getGlobalBounds()))   //sprawdzenie czy trafiono nas
        {

            hit = true;

            break;
        }
    }
}

void Admin::enemyMovement()
{
    for (int i = 0; i < InvadersArmy.size(); i++)
    {
        if (InvadersArmy[i].getShape().getPosition().x <= 0 ||
            InvadersArmy[i].getShape().getPosition().x >= m_window.getSize().x - InvadersArmy[i].getShape().getSize().x)    //jeśli przeciwnicy dotkna krawedzi to zmieniaja kierunek
        {
            for (int t = 0; t < InvadersArmy.size(); t++)
            {
                InvadersArmy[t].changeDirection();  //zmiana kierunku
            }
            break;
        }
    }
}

void Admin::playerShootControl()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && PlayerFireClock.getElapsedTime() >= PlayerFireRate)
    {

        PlayerAmmo.push_back(LaserBeam(Milano_Player.getPosition().x+35, Milano_Player.getPosition().y));  //strzelanie przez gracza
        PlayerFireClock.restart();
    }
}

void Admin::invaderShootControl()
{
    int index = rand() % (InvadersArmy.size()); //losowanie indeksu kosmity
    if (InvaderFireClock.getElapsedTime() >= InvaderFireCycle)
    {
        InvaderAmmo.push_back(LaserBeam(InvadersArmy[index].getShape().getPosition().x+30, InvadersArmy[index].getShape().getPosition().y));   //stworzenie pocisku losowego kosmity
        InvaderFireClock.restart();
    }

}


void Admin::playit()
{
    sf::Music music;
    if (!music.openFromFile("SpaceInvadersOST.wav"))
        int b = 9; // error             nie wykorzytana funkcja
    music.play();
    music.setLoop(true);
}

void Admin::updateGameplay()
{

    PlayerPointer->update();    //wskaznik polimorfimczny

    for (int i = 0; i < InvadersArmy.size(); i++)
    {
        InvadersArmy[i].refreshInvader();       //szybkosc kosmitow
    }

    invaderHitCheck();      //czy trafiono kosmitow

    playerHitCheck();       //czy trafiono gracza

    if (InvadersArmy.empty())
    {
        visible = false;

        Gameover.displayEndScreen();        //jesli zniszczono wszsytskich kosmitow to gracz wygrywa
        return; // zatrzymaj aktualizacje gry po wyswietleniu "Victory"
    }

    if (hit)
    {
        Gameover.displayDefeat();   //jesli trafiono gracza to wyswietl "Defeat"
        visible = false;
        return;
    }

    enemyMovement();    //aktualizacja ruchu preciwnika

    playerShootControl();   //kontrola strzelania graczem

    invaderShootControl();      //kontrola ognia kosmitow

    for (int y = 0; y < InvaderAmmo.size(); y++)
    {
        InvaderAmmo[y].updateInvadersBeam();        //aktualizacja pociskow kosmitow
    }

    for (int p = 0; p < PlayerAmmo.size(); p++)
    {
        PlayerAmmo[p].updatePlayerBeam();

        if (PlayerAmmo[p].getShape().getPosition().y <= 0)      //usuwanie pociskow gracza jesli wyjda po za ekran
        {
            PlayerAmmo.erase(PlayerAmmo.begin() + p);
            p--;
        }
    }
}
void Admin::renderGame()
{
    if (visible)
    {
        m_window.clear();       //wyswietlanie wszystkich elementow gry

        PlayerPointer->render(m_window);

        for (int j = 0; j < InvaderAmmo.size(); j++)
        {
            InvaderAmmo[j].beamRender(m_window);
        }

        for (int u = 0; u < PlayerAmmo.size(); u++)
        {
            PlayerAmmo[u].beamRender(m_window);
        }

        for (int i = 0; i < InvadersArmy.size(); i++)
        {
            InvadersArmy[i].invaderRender(m_window);
        }

        m_window.display();
    }
}
