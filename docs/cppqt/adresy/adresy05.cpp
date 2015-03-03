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
    connect(nastBtn, SIGNAL(clicked()), this, SLOT(nast()));
    connect(poprzBtn, SIGNAL(clicked()), this, SLOT(poprz()));
    connect(edytujBtn, SIGNAL(clicked()), this, SLOT(edytujKontakt()));
    connect(usunBtn, SIGNAL(clicked()), this, SLOT(usunKontakt()));

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
    } else if (aktTryb == edytujT) {
        if (staraNazwa != nazwa) {
            if (!kontakty.contains(nazwa)) {
                QMessageBox::information(this, trUtf8("Edycja udana"),
                                         trUtf8("Wyedytowałeś kontakt \"%1\".").arg(staraNazwa));
                kontakty.remove(staraNazwa);
                kontakty.insert(nazwa,adres);
            } else {
                QMessageBox::information(this, trUtf8("Edycja nieudana"),
                                         trUtf8("Kontakt \"%1\" jest już w książce adresowej.").arg(nazwa));
            }
        } else if (staryAdres != adres) {
            QMessageBox::information(this,trUtf8("Edycja udana"),
                                     trUtf8("Wyedytowałeś kontakt \"%1\".").arg(nazwa));
            kontakty[nazwa]=adres;
        }
    }

    aktGui(nawigujT);
}

void adresy::anuluj() {
    nazwaLine->setText(staraNazwa);
    adresText->setText(staryAdres);
    aktGui(nawigujT);
}

void adresy::nast() {
    QString nazwa = nazwaLine->text();
    QMap<QString, QString>::iterator i = kontakty.find(nazwa);
    if (i != kontakty.end()) i++;
    if (i == kontakty.end()) i = kontakty.begin();
    nazwaLine->setText(i.key());
    adresText->setText(i.value());
}

void adresy::poprz() {
    QString nazwa = nazwaLine->text();
    QMap<QString, QString>::iterator i = kontakty.find(nazwa);
    if (i == kontakty.begin()) i = kontakty.end();
    i--;
    nazwaLine->setText(i.key());
    adresText->setText(i.value());
}

void adresy::edytujKontakt() {
    staraNazwa = nazwaLine->text();
    staryAdres = adresText->toPlainText();
    aktGui(edytujT);
}

void adresy::usunKontakt() {
    QString nazwa = nazwaLine->text();
    QString adres = adresText->toPlainText();

    if (kontakty.contains(nazwa)) {
        int button = QMessageBox::question(this,trUtf8("Potwierdź usunięcie"),
                                           trUtf8("Czy na pewno usunąć kontakt \"%1\"?").arg(nazwa),
                                           QMessageBox::Yes|QMessageBox::No);
        if (button == QMessageBox::Yes) {
            poprz();
            kontakty.remove(nazwa);
            QMessageBox::information(this,trUtf8("Usunięto"),
                                 trUtf8("Usunięto kontakt \"%1\".").arg(nazwa));
        }
    }
    aktGui(nawigujT);
}
