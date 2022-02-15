// Proiect realizat de Alexa George-Catalin si de Ungureanu Diana Cristina, grupa 1A5.
#include <iostream>
#include <graphics.h>
#include <cstring>
#include <windows.h>
#include <mmsystem.h>
#include <fstream>
#include <stdio.h>
#include <time.h>

using namespace std;
bool eng, stop, song1, settings=0, close=1,menu=1, t=0, table,win=0;
bool clickedPlay=0, clickedNivel1=0, clickedNivel2=0, clickedNivel3=0, clickedNivel4=0, clickedNivel5=0, clickedNivel6=0, clickedNivel7=0, clickedNivel8=0, clickedNivel9=0, clickedNivel10=0;
bool for_level1=0,for_level2=0,for_level3=0,for_level4=0,for_level5=0,for_level6=0,for_level7=0,for_level8=0,for_level9=0,for_level10=0;
int ok=0, k=0, r,i;
int LMBdial1=0, LMBdial2=0,LMBdial3=0,LMBdial4=0;
int p=0, area1=0,area2=0,area3=0,area4=0, varTime=0, seconds=0, minutes=0, hours=0, timePassed, scor=0;
char dial1[100],dial2[100],dial3[100],dial4[100],dialCopy[100];
char timp [15];
char timeHelp [3];
char score[100];
fstream fscor, readConfig;
ofstream writeConfig;

struct Piece  //Ne construim structura de piese pentru a o putea muta si roti.
{
    char path[100];
    double x1,y1,x2,y2;
    int r, insert ;
} pieceVector[4],gamePiece[4],dragPiece;


