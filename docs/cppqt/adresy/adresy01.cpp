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

    setWindowTitle(trUtf8("Prosta książka adresowa"));
}

adresy::~adresy()
{
    delete ui;
}
