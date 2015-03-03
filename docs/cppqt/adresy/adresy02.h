#ifndef ADRESY_H
#define ADRESY_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QTextCodec>

namespace Ui {
class adresy;
}

class adresy : public QWidget
{
    Q_OBJECT

public:
    explicit adresy(QWidget *parent = 0);
    ~adresy();

    enum Tryb { nawigujT, dodajT, edytujT };

public slots:
    void dodajKontakt();
    void koniec();

private:
    Ui::adresy *ui;
    QPushButton *dodajBtn;
    QPushButton *zapiszBtn;
    QPushButton *anulujBtn;
    QPushButton *poprzBtn;
    QPushButton *nastBtn;
    QPushButton *edytujBtn;
    QPushButton *usunBtn;
    QPushButton *koniecBtn;
    QLineEdit *nazwaLine;
    QTextEdit *adresText;

    Tryb aktTryb;
    void aktGui(Tryb tryb);
    QString staraNazwa;
    QString staryAdres;
    QMap<QString,QString> kontakty;

};

#endif // ADRESY_H
