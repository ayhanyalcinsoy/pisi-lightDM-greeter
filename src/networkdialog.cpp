#include "networkdialog.h"
#include "ui_networkdialog.h"

#include "QString"
#include <QDebug>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>

NetworkDialog::NetworkDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkDialog)
{
    ui->setupUi(this);

    logButtonClicked = false;


}

NetworkDialog::~NetworkDialog()
{
    delete ui;
}

void NetworkDialog::SetText(QString Text){

    if(!logButtonClicked)
        ui->NDtextEdit->setText(Text);

}

void NetworkDialog::addService(QString Text){



}

static bool hidden = false;


void NetworkDialog::on_logbutton_clicked()
{
    FILE *fp;


    QString  tmpstring;
    QString outstr;
    int size;

    tmpstring = "";


    fp = fopen("/var/log/lightdm/seat0-greeter.log", "r");
    if (fp == NULL) {
        qWarning() << tr("Greeter log read error");
        return;
    }


    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);

    char data[sz - 1];

    rewind(fp);


    size = fread(data, 1, sizeof(data), fp);
    if(size < 1){
        qWarning() << tr("Greeter log read error");
        pclose(fp);
        return;
    }

    /* close */
    pclose(fp);


    for(int i = sz - 1; i> 0; i--){

        if(data[i] != '\"'){
            data[i] = 0;
        }else{
            break;
        }
    }

    tmpstring = QString::fromLocal8Bit(data,size);

    ui->NDtextEdit->setText(tmpstring);

    logButtonClicked = true;

}
