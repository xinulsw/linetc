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
};

#endif // ADRESY_H