void GetTable() //Aici se desenază în program tabla pe care jucătorul va pune pisele.
{
    int a,b;
    a=getmaxwidth()/2;  //Aici salvam jumătatea lățimii, respectiv a înălțimii pentru a face codul mai ușor de scris.
    b=getmaxheight()/2;
    strcpy(pieceVector[0].path,"c:\cadran1.gif");
    pieceVector[0].x1=a-310;
    pieceVector[0].y1=b-310;
    pieceVector[0].x2=a-10;
    pieceVector[0].y2=b-10;

    strcpy(pieceVector[1].path,"c:\cadran2.gif");
    pieceVector[1].x1=a+10;
    pieceVector[1].y1=b-310;
    pieceVector[1].x2=a+310;
    pieceVector[1].y2=b-10;


    strcpy(pieceVector[2].path,"c:\cadran3.gif");
    pieceVector[2].x1=a-310;
    pieceVector[2].y1=b+10;
    pieceVector[2].x2=a-10;
    pieceVector[2].y2=b+310;;


    strcpy(pieceVector[3].path,"c:\cadran4.gif");
    pieceVector[3].x1=a+10;
    pieceVector[3].y1=b+10;
    pieceVector[3].x2=a+310;
    pieceVector[3].y2=b+310;
}
void ShowTimer()
{
    settextstyle(10,0,5);
    setcolor(4);
    outtextxy (0, 0, timp);
}
void Timer()
{
    delay(50);
    varTime += 50;
    if (varTime%1000==0)
        seconds++;
    itoa (hours, timeHelp, 10);//face o variablia de tip int in una de tip char in baza specificata
    strcpy (timp, timeHelp);
    strcat (timp, " : ");
    itoa (minutes, timeHelp, 10);
    strcat (timp, timeHelp);
    strcat (timp, " : ");
    itoa (seconds, timeHelp, 10);
    strcat (timp, timeHelp);
    ShowTimer();
}
void DrawTable()
{
    //Aici desenăm toată tabla.

    int  j;

    readimagefile("c:\plaja.gif",0,0,getmaxwidth(),getmaxheight());
    readimagefile("c:\spate.gif", getmaxwidth()/2-330,getmaxheight()/2-330,getmaxwidth()/2+330,getmaxheight()/2+330);
    readimagefile("c:\spate.gif", getmaxwidth()/2+420,getmaxheight()/2-320,getmaxwidth()/2+590,getmaxheight()/2+320);
    if (eng==1)
        readimagefile("c:\score.gif",0,50,100,100);
    else
        readimagefile("c:\scorero.gif",0,50,100,100);

    for (j=0; j<4; j++)
        readimagefile(gamePiece[j].path,gamePiece[j].x1,gamePiece[j].y1,gamePiece[j].x2,gamePiece[j].y2);
    for(i=0; i<4; i++)
        readimagefile(pieceVector[i].path,pieceVector[i].x1,pieceVector[i].y1,pieceVector[i].x2,pieceVector[i].y2);
    if(for_level1==true)
        readimagefile("c:\solutie1.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level2==true)
        readimagefile("c:\solutie2.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level3==true)
        readimagefile("c:\solutie3.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level4==true)
        readimagefile("c:\solutie4.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level5==true)
        readimagefile("c:\solutie5.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level6==true)
        readimagefile("c:\solutie6.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level7==true)
        readimagefile("c:\solutie7.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level8==true)
        readimagefile("c:\solutie8.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level9==true)
        readimagefile("c:\solutie9.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
    if(for_level10==true)
        readimagefile("c:\solutie10.gif", 10,getmaxheight()/2-130,110,getmaxheight()/2+330);
}

void Pieces()
{
    //Aici ne construim structura pieselor.
    strcpy(gamePiece[0].path,"c:\piesa1-nord.gif");
    gamePiece[0].x1=getmaxwidth()/2+430;
    gamePiece[0].y1=getmaxheight()/2-310;
    gamePiece[0].x2=getmaxwidth()/2+580;
    gamePiece[0].y2=getmaxheight()/2-160;
    gamePiece[0].r=0;
    gamePiece[0].insert=1;



    strcpy(gamePiece[1].path,"c:\piesa2-par.gif");
    gamePiece[1].x1=getmaxwidth()/2+430;
    gamePiece[1].y1=getmaxheight()/2-155;
    gamePiece[1].x2=getmaxwidth()/2+580;
    gamePiece[1].y2=getmaxheight()/2-5;
    gamePiece[1].r=0;
    gamePiece[1].insert=1;


    strcpy(gamePiece[2].path,"c:\piesa3-nord.gif");
    gamePiece[2].x1=getmaxwidth()/2+430;
    gamePiece[2].y1=getmaxheight()/2+5;
    gamePiece[2].x2=getmaxwidth()/2+580;
    gamePiece[2].y2=getmaxheight()/2+155;
    gamePiece[2].r=0;
    gamePiece[2].insert=1;


    strcpy(gamePiece[3].path,"c:\piesa4-par.gif");
    gamePiece[3].x1=getmaxwidth()/2+430;
    gamePiece[3].y1=getmaxheight()/2+160;
    gamePiece[3].x2=getmaxwidth()/2+580;
    gamePiece[3].y2=getmaxheight()/2+310;
    gamePiece[3].r=0;
    gamePiece[3].insert=1;
}


void Click()
{
    //In acest if verificam daca jucatorul este intr-un nivel pentru a porni cronometrul.
    if (clickedNivel1==1||clickedNivel2==1||clickedNivel3==1||clickedNivel4==1||clickedNivel5==1||clickedNivel6==1||clickedNivel7==1||clickedNivel8==1||clickedNivel9==1||clickedNivel10==1)
    {
        Timer();
        itoa(scor,score,10);
        outtextxy (115, 50, score);
        if (seconds==60)
        {
            clickedNivel1=0;
            clickedNivel2=0;
            clickedNivel3=0;
            clickedNivel4=0;
            clickedNivel5=0;
            clickedNivel6=0;
            clickedNivel7=0;
            clickedNivel8=0;
            clickedNivel9=0;
            clickedNivel10=0;
            seconds=0;
            varTime=0;
            win=1;
            if (scor>0)
                if (scor<200)
                    scor=0;
                else
                    scor=scor-200;
            itoa(scor,score,10);
            outtextxy (115, 50, score);
            readimagefile("c:\spate.gif", getmaxwidth()/2+420,getmaxheight()/2-320,getmaxwidth()/2+590,getmaxheight()/2+320);
            if (eng==1)
            {
                readimagefile("c:\lost.gif",getmaxwidth()/2-200,10,getmaxwidth()/2+200,70);
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\lostro.gif",getmaxwidth()/2-200,10,getmaxwidth()/2+200,70);
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for(i=0; i<4; i++)
                readimagefile(pieceVector[i].path,pieceVector[i].x1,pieceVector[i].y1,pieceVector[i].x2,pieceVector[i].y2);
            if(for_level1==1)
            {
                readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa3-sud.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level1=0;
            }

            if(for_level2==1)
            {
                readimagefile("c:\piesa1-est.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa2-par.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa3-est.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level2=0;
            }

            if(for_level3==1)
            {
                readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa3-nord.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa1-nord.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level3=0;
            }

            if(for_level4==1)
            {
                readimagefile("c:\piesa3-vest.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa1-vest.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa2-par.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level4=0;
            }

            if(for_level5==1)
            {
                readimagefile("c:\piesa3-nord.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level5=0;
            }

            if(for_level6==1)
            {
                readimagefile("c:\piesa3-nord.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa2-par.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa1-vest.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level6=0;
            }

            if(for_level7==1)
            {
                readimagefile("c:\piesa3-est.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa2-par.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level7=0;
            }

            if(for_level8==1)
            {
                readimagefile("c:\piesa4-par.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa3-est.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level8=0;
            }

            if(for_level9==1)
            {
                readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa3-est.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa1-vest.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level9=0;
            }

            if(for_level10==1)
            {
                readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                readimagefile("c:\piesa1-est.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                readimagefile("c:\piesa3-vest.gif",getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                for_level10=0;
            }
        }
    }
    if(ismouseclick(WM_LBUTTONDOWN)) //Aici testăm dacă butonul stâng al mouse-ului a fost apăsat.
    {
        int x,y;
        int zona_click,a,b;  //În următoarele 4 if-uri verificăm pe ce pisă a făcut jucătorul click pentru a ști ce piesă trebuie pusă pe cadran.
        x=mousex();
        y=mousey();
        a=getmaxwidth()/2;
        b=getmaxheight()/2;
        clearmouseclick(WM_LBUTTONDOWN);
        clearmouseclick(WM_RBUTTONDOWN);
        if(menu==1&&x>=a-150&&x<=a+150&&y>=b-115&&y<=b-65)
            ok++;

        if(clickedPlay==1&&menu==0&&table==false&&((x>=a-320&&x<=a-200&&y>=b-125&&y<=b-5)||(x>=a-190&&x<=a-70&&y>=b-125&&y<=b-5)||(x>=a-160&&x<=a+60&&y>=b-125&&y<=b-5)||(x>=a+70&&x<=a+190&&y>=b-125&&y<=b-5)||(x>=a+200&&x<=a+320&&y>=b-125&&y<=b-5)||(x>=a-320&&x<=a-200&&y>=b+5&&y<=b+125)||(x>=a-190&&x<=a-70&&y>=b+5&&y<=b+125)||(x>=a-60&&x<=a+60&&y>=b+5&&y<=b+125)||(x>=a+70&&x<=a+190&&y>=b+5&&y<=b+125)||(x>=a+200&&x<=a+320&&y>=b+5&&y<=b+125)))
            ok++;
        //In acest if verificam daca jucatorul a facut click pe butonul pentru instructiuni.
        if(x>=a-150&&x<=a+150&&y>=b+5&&y<=b+55&&menu==1&&clickedPlay==0)
        {
            menu=0;
            close=0;
            if(eng==1)
            {
                readimagefile("c:\howTo.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu3.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }
            else
            {
                readimagefile("c:\howToro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu3ro.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }

        }
        //Buton de iesire
        if(close==1&&x>=a-150&&x<=a+150&&y>=b+65&&y<=b+115)
        {
            if(scor>0)
            {
                time_t rawtime;
                struct tm * timeinfo;
                time ( &rawtime );
                timeinfo = localtime ( &rawtime );
                fscor.open("scor.txt", fstream::out | fstream::app);
                fscor<< scor<<"   "<<asctime (timeinfo)<< endl;
                fscor.close();
            }
            exit(0);
        }

        //Aici verificam daca jucatorul a facut click pe butonul pentru setari.
        if(clickedPlay==0&&menu==1&&x>=a-150&&x<=a+150&&y>=b-55&&y<=b-5)
        {
            k++;
            menu=0;
            settings=1;
            readimagefile("c:\meniuSetari.gif",0,0,getmaxwidth(),getmaxheight());
            if(eng==1)
            {
                readimagefile("c:\spate.gif",a-60,10,a+60, 60);
                readimagefile("c:\spate.gif",a-150,250,a+150, 310);
                readimagefile("c:\meniu3.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
                readimagefile("c:\music.gif",a-60,10,a+60, 60);
                readimagefile("c:\on.gif",a-200,80,a-100,150);
                readimagefile("c:\off.gif",a-200,160,a-100,230);
                readimagefile("c:\song1.gif",a+125,80,a+325,150);
                readimagefile("c:\song2.gif",a+125,160,a+325,230);
                readimagefile("c:\lang.gif",a-150,250,a+150, 310);
            }
            else
            {
                readimagefile("c:\spate.gif",a-60,10,a+60, 60);
                readimagefile("c:\spate.gif",a-150,250,a+150, 310);
                readimagefile("c:\meniu3ro.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
                readimagefile("c:\musicro.gif",a-60,10,a+60, 60);
                readimagefile("c:\onro.gif",a-200,80,a-100,150);
                readimagefile("c:\offro.gif",a-200,160,a-100,230);
                readimagefile("c:\song1ro.gif",a+125,80,a+325,150);
                readimagefile("c:\song2ro.gif",a+125,160,a+325,230);
                readimagefile("c:\langro.gif",a-150,250,a+150, 310);
            }
            readimagefile("c:\carlig.gif",a-170,330,a+170, 510);
            readimagefile("c:\carma.gif",a-170,530,a+170, 710);
            close=0;
        }
        //Mai jos avem diferite butoane din pagina de setari (on/off muzica, limba si muzica sselectata)
        if(stop==1&&settings==1&&x>=a-200&&x<=a-130&&y>=80&&y<=150)
        {
            stop=0;
            writeConfig.open("config.txt",  fstream::out | fstream::trunc);//fstream out-> ne lasa sa scriem in fisier  fstream trunc->sterge toate datele scrise in fisier.
            writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
            writeConfig.close();
            if(song1)
                sndPlaySound(TEXT("c:\melodie-joc.wav"), SND_LOOP | SND_ASYNC);
            else
                sndPlaySound(TEXT("c:\melodie-joc2.wav"), SND_LOOP | SND_ASYNC);
        }

        if(settings==1&&x>=a-200&&x<=a-130&&y>=160&&y<=230)
        {
            PlaySound(NULL, 0, 0);
            stop=1;
            writeConfig.open("config.txt",  fstream::out | fstream::trunc);
            writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
            writeConfig.close();
        }
        if(settings==1&&x>=a+125&&x<=a+325&&y>=80&&y<=150)
        {
            if(song1==0)
            {
                song1=1;
                writeConfig.open("config.txt",  fstream::out | fstream::trunc);
                writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
                writeConfig.close();
                sndPlaySound(TEXT("c:\melodie-joc.wav"), SND_LOOP | SND_ASYNC);
            }
        }

        if(settings==1&&x>=a+125&&x<=a+325&&y>=160&&y<=230)
        {
            if(song1==1)
            {
                song1=0;
                writeConfig.open("config.txt",  fstream::out | fstream::trunc);
                writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
                writeConfig.close();
                sndPlaySound(TEXT("c:\melodie-joc2.wav"), SND_LOOP | SND_ASYNC);
            }
        }
        if(clickedPlay==0&&menu==0&&settings==1&&((x>=a-170&&x<=a+170&&y>=530&&y<=710)||(x>=a-170&&x<=a+170&&y>=330&&y<=510)))
            k++;
        if (k>=3&&settings==1&&x>=a-170&&x<=a+170&&y>=530&&y<=710&&eng==0)
        {
            eng=1;
            writeConfig.open("config.txt",  fstream::out | fstream::trunc);
            writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
            writeConfig.close();
            readimagefile("c:\spate.gif",a-60,10,a+60, 60);
            readimagefile("c:\spate.gif",a-150,250,a+150, 310);
            readimagefile("c:\meniu3.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            readimagefile("c:\music.gif",a-60,10,a+60, 60);
            readimagefile("c:\on.gif",a-200,80,a-100,150);
            readimagefile("c:\off.gif",a-200,160,a-100,230);
            readimagefile("c:\song1.gif",a+125,80,a+325,150);
            readimagefile("c:\song2.gif",a+125,160,a+325,230);
            readimagefile("c:\lang.gif",a-150,250,a+150, 310);
        }
        if (k>=3&&settings==1&&x>=a-170&&x<=a+170&&y>=330&&y<=510&&eng==1)
        {
            eng=0;
            writeConfig.open("config.txt",  fstream::out | fstream::trunc);
            writeConfig<<eng<<endl<<stop<<endl<<song1<<endl;
            writeConfig.close();
            readimagefile("c:\spate.gif",a-60,10,a+60, 60);
            readimagefile("c:\spate.gif",a-150,250,a+150, 310);
            readimagefile("c:\meniu3ro.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            readimagefile("c:\musicro.gif",a-60,10,a+60, 60);
            readimagefile("c:\onro.gif",a-200,80,a-100,150);
            readimagefile("c:\offro.gif",a-200,160,a-100,230);
            readimagefile("c:\song1ro.gif",a+125,80,a+325,150);
            readimagefile("c:\song2ro.gif",a+125,160,a+325,230);
            readimagefile("c:\langro.gif",a-150,250,a+150, 310);
        }
        //Aici verificam daca jucatorul a facut click pe butnoul play.
        if(menu==1&&clickedPlay==false&&x>=a-150&&x<=a+150&&y>=b-115&&y<=b-65)
        {
            readimagefile("c:\selectie.gif",0,0,getmaxwidth(),getmaxheight());
            readimagefile("c:\level1.gif",a-320,b-125,a-200,b-5);
            readimagefile("c:\level2.gif",a-190,b-125,a-70,b-5);
            readimagefile("c:\level3.gif",a-60,b-125,a+60,b-5);
            readimagefile("c:\level4.gif",a+70,b-125,a+190,b-5);
            readimagefile("c:\level5.gif",a+200,b-125,a+320,b-5);
            readimagefile("c:\level6.gif",a-320,b+5,a-200,b+125);
            readimagefile("c:\level7.gif",a-190,b+5,a-70,b+125);
            readimagefile("c:\level8.gif",a-60,b+5,a+60,b+125);
            readimagefile("c:\level9.gif",a+70,b+5,a+190,b+125);
            readimagefile("c:\level10.gif",a+200,b+5,a+320,b+125);
            if(eng==1)
            {
                readimagefile("c:\select.gif",a-313,20,a+313,134);
                readimagefile("c:\meniu3.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }
            else
            {
                readimagefile("c:\selectro.gif",a-313,20,a+313,134);
                readimagefile("c:\meniu3ro.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }

            clickedPlay=true;
            menu=0;
            close=0;


        }
        //Aici verificam daca jucatorul a facut click e butonul care ne intoarce la meniu.
        if(x>=getmaxwidth()-310&&x<=getmaxwidth()-10&&y>=getmaxheight()-120&&y<=getmaxheight()-70&&menu==0)
        {
            readimagefile("c:\meniu1.gif",0,0,getmaxwidth(),getmaxheight());
            if(eng==1)
            {
                readimagefile("c:\play.gif",getmaxwidth()/2-150,getmaxheight()/2-115,getmaxwidth()/2+150,getmaxheight()/2-65);
                readimagefile("c:\settings.gif",getmaxwidth()/2-150,getmaxheight()/2-55,getmaxwidth()/2+150,getmaxheight()/2-5);
                readimagefile("c:\how.gif",getmaxwidth()/2-150,getmaxheight()/2+5,getmaxwidth()/2+150,getmaxheight()/2+55);
                readimagefile("c:\lupa.gif",getmaxwidth()/2-150,getmaxheight()/2+65,getmaxwidth()/2+150,getmaxheight()/2+115);
            }
            else
            {
                readimagefile("c:\playro.gif",getmaxwidth()/2-150,getmaxheight()/2-115,getmaxwidth()/2+150,getmaxheight()/2-65);
                readimagefile("c:\settingsro.gif",getmaxwidth()/2-150,getmaxheight()/2-55,getmaxwidth()/2+150,getmaxheight()/2-5);
                readimagefile("c:\howro.gif",getmaxwidth()/2-150,getmaxheight()/2+5,getmaxwidth()/2+150,getmaxheight()/2+55);
                readimagefile("c:\luparo.gif",getmaxwidth()/2-150,getmaxheight()/2+65,getmaxwidth()/2+150,getmaxheight()/2+115);
            }
            menu=1;
            close=1;
            if (clickedPlay==true)
            {
                clickedPlay=false;
                ok--;
            }
            if (settings==1)
            {
                settings=0;
                k=0;
            }
        }
        //Aici reconstruim meniul de selectie a nivelului pentru ca jucatorul sa poate juca in continuare ce nivel doreste
        if(win==true&&x>=getmaxwidth()-310&&x<=getmaxwidth()-10&&y>+getmaxheight()-60&&y<=getmaxheight()-10)
        {
            readimagefile("c:\selectie.gif",0,0,getmaxwidth(),getmaxheight());
            readimagefile("c:\level1.gif",a-320,b-125,a-200,b-5);
            readimagefile("c:\level2.gif",a-190,b-125,a-70,b-5);
            readimagefile("c:\level3.gif",a-60,b-125,a+60,b-5);
            readimagefile("c:\level4.gif",a+70,b-125,a+190,b-5);
            readimagefile("c:\level5.gif",a+200,b-125,a+320,b-5);
            readimagefile("c:\level6.gif",a-320,b+5,a-200,b+125);
            readimagefile("c:\level7.gif",a-190,b+5,a-70,b+125);
            readimagefile("c:\level8.gif",a-60,b+5,a+60,b+125);
            readimagefile("c:\level9.gif",a+70,b+5,a+190,b+125);
            readimagefile("c:\level10.gif",a+200,b+5,a+320,b+125);
            if(eng==1)
            {
                readimagefile("c:\select.gif",a-313,20,a+313,134);
                readimagefile("c:\meniu3.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }
            else
            {
                readimagefile("c:\selectro.gif",a-313,20,a+313,134);
                readimagefile("c:\meniu3ro.gif",getmaxwidth()-310,getmaxheight()-120,getmaxwidth()-10,getmaxheight()-70);
            }
            menu=0;
            clickedPlay=true;
            win=false;
            table=false;
            Pieces();
            area1=0;
            area2=0;
            area3=0;
            area4=0;
            ok=1;
            LMBdial4=0;
            LMBdial1=0;
            LMBdial2=0;
            LMBdial3=0;
        }


        //In urmatoarele if-uri verificam ce nivel a selectat jucatorul
        if(table==false&&x>=a-320&&x<=a-200&&y>=b-125&&y<=b-5&&ok==2&&menu==0)
        {
            clickedNivel1=true;
            table=true;
            for_level1=true;
            DrawTable();
            menu=1;
        }
        if(table==false&&x>=a-190&&x<=a-70&&y>=b-125&&y<=b-5&&ok==2&&menu==0)
        {
            clickedNivel2=true;
            table=true;
            for_level2=true;
            DrawTable();
            menu=1;
        }

        if(table==false&&x>=a-60&&x<=a+60&&y>=b-125&&y<=b-5&&ok==2&&menu==0)
        {
            clickedNivel3=true;
            table=true;
            for_level3=true;
            DrawTable();
            menu=1;
        }
        if(table==false&&x>=a+70&&x<=a+190&&y>=b-125&&y<=b-5&&ok==2&&menu==0)
        {
            clickedNivel4=true;
            table=true;
            for_level4=true;
            DrawTable();
            menu=1;
        }
        if(table==false&&x>=a+200&&x<=a+320&&y>=b-125&&y<=b-5&&ok==2&&menu==0)
        {
            clickedNivel5=true;
            table=true;
            for_level5=true;
            DrawTable();
            menu=1;
        }
        if(table==false&&x>=a-320&&x<=a-200&&y>=b+5&&y<=b+125&&ok==2&&menu==0)
        {
            clickedNivel6=true;
            table=true;
            for_level6=true;
            DrawTable();
            menu=1;

        }
        if(table==false&&x>=a-190&&x<=a-70&&y>=b+5&&y<=b+125&&ok==2&&menu==0)
        {
            clickedNivel7=true;
            table=true;
            for_level7=true;
            DrawTable();
            menu=1;

        }
        if(table==false&&x>=a-60&&x<=a+60&&y>=b+5&&y<=b+125&&ok==2&&menu==0)
        {
            clickedNivel8=true;
            table=true;
            for_level8=true;
            DrawTable();
            menu=1;

        }
        if(table==false&&x>=a+70&&x<=a+190&&y>=b+5&&y<=b+125&&ok==2&&menu==0)
        {
            clickedNivel9=true;
            table=true;
            for_level9=true;
            DrawTable();
            menu=1;

        }
        if(table==false&&x>=a+200&&x<=a+320&&y>=b+5&&y<=b+125&&ok==2&&menu==0)
        {
            clickedNivel10=true;
            table=true;
            for_level10=true;
            DrawTable();
            menu=1;

        }




        //In urmatoarele 4 if-uri se retine piesa din dreapta pe care jucatorul a facut click si respectiv rotatia acesteia pentru a o putea pune pe masa principala.
        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2-310&&y<=getmaxheight()/2-160&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            dragPiece.x1=getmaxwidth()/2+430;
            dragPiece.x2=getmaxwidth()/2+580;
            dragPiece.y1=getmaxheight()/2-310;
            dragPiece.y2=getmaxheight()/2-160;
            zona_click=0;

            switch(gamePiece[0].r)
            {
            case 0:
                strcpy(dragPiece.path,"c:\piesa1-nord.gif");
                t=1;
                break;
            case 1:
                strcpy(dragPiece.path,"c:\piesa1-est.gif");
                t=1;
                break;
            case 2:
                strcpy(dragPiece.path,"c:\piesa1-sud.gif");
                t=1;
                break;
            case 3:
                strcpy(dragPiece.path,"c:\piesa1-vest.gif");
                t=1;
                break;
            }

        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2-155&&y<=getmaxheight()/2-5&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            dragPiece.x1=getmaxwidth()/2+430;
            dragPiece.x2=getmaxwidth()/2+580;
            dragPiece.y1=getmaxheight()/2-155;
            dragPiece.y2=getmaxheight()/2-5;
            zona_click=1;

            switch(gamePiece[1].r)
            {
            case 0:
                strcpy(dragPiece.path,"c:\piesa2-par.gif");
                t=1;
                break;
            case 1:
                strcpy(dragPiece.path,"c:\piesa2-impar.gif");
                t=1;
                break;
            }

        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2+5&&y<=getmaxheight()/2+155&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            dragPiece.x1=getmaxwidth()/2+430;
            dragPiece.x2=getmaxwidth()/2+580;
            dragPiece.y1=getmaxheight()/2+5;
            dragPiece.y2=getmaxheight()/2+155;
            zona_click=2;

            switch(gamePiece[2].r)
            {
            case 0:
                strcpy(dragPiece.path,"c:\piesa3-nord.gif");
                t=1;
                break;
            case 1:
                strcpy(dragPiece.path,"c:\piesa3-est.gif");
                t=1;
                break;
            case 2:
                strcpy(dragPiece.path,"c:\piesa3-sud.gif");
                t=1;
                break;
            case 3:
                strcpy(dragPiece.path,"c:\piesa3-vest.gif");
                t=1;
                break;
            }

        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2+160&&y<=getmaxheight()/2+310&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            dragPiece.x1=getmaxwidth()/2+430;
            dragPiece.x2=getmaxwidth()/2+580;
            dragPiece.y1=getmaxheight()/2+160;
            dragPiece.y2=getmaxheight()/2+310;
            zona_click=3;

            switch(gamePiece[3].r)
            {
            case 0:
                strcpy(dragPiece.path,"c:\piesa4-par.gif");
                t=1;
                break;
            case 1:
                strcpy(dragPiece.path,"c:\piesa4-impar.gif");
                t=1;
                break;
            }

        }



        //În următoarele 4 if-uri verificăm pe ce cadran de pe tablă trebuie desenată piesa selectată și o desenăm.
        if(x>=getmaxwidth()/2-310&&x<=getmaxwidth()/2-10&&y>=getmaxheight()/2-310&&y<=getmaxheight()/2-10&&t==1&&area1==0&&gamePiece[zona_click].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            gamePiece[zona_click].insert=0;
            readimagefile(dragPiece.path,getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile("c:\coperta.gif",dragPiece.x1,dragPiece.y1,dragPiece.x2,dragPiece.y2);
            strcpy(dial1,dragPiece.path);
            area1=-1;
            t=0;

        }

        if(x>=getmaxwidth()/2+10&&x<=getmaxwidth()/2+310&&y>=getmaxheight()/2-310&&y<=getmaxheight()/2-10&&t==1&&area2==0&&gamePiece[zona_click].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            gamePiece[zona_click].insert=0;
            readimagefile(dragPiece.path,getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile("c:\coperta.gif",dragPiece.x1,dragPiece.y1,dragPiece.x2,dragPiece.y2);
            strcpy(dial2,dragPiece.path);
            area2=-1;
            t=0;

        }

        if(x>=getmaxwidth()/2-310&&x<=getmaxwidth()/2-10&&y>=getmaxheight()/2+10&&y<=getmaxheight()/2+310&&t==1&&area3==0&&gamePiece[zona_click].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            gamePiece[zona_click].insert=0;
            readimagefile(dragPiece.path,getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            readimagefile("c:\coperta.gif",dragPiece.x1,dragPiece.y1,dragPiece.x2,dragPiece.y2);
            strcpy(dial3,dragPiece.path);
            area3=-1;
            t=0;

        }

        if(x>=getmaxwidth()/2+10&&x<=getmaxwidth()/2+310&&y>=getmaxheight()/2+10&&y<=getmaxheight()/2+310&&t==1&&area4==0&&gamePiece[zona_click].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            gamePiece[zona_click].insert=0;
            readimagefile(dragPiece.path,getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            readimagefile("c:\coperta.gif",dragPiece.x1,dragPiece.y1,dragPiece.x2,dragPiece.y2);
            strcpy(dial4,dragPiece.path);
            area4=-1;
            t=0;

        }

        //In urmatoarele 10 if-uri se efectueaza interschimbarea a 2 piese care au fost deja puse pe masa principala
        if(x>=a-310&&x<=a-10&&y>=b-310&&y<=b-10&&(strcmp(dial1,"sirulegol")>0||strcmp(dial1,"sirulegol")<0)&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            LMBdial1++;

        }
        if(x>=a+10&&x<=a+310&&y>=b-310&&y<=b-10&&(strcmp(dial2,"sirulegol")>0||strcmp(dial2,"sirulegol")<0)&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            LMBdial2++;
        }

        if(x>=a-310&&x<=a-10&&y>=b+10&&y<=b+310&&(strcmp(dial3,"sirulegol")>0||strcmp(dial3,"sirulegol")<0)&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            LMBdial3++;
        }

        if(x>=a+10&&x<=a+310&&y>=b+10&&y<=b+310&&(strcmp(dial4,"sirulegol")>0||strcmp(dial4,"sirulegol")<0)&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            LMBdial4++;
        }
        if(LMBdial1>=2&&LMBdial2>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile("c:\cadran2.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile(dial2, getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile(dial1, getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            strcpy(dialCopy,dial1);
            strcpy(dial1,dial2);
            strcpy(dial2,dialCopy);
            LMBdial2=1;
            LMBdial1=1;
        }



        if(LMBdial1>=2&&LMBdial3>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            readimagefile(dial3, getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile(dial1, getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            strcpy(dialCopy,dial1);
            strcpy(dial1,dial3);
            strcpy(dial3,dialCopy);
            LMBdial3=1;
            LMBdial1=1;
        }



        if(LMBdial1>=2&&LMBdial4>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            readimagefile(dial4, getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
            readimagefile(dial1, getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            strcpy(dialCopy,dial1);
            strcpy(dial1,dial4);
            strcpy(dial4,dialCopy);
            LMBdial4=1;
            LMBdial1=1;
        }



        if(LMBdial2>=2&&LMBdial3>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran2.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            readimagefile(dial3, getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile(dial2, getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            strcpy(dialCopy,dial2);
            strcpy(dial2,dial3);
            strcpy(dial3,dialCopy);
            LMBdial3=1;
            LMBdial2=1;
        }


        if(LMBdial2>=2&&LMBdial4>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran2.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            readimagefile(dial4, getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
            readimagefile(dial2, getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            strcpy(dialCopy,dial2);
            strcpy(dial2,dial4);
            strcpy(dial4,dialCopy);
            LMBdial4=1;
            LMBdial2=1;
        }


        if(LMBdial3>=2&&LMBdial4>=2&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            readimagefile(dial4, getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
            readimagefile(dial3, getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
            strcpy(dialCopy,dial3);
            strcpy(dial3,dial4);
            strcpy(dial4,dialCopy);
            LMBdial4=1;
            LMBdial3=1;
        }
        clearmouseclick(WM_LBUTTONDOWN);

    }

    if(ismouseclick(WM_RBUTTONDOWN)) //Verificăm dacă butonul drept al mouse-ului a fost apăsat.
    {
        int x, y;
        x=mousex();
        y=mousey();
        //În următoarele 4 if-uri verificăm dacă jucătorul vrea să rotească piesele de pe masa din dreapta.
        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2-310&&y<=getmaxheight()/2-160&&gamePiece[0].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\coperta.gif", getmaxwidth()/2+430,getmaxheight()/2-310,getmaxwidth()/2+580,getmaxheight()/2-160);
            gamePiece[0].r=(gamePiece[0].r+1)%4;
            switch(gamePiece[0].r)
            {
            case 0:
                readimagefile("c:\piesa1-nord.gif", getmaxwidth()/2+430,getmaxheight()/2-310,getmaxwidth()/2+580,getmaxheight()/2-160);
                break;
            case 1:
                readimagefile("c:\piesa1-est.gif", getmaxwidth()/2+430,getmaxheight()/2-310,getmaxwidth()/2+580,getmaxheight()/2-160);
                break;
            case 2:
                readimagefile("c:\piesa1-sud.gif", getmaxwidth()/2+430,getmaxheight()/2-310,getmaxwidth()/2+580,getmaxheight()/2-160);
                break;
            case 3:
                readimagefile("c:\piesa1-vest.gif", getmaxwidth()/2+430,getmaxheight()/2-310,getmaxwidth()/2+580,getmaxheight()/2-160);
                break;
            }

        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2-155&&y<=getmaxheight()/2-5&&gamePiece[1].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            readimagefile("c:\coperta.gif", getmaxwidth()/2+430,getmaxheight()/2-155,getmaxwidth()/2+580,getmaxheight()/2-5);
            gamePiece[1].r=(gamePiece[1].r+1)%2;
            switch(gamePiece[1].r)
            {
            case 0:
                readimagefile("c:\piesa2-par.gif", getmaxwidth()/2+430,getmaxheight()/2-155,getmaxwidth()/2+580,getmaxheight()/2-5);
                break;
            case 1:
                readimagefile("c:\piesa2-impar.gif", getmaxwidth()/2+430,getmaxheight()/2-155,getmaxwidth()/2+580,getmaxheight()/2-5);
                break;
            }
        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2+5&&y<=getmaxheight()/2+155&&gamePiece[2].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            readimagefile("c:\coperta.gif", getmaxwidth()/2+430,getmaxheight()/2+5,getmaxwidth()/2+580,getmaxheight()/2+155);
            gamePiece[2].r=(gamePiece[2].r+1)%4;
            switch(gamePiece[2].r)
            {
            case 0:
                readimagefile("c:\piesa3-nord.gif", getmaxwidth()/2+430,getmaxheight()/2+5,getmaxwidth()/2+580,getmaxheight()/2+155);
                break;
            case 1:
                readimagefile("c:\piesa3-est.gif", getmaxwidth()/2+430,getmaxheight()/2+5,getmaxwidth()/2+580,getmaxheight()/2+155);
                break;
            case 2:
                readimagefile("c:\piesa3-sud.gif", getmaxwidth()/2+430,getmaxheight()/2+5,getmaxwidth()/2+580,getmaxheight()/2+155);
                break;
            case 3:
                readimagefile("c:\piesa3-vest.gif", getmaxwidth()/2+430,getmaxheight()/2+5,getmaxwidth()/2+580,getmaxheight()/2+155);
                break;
            }
        }

        if (x>=getmaxwidth()/2+430&&x<=getmaxwidth()/2+580&&y>=getmaxheight()/2+160&&y<=getmaxheight()/2+310&&gamePiece[3].insert==1&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {
            readimagefile("c:\coperta.gif", getmaxwidth()/2+430,getmaxheight()/2+160,getmaxwidth()/2+580,getmaxheight()/2+310);
            gamePiece[3].r=(gamePiece[3].r+1)%2;
            switch(gamePiece[3].r)
            {
            case 0:
                readimagefile("c:\piesa4-par.gif", getmaxwidth()/2+430,getmaxheight()/2+160,getmaxwidth()/2+580,getmaxheight()/2+310);
                break;
            case 1:
                readimagefile("c:\piesa4-impar.gif", getmaxwidth()/2+430,getmaxheight()/2+160,getmaxwidth()/2+580,getmaxheight()/2+310);
                break;
            }
        }
        int a=getmaxwidth()/2;
        int b=getmaxheight()/2;
        //In urmatoarele 4 if-uri verificam daca jucatorul vrea sa roteasca o piesa care a fost pusa pe tabla principala
        if(x>=a-310&&x<=a-10&&y>=b-310&&y<=b-10&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            if(strncmp(dial1,gamePiece[0].path,8)==0)

            {
                readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                gamePiece[0].r=(gamePiece[0].r+1)%4;
                switch(gamePiece[0].r)
                {
                case 0:
                    readimagefile("c:\piesa1-nord.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa1-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa1-est.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa1-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa1-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa1-vest.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa1-vest.gif");
                    break;
                }
            }

            if(strncmp(dial1,gamePiece[1].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                gamePiece[1].r=(gamePiece[1].r+1)%2;
                switch(gamePiece[1].r)
                {
                case 0:
                    readimagefile("c:\piesa2-par.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa1-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa2-impar.gif");
                    break;

                }
            }

            if(strncmp(dial1,gamePiece[2].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                gamePiece[2].r=(gamePiece[2].r+1)%4;
                switch(gamePiece[2].r)
                {
                case 0:
                    readimagefile("c:\piesa3-nord.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa3-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa3-est.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa3-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa3-sud.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa3-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa3-vest.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa3-vest.gif");
                    break;
                }
            }

            if(strncmp(dial1,gamePiece[3].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran1.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                gamePiece[3].r=(gamePiece[3].r+1)%2;
                switch(gamePiece[3].r)
                {
                case 0:
                    readimagefile("c:\piesa4-par.gif", getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa4-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2-310,getmaxheight()/2-310,getmaxwidth()/2-10,getmaxheight()/2-10);
                    strcpy(dial1,"c:\piesa4-impar.gif");
                    break;

                }
            }
        }

        if(x>=a+10&&x<=a+310&&y>=b-310&&y<=b-10&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            if(strncmp(dial2,gamePiece[0].path,8)==0)

            {
                readimagefile("c:\cadran2.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                gamePiece[0].r=(gamePiece[0].r+1)%4;
                switch(gamePiece[0].r)
                {
                case 0:
                    readimagefile("c:\piesa1-nord.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa1-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa1-est.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa1-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa1-sud.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa1-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa1-vest.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa1-vest.gif");
                    break;
                }
            }

            if(strncmp(dial2,gamePiece[1].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran2.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                gamePiece[1].r=(gamePiece[1].r+1)%2;
                switch(gamePiece[1].r)
                {
                case 0:
                    readimagefile("c:\piesa2-par.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa2-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa2-impar.gif");
                    break;

                }
            }

            if(strncmp(dial2,gamePiece[2].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran2.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                gamePiece[2].r=(gamePiece[2].r+1)%4;
                switch(gamePiece[2].r)
                {
                case 0:
                    readimagefile("c:\piesa3-nord.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa3-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa3-est.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa3-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa3-sud.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa3-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa3-vest.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa3-vest.gif");
                    break;
                }
            }

            if(strncmp(dial2,gamePiece[3].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran2.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                gamePiece[3].r=(gamePiece[3].r+1)%2;
                switch(gamePiece[3].r)
                {
                case 0:
                    readimagefile("c:\piesa4-par.gif", getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa4-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2+10,getmaxheight()/2-310,getmaxwidth()/2+310,getmaxheight()/2-10);
                    strcpy(dial2,"c:\piesa4-impar.gif");
                    break;

                }
            }
        }

        if(x>=a-310&&x<=a-10&&y>=b+10&&y<=b+310&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            if(strncmp(dial3,gamePiece[0].path,8)==0)

            {
                readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                gamePiece[0].r=(gamePiece[0].r+1)%4;
                switch(gamePiece[0].r)
                {
                case 0:
                    readimagefile("c:\piesa1-nord.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa1-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa1-est.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa1-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa1-sud.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa1-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa1-vest.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa1-vest.gif");
                    break;
                }
            }

            if(strncmp(dial3,gamePiece[1].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                gamePiece[1].r=(gamePiece[1].r+1)%2;
                switch(gamePiece[1].r)
                {
                case 0:
                    readimagefile("c:\piesa2-par.gif",  getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa2-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa2-impar.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa2-impar.gif");
                    break;

                }
            }

            if(strncmp(dial3,gamePiece[2].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                gamePiece[2].r=(gamePiece[2].r+1)%4;
                switch(gamePiece[2].r)
                {
                case 0:
                    readimagefile("c:\piesa3-nord.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa3-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa3-est.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa3-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa3-sud.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa3-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa3-vest.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa3-vest.gif");
                    break;
                }
            }

            if(strncmp(dial3,gamePiece[3].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran3.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                gamePiece[3].r=(gamePiece[3].r+1)%2;
                switch(gamePiece[3].r)
                {
                case 0:
                    readimagefile("c:\piesa4-par.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa4-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa4-impar.gif", getmaxwidth()/2-310,getmaxheight()/2+10,getmaxwidth()/2-10,getmaxheight()/2+310);
                    strcpy(dial3,"c:\piesa4-impar.gif");
                    break;

                }
            }
        }

        if(x>=a+10&&x<=a+310&&y>=b+10&&y<=b+310&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))
        {

            if(strncmp(dial4,gamePiece[0].path,8)==0)

            {
                readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                gamePiece[0].r=(gamePiece[0].r+1)%4;
                switch(gamePiece[0].r)
                {
                case 0:
                    readimagefile("c:\piesa1-nord.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa1-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa1-est.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa1-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa1-sud.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa1-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa1-vest.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa1-vest.gif");
                    break;
                }
            }

            if(strncmp(dial4,gamePiece[1].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                gamePiece[1].r=(gamePiece[1].r+1)%2;
                switch(gamePiece[1].r)
                {
                case 0:
                    readimagefile("c:\piesa2-par.gif",  getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa2-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa2-impar.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa2-impar.gif");
                    break;

                }
            }

            if(strncmp(dial4,gamePiece[2].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                gamePiece[2].r=(gamePiece[2].r+1)%4;
                switch(gamePiece[2].r)
                {
                case 0:
                    readimagefile("c:\piesa3-nord.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa3-nord.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa3-est.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa3-est.gif");
                    break;
                case 2:
                    readimagefile("c:\piesa3-sud.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa3-sud.gif");
                    break;
                case 3:
                    readimagefile("c:\piesa3-vest.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa3-vest.gif");
                    break;
                }
            }

            if(strncmp(dial4,gamePiece[3].path,8)==0&&clickedPlay==true&&(clickedNivel1==true||clickedNivel2==true||clickedNivel3==true||clickedNivel4==true||clickedNivel5==true||clickedNivel6==true||clickedNivel7==true||clickedNivel8==true||clickedNivel9==true||clickedNivel10==true))

            {
                readimagefile("c:\cadran4.gif", getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                gamePiece[3].r=(gamePiece[3].r+1)%2;
                switch(gamePiece[3].r)
                {
                case 0:
                    readimagefile("c:\piesa4-par.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa4-par.gif");
                    break;
                case 1:
                    readimagefile("c:\piesa4-impar.gif",getmaxwidth()/2+10,getmaxheight()/2+10,getmaxwidth()/2+310,getmaxheight()/2+310);
                    strcpy(dial4,"c:\piesa4-impar.gif");
                    break;

                }
            }
        }

        clearmouseclick(WM_RBUTTONDOWN);
    }
    //In urmatoarele 10 if-uri verificam daca jucatorul a castigat
    if(for_level1==true)
    {
        if(strcmp(dial1,"c:piesa1-sud.gif")==0&&strcmp(dial2,"c:piesa4-impar.gif")==0&&strcmp(dial3,"c:piesa2-impar.gif")==0&&strcmp(dial4,"c:piesa3-sud.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level1=false;
            clickedNivel1=false;
            win=true;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");

        }
    }



    if(for_level2==true)
    {
        if(strcmp(dial1,"c:piesa1-est.gif")==0&&strcmp(dial2,"c:piesa4-impar.gif")==0&&strcmp(dial3,"c:piesa2-par.gif")==0&&strcmp(dial4,"c:piesa3-est.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level2=false;
            win=true;
            clickedNivel2=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }

    if(for_level3==true)
    {
        if(strcmp(dial1,"c:piesa4-impar.gif")==0&&strcmp(dial2,"c:piesa2-impar.gif")==0&&strcmp(dial3,"c:piesa3-nord.gif")==0&&strcmp(dial4,"c:piesa1-nord.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level3=false;
            win=true;
            clickedNivel3=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");


        }
    }
    if(for_level4==true)
    {
        if(strcmp(dial1,"c:piesa3-vest.gif")==0&&strcmp(dial2,"c:piesa1-vest.gif")==0&&strcmp(dial3,"c:piesa4-par.gif")==0&&strcmp(dial4,"c:piesa2-par.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level4=false;
            win=true;
            clickedNivel4=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");


        }
    }

    if(for_level5==true)
    {
        if(strcmp(dial1,"c:piesa3-nord.gif")==0&&strcmp(dial2,"c:piesa4-par.gif")==0&&strcmp(dial3,"c:piesa2-impar.gif")==0&&strcmp(dial4,"c:piesa1-sud.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level5=false;
            win=true;
            clickedNivel5=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }

    if(for_level6==true)
    {
        if(strcmp(dial1,"c:piesa3-nord.gif")==0&&strcmp(dial2,"c:piesa4-par.gif")==0&&strcmp(dial3,"c:piesa2-par.gif")==0&&strcmp(dial4,"c:piesa1-vest.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level6=false;
            win=true;
            clickedNivel6=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }
    if(for_level7==true)
    {
        if(strcmp(dial1,"c:piesa3-est.gif")==0&&strcmp(dial2,"c:piesa2-par.gif")==0&&strcmp(dial3,"c:piesa4-par.gif")==0&&strcmp(dial4,"c:piesa1-nord.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level7=false;
            win=true;
            clickedNivel7=false;
            varTime=0;
            seconds=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }

    if(for_level8==true)
    {
        if(strcmp(dial1,"c:piesa4-par.gif")==0&&strcmp(dial2,"c:piesa2-impar.gif")==0&&strcmp(dial3,"c:piesa3-est.gif")==0&&strcmp(dial4,"c:piesa1-sud.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level8=false;
            win=true;
            clickedNivel8=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }
    if(for_level9==true)
    {
        if(strcmp(dial1,"c:piesa4-impar.gif")==0&&strcmp(dial2,"c:piesa3-est.gif")==0&&strcmp(dial3,"c:piesa1-vest.gif")==0&&strcmp(dial4,"c:piesa2-impar.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level9=false;
            win=true;
            clickedNivel9=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }
    if(for_level10==true)
    {
        if(strcmp(dial1,"c:piesa2-impar.gif")==0&&strcmp(dial2,"c:piesa1-est.gif")==0&&strcmp(dial3,"c:piesa3-vest.gif")==0&&strcmp(dial4,"c:piesa4-impar.gif")==0)
        {
            if(seconds<=20)
                scor=scor+400;
            else if(seconds<=40)
                scor=scor+200;
            else if (seconds<60)
                scor=scor+100;
            if(eng==1)
            {
                readimagefile("c:\win.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            else
            {
                readimagefile("c:\winro.gif",0,0,getmaxwidth(),getmaxheight());
                readimagefile("c:\meniu2ro.gif",getmaxwidth()-310,getmaxheight()-60,getmaxwidth()-10,getmaxheight()-10);
            }
            for_level10=false;
            win=true;
            clickedNivel10=false;
            seconds=0;
            varTime=0;
            strcpy(dial1,"sirulegol");
            strcpy(dial2,"sirulegol");
            strcpy(dial3,"sirulegol");
            strcpy(dial4,"sirulegol");
        }
    }

}


int main()
{

    readConfig.open("config.txt", fstream::in | fstream::out | fstream::app);//Aici am declarat fisierul in care salvam datele de tip bool ale setarilor.
    readConfig >> eng>>stop>>song1;
    readConfig.close();
    initwindow(getmaxwidth(),getmaxheight(),"Pirates Hide And Seek");
    readimagefile("c:\meniu1.gif",0,0,getmaxwidth(),getmaxheight());
    if(stop==0)
    {
        if(song1==1)
            sndPlaySound(TEXT("c:\melodie-joc.wav"), SND_LOOP | SND_ASYNC);
        else
            sndPlaySound(TEXT("c:\melodie-joc2.wav"), SND_LOOP | SND_ASYNC);
    }
    strcpy(dial1,"sirulegol");
    strcpy(dial2,"sirulegol");
    strcpy(dial3,"sirulegol");
    strcpy(dial4,"sirulegol");
    GetTable();
    Pieces();

    if (eng==1)
    {
        readimagefile("c:\play.gif",getmaxwidth()/2-150,getmaxheight()/2-115,getmaxwidth()/2+150,getmaxheight()/2-65);
        readimagefile("c:\settings.gif",getmaxwidth()/2-150,getmaxheight()/2-55,getmaxwidth()/2+150,getmaxheight()/2-5);
        readimagefile("c:\how.gif",getmaxwidth()/2-150,getmaxheight()/2+5,getmaxwidth()/2+150,getmaxheight()/2+55);
        readimagefile("c:\lupa.gif",getmaxwidth()/2-150,getmaxheight()/2+65,getmaxwidth()/2+150,getmaxheight()/2+115);
    }
    else
    {
        readimagefile("c:\playro.gif",getmaxwidth()/2-150,getmaxheight()/2-115,getmaxwidth()/2+150,getmaxheight()/2-65);
        readimagefile("c:\settingsro.gif",getmaxwidth()/2-150,getmaxheight()/2-55,getmaxwidth()/2+150,getmaxheight()/2-5);
        readimagefile("c:\howro.gif",getmaxwidth()/2-150,getmaxheight()/2+5,getmaxwidth()/2+150,getmaxheight()/2+55);
        readimagefile("c:\luparo.gif",getmaxwidth()/2-150,getmaxheight()/2+65,getmaxwidth()/2+150,getmaxheight()/2+115);
    }
    while(true)
    {
        Click();

    }
    getch();
    return 0;
}
