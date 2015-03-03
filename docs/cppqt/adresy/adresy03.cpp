#include "adresy.h"
#include "ui_adresy.h"

adresy::adresy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adresy)
{
    ui->setupUi(this);

    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    nazwaLine = new QLineEdit;
    nazwaLine = ui->nazwaLine;
    nazwaLine->setReadOnly(true);

    adresText = new QTextEdit;
    adresText = ui->adresText;
    adresText->setReadOnly(true);

    dodajBtn = new QPushButton;
    dodajBtn = ui->dodajBtn;

    zapiszBtn = new QPushButton;
    zapiszBtn = ui->zapiszBtn;
    zapiszBtn->hide();

    anulujBtn = new QPushButton;
    anulujBtn = ui->anulujBtn;
    anulujBtn->hide();

    nastBtn = new QPushButton;
    nastBtn = ui->nastBtn;
    nastBtn->setEnabled(false);

    poprzBtn = new QPushButton;
    poprzBtn = ui->poprzBtn;
    poprzBtn->setEnabled(false);

    edytujBtn = new QPushButton;
    edytujBtn = ui->edytujBtn;
    edytujBtn->setEnabled(false);

    usunBtn = new QPushButton;
    usunBtn = ui->usunBtn;
    usunBtn->setEnabled(false);

    koniecBtn = new QPushButton;
    koniecBtn = ui->koniecBtn;
    koniecBtn->setEnabled(true);

    connect(dodajBtn, SIGNAL(clicked()), this, SLOT(dodajKontakt()));
    connect(koniecBtn,SIGNAL(clicked()),this, SLOT(koniec()));
    connect(zapiszBtn, SIGNAL(clicked()), this, SLOT(zapiszKontakt()));
    connect(anulujBtn, SIGNAL(clicked()), this, SLOT(anuluj()));

    setWindowTitle(trUtf8("Prosta książka adresowa"));
}

adresy::~adresy()
{
    delete ui;
}

void adresy::dodajKontakt() {
    staraNazwa = nazwaLine->text();
    staryAdres = adresText->toPlainText();

    nazwaLine->clear();
    adresText->clear();

    aktGui(dodajT);
}

void adresy::aktGui(Tryb tryb) {
    aktTryb=tryb;
    switch (aktTryb) {
        case dodajT:
        case edytujT:
            nazwaLine->setReadOnly(false);
            nazwaLine->setFocus(Qt::OtherFocusReason);
            adresText->setReadOnly(false);

            dodajBtn->setEnabled(false);
            edytujBtn->setEnabled(false);
            usunBtn->setEnabled(false);

            zapiszBtn->show();
            anulujBtn->show();

            nastBtn->setEnabled(false);
            poprzBtn->setEnabled(false);
        break;
        case nawigujT:
            if (kontakty.isEmpty()) {
                nazwaLine->clear();
                adresText->clear();
            }
            nazwaLine->setReadOnly(true);
            adresText->setReadOnly(true);
            dodajBtn->setEnabled(true);

            int ile=kontakty.size();
            edytujBtn->setEnabled(ile >= 1);
            usunBtn->setEnabled(ile >=1 );
            nastBtn->setEnabled(ile > 1);
            poprzBtn->setEnabled(ile > 1);

            zapiszBtn->hide();
            anulujBtn->hide();
        break;
    }
}

void adresy::koniec() {
    adresy::close();
}

void adresy::zapiszKontakt() {
    QString nazwa = nazwaLine->text();
    QString adres = adresText->toPlainText();

    if (nazwa == "" || adres == "") {
        QMessageBox::information(this, trUtf8("Puste pole"),trUtf8("Proszę wpisać nazwę i adres."));
        return;
    }

    if (aktTryb == dodajT) {
        if (!kontakty.contains(nazwa)) {
            kontakty.insert(nazwa, adres);
            QMessageBox::information(this, trUtf8("Dodano wpis"),
                                     trUtf8("Kontakt \"%1\" dodano do książki adresowej.").arg(nazwa));
        } else {
            QMessageBox::information(this, trUtf8("Nie dodano wpisu"),
                                     trUtf8("Przykro, ale kontakt \"%1\" jest już w książce adresowej.").arg(nazwa));
        }
    }

    aktGui(nawigujT);
}

void adresy::anuluj() {
    nazwaLine->setText(staraNazwa);
    adresText->setText(staryAdres);
    aktGui(nawigujT);
}
