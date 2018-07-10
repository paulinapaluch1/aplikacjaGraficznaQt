#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->definicja->setVisible(0);
    ui->label->setVisible(0);
    ui->wzrost->setVisible(0);
    ui->label_2->setVisible(0);
    ui->masa->setVisible(0);
    ui->oblicz->setVisible(0);
    ui->label_3->setVisible(0);
    ui->wynik->setVisible(0);
    ui->c->setVisible(0);
    ui->opis->setVisible(0);
    ui->label_4->setVisible(0);
    ui->e->setVisible(0);
    ui->opisE->setVisible(0);
    ui->ok->setVisible(0);
    ui->label_5->setVisible(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCo_to_jest_triggered()
{

    ui->definicja->setVisible(1);
    ui->label->setVisible(0);
    ui->wzrost->setVisible(0);
    ui->label_2->setVisible(0);
    ui->masa->setVisible(0);
    ui->oblicz->setVisible(0);
    ui->c->setVisible(0);
    ui->opis->setVisible(0);
    ui->label_4->setVisible(0);
    ui->e->setVisible(0);
    ui->opisE->setVisible(0);
    ui->ok->setVisible(0);
    ui->label_5->setVisible(0);



    ui->definicja->setText("BMI(z angielskego Body Mass Index to wspolczynnik, ktory "
                           "pozwala obliczyc,czy proporcje naszej masy ciala w stosunku do wzrostu "
                           "sa wlasciwe. Sprawdz, czy Twoja masa ciala miesci sie w granicach prawidlowych, "
                           "jest za niska lub zbyt wysoka. Przekonaj sie, czy nie grozi Ci niedozywienie czy tez nadwaga.");
}

void MainWindow::on_oblicz_clicked()
{

     if(ui->wzrost->cursorPosition()<1||ui->masa->cursorPosition()<1) QMessageBox::information(this,"Error","Najpierw podaj dane!");
else
 {
    ui->label_3->setVisible(1);
    ui->wynik->setVisible(1);
    ui->wynik->setText(QString::number(ui->masa->text().toFloat()/(pow(ui->wzrost->text().toFloat(),2))));
    ui->opis->setVisible(1);
 }
}

void MainWindow::on_actionOblicz_triggered()
{
   ui->definicja->setVisible(0);
    ui->label->setVisible(1);
    ui->wzrost->setVisible(1);
    ui->label_2->setVisible(1);
    ui->masa->setVisible(1);
    ui->oblicz->setVisible(1);
    ui->label_4->setVisible(0);
    ui->e->setVisible(0);
    ui->opisE->setVisible(0);
    ui->ok->setVisible(0);
    ui->label_5->setVisible(0);
}



void MainWindow::on_opis_clicked()
{
    if(ui->opis->property("checked")==1)
    {
        ui->c->setVisible(1);
        float rob=ui->wynik->text().toFloat();
        if(rob<16){ ui->c->setText("wyglodzenie"); ui->c->setStyleSheet("background-color:red");}
        else if(rob<17) ui->c->setText("wychudzenie");
        else if(rob<18.5) ui->c->setText("niedowaga");
        else if(rob<25) { ui->c->setText("waga prawidlowa"); ui->c->setStyleSheet("background-color:green");}
        else if(rob<30) ui->c->setText("nadwaga");
        else if(rob<35) ui->c->setText("I stopien otylosci");
        else if(rob<40) ui->c->setText("II stopien otylosci");
        else if(rob>40){ ui->c->setText("III stopien otylosci(otyłosc skrajna)");}

    }
    else
    {
        ui->c->clear();
        ui->c->setVisible(0);
    }

}





void MainWindow::on_actionSprawd_E_triggered()
{
    ui->definicja->setVisible(0);
    ui->label->setVisible(0);
    ui->wzrost->setVisible(0);
    ui->label_2->setVisible(0);
    ui->masa->setVisible(0);
    ui->oblicz->setVisible(0);
    ui->label_3->setVisible(0);
    ui->wynik->setVisible(0);
    ui->c->setVisible(0);
    ui->opis->setVisible(0);
    ui->label_4->setVisible(1);
    ui->e->setVisible(1);
    ui->opisE->setVisible(1);
    ui->ok->setVisible(1);
    ui->label_5->setVisible(1);


}

void MainWindow::on_ok_clicked()
{
    if(ui->e->cursorPosition()<1)  QMessageBox::information(this,"Error","Najpierw podaj numer E!");
    int rob=ui->e->text().toFloat();
    if(rob==102) ui->opisE->setText("tartrazyna - barwnik, wywoluje reakcje alergiczne,depresje,ADHD u dzieci");
    else if(rob==104) ui->opisE->setText("zolcien chinolowa - barwnik, powoduje reakcje alergiczne");
    else if(rob==123) ui->opisE->setText("amarant - barwnik, moze powowodowac niezyt nosa,nieplodnosc,choroby nerek i watroby");
    else if(rob==124) ui->opisE->setText("czerwien koszelinowa - ma dzialania rakotworcze");
    else if(rob==127) ui->opisE->setText("erytrozyna - barwnik - powoduje dekoncentracje");
    else if(rob==210||rob==211||rob==212||rob==213) ui->opisE->setText("kwas benzoesowy - konserwant - moze powodowac astme, pokrzywke, podraznia oczy i skore,toksyczny dla ukladu nerwowoego");
    else if(rob==220||rob==221||rob==222||rob==223||rob==224||rob==225||rob==226||rob==227||rob==228) ui->opisE->setText("siarczan - konserwant - niszczy witamine B12, powoduje reakcje alergiczne, nudnosci, bole glowy, zakloca prac jelit");
    else if(rob==249||rob==250) ui->opisE->setText("azotyna - konserwant o dzialaniu rakotworczym");
    else if(rob==100) ui->opisE->setText("kurkumina - skladnik nieszkodliwy");
    else if(rob==300) ui->opisE->setText("kwas askorbinowy - wit.C - skladnik nieszkodliwy");
    else if(rob==412) ui->opisE->setText("guma guar - ma dzialanie przeczyszczajace,hamuje apetyt");
    else if(rob==101) ui->opisE->setText("ryboflawina - wit. B2 - skladnik nieszkodliwy");
    else if(rob==306) ui->opisE->setText("witamina E - skladnik nieszkodliwy");
    else if(rob==440) ui->opisE->setText("pektyna - skladnik nieszkodliwy");
    else if(rob==160||rob==161||rob==163) ui->opisE->setText("karoten - skladnik nieszkodliwy");
    else if(rob==410) ui->opisE->setText("maczka chleba swietojanskiego - skladnik nieszkodliwy");
    else if(rob==120) ui->opisE->setText("koszelina - powoduje reakcje alergiczne");
    else if(rob==385) ui->opisE->setText("sol wapniowo-disodowa - zaburzenia w przemianie materii ");
    else if(rob==110) ui->opisE->setText("żółcień pomaranczowa - barwnik, powoduje reakcje alergiczne");
    else if(rob==420) ui->opisE->setText("sorbitrol - powoduje powstanie zacmy, ma dzialanie przeczyszczajace");
    else if(rob==554||rob==555||rob==556||rob==559) ui->opisE->setText("krzemian - prowadzi do odkladania sie glinu w organizmie");
    else if(rob==621) ui->opisE->setText("glutaminian sodu - wzmacniacz smaku- powoduje bole glowy i zawroty, palpitacje serca, nadmierna potliwosc");
    else if(rob==622) ui->opisE->setText("glutaminian potasu - wzmacniacz smaku - powoduje bole glowy, pogorszenie wzroku, bezsennosc, oslabienie,otylosc");
    else if(rob==951) ui->opisE->setText("aspartam - substancja slodzaca - powoduje osadzanie zanieczyszczen w organizmie");
    else if(rob==954) ui->opisE->setText("sacharyna - stymuluje dzialania komorek nowotworowych");
    else if(rob==110) ui->opisE->setText("zolcien pomaranczowa - barwnik, powoduje reakcje alergiczne");
    else ui->opisE->setText("Brak informacji");





}

void MainWindow::on_actionCo_to_jest_2_triggered()
{
    ui->definicja->setVisible(1);
    ui->label->setVisible(0);
    ui->wzrost->setVisible(0);
    ui->label_2->setVisible(0);
    ui->masa->setVisible(0);
    ui->oblicz->setVisible(0);
    ui->label_3->setVisible(0);
    ui->wynik->setVisible(0);
    ui->c->setVisible(0);
    ui->opis->setVisible(0);
    ui->label_4->setVisible(0);
    ui->e->setVisible(0);
    ui->opisE->setVisible(0);
    ui->ok->setVisible(0);
    ui->label_5->setVisible(0);
    ui->definicja->setText("Substancje E to dodatki chemiczne dodawane do zywnosci,"
                           " polepszacze, zageszczacze, barwniki i sztuczne konserwanty maja nadac atrakcyjny wyglad,"
                           " poprawic smak, przedluzyc okres przydatnosci do spozycia, spulchnic lub zagescic. "
                           "Jednak wiele z tych substancji dodanych do zywnosci moze powodowac lub nasilac problemy zdrowotne,"
                           "np. reakcje alergiczne, bole zoladkowe, astme, zapalenia skory, migrene, katar sienny i nadwrazliwosc sensoryczna. "
                           "Sprawdz czy i w jakim stopniu skladnik na Twoim produkcie jest dla ciebie szkodliwy.");

}
