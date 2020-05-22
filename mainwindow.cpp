#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMenuBar"
#include <QAction>
#include <QtDebug>
#include <QFileDialog>
#include <QColorDialog>
#include <QFontDialog>
#include <QMessageBox>
#include <QStringList>
#include <QTableWidgetItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    com::setStyle("://Proj/white.qss");
    //这些都改成为qss样式
    setWindowTitle("Rabbitchenc style demo");
    ui->helpAction->setIcon(QIcon("://Image/sysicon/帮助.png"));
    ui->openAction->setIcon(QIcon("://Image/File/open.jpg"));
    ui->closeAction->setIcon(QIcon("://Image/File/clo.png"));
    ui->saveAction->setIcon(QIcon("://Image/File/save.png"));
    ui->deleteAction->setIcon(QIcon("://Image/sysicon/delete.png"));
    ui->newAction->setIcon(QIcon("://Image/File/new.jpeg"));
    ui->rejuAction->setIcon(QIcon("://Image/File/皮肤.png"));
    QPixmap img = QPixmap(":/Image/庄周.jpeg");
    ui->label->setPixmap(img);
    ui->textEdit->setText("蝴蝶是我，抑或我就是蝴蝶？");


    //设置表格相关的内容
    ui->tableAttri->setColumnCount(3);
    ui->tableAttri->setHorizontalHeaderLabels(QStringList()<<"属性"<<"星数"<<"备注");
    ui->tableAttri->setRowCount(10);
    QStringList attriList;
    attriList << "生存能力" <<"攻击伤害"<<"技能效果"<<"上手难度"<<"红色铭文" << "绿色铭文" << "蓝色铭文"<< "玩法技巧"<<"英雄点评"<<"英雄皮肤";

    QList<QString> startList;
    startList << "********" <<"**" <<"***" <<"**" <<".."<<".."<<".."<<".."<<".."<<"..";
    for(int i=0;i<10;i++){
         int col = 0;
         ui->tableAttri->setItem(i,col++,new QTableWidgetItem(attriList[i]));
         ui->tableAttri->setItem(i,col++,new QTableWidgetItem(startList.at(i)));
         ui->tableAttri->setCellWidget(i,col++,new QLabel);
    }

    QStringList cloth1List,cloth2List,cloth3List;

    cloth1List << "近卫荣耀" <<"影忍之足"<<"魔女斗篷"<<"极寒风暴"<<"霸者重装" << "痛苦面具";
    cloth2List << "救赎之翼" <<"影忍之足"<<"红莲斗篷"<<"极寒风暴"<<"不祥征兆" << "魔女斗篷";
    cloth3List << "爆裂之甲" <<"影忍之足"<<"冰封之心"<<"极寒风暴"<<"魔女斗篷" << "痛苦面具";

    ui->tableSkill->setColumnCount(10);
    ui->tableSkill->setRowCount(3);

    QStringList titles;
    titles << "推荐出装1"<< "推荐出装2"<<"推荐出装3";
    ui->tableSkill->setVerticalHeaderLabels(titles);
    for(int j=0;j<6;j++){
         int col = 0;
         ui->tableSkill->setItem(col++,j,new QTableWidgetItem(cloth1List[j]));
         ui->tableSkill->setItem(col++,j,new QTableWidgetItem(cloth2List[j]));
         ui->tableSkill->setItem(col++,j,new QTableWidgetItem(cloth3List[j]));
    }

    //树状列表部分
    QTreeWidgetItem * subRoot[2];

    QStringList subRList;
    subRList << "技能信息" << "英雄关系";

    for(int i=0;i<2;i++){
        subRoot[i] = new QTreeWidgetItem(ui->treeWidget);
        subRoot[i]->setText(0,subRList[i]);
        subRoot[i]->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable);
    }

    QStringList skillList;
    skillList << "自然意志（被动）" <<"化蝶（1技能）" <<"蝴蝶效应（2技能）" << "天人合一（大招）";

    QTreeWidgetItem *skillItem[4];
    for(int i =0;i<4;i++){
       skillItem[i] = new QTreeWidgetItem(subRoot[0]);
       skillItem[i]->setText(0,skillList[i]);
    }

    QTreeWidgetItem *infoItem[3];
    QStringList typeList;
    typeList << "最佳搭档" <<"压制英雄"<<"被压制英雄";
    for(int i =0;i<3;i++){
       infoItem[i] = new QTreeWidgetItem(subRoot[1]);
       infoItem[i]->setText(0,typeList[i]);
    }


    QTreeWidgetItem *partnerItem[2];
    QStringList partnerList;
    partnerList << "不知火舞" << "黄忠";
    for(int i=0;i<2;i++){
       partnerItem[i] = new QTreeWidgetItem(infoItem[0]);
       partnerItem[i]->setText(0,partnerList[i]);
    }

    QTreeWidgetItem *winnerItem[2];
    QStringList winnerList;
    winnerList << "花木兰" << "后羿";
    for(int i=0;i<2;i++){
       winnerItem[i] = new QTreeWidgetItem(infoItem[1]);
       winnerItem[i]->setText(0,winnerList[i]);
    }


    QTreeWidgetItem *loserItem[2];
    QStringList loserList;
    loserList << "韩信" << "貂蝉";
    for(int i=0;i<2;i++){
       loserItem[i] = new QTreeWidgetItem(infoItem[2]);
       loserItem[i]->setText(0,loserList[i]);
    }
        QWidget *styleWidget = new QWidget;

        QStringList styleList;
        styleList << "样式1" <<"样式2";
        QPushButton *btnStyle[2];
        for(int i=0;i<2;i++){
            btnStyle[i] = new QPushButton(styleWidget);
            btnStyle[i]->move(400*i+20,20);
            btnStyle[i]->setText(styleList[i]);
            btnStyle[i]->resize(300,300);
        }
        ui->tabWidget->insertTab(4,styleWidget,"皮肤样式");






}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_styleWhite_triggered()
{
    com::setStyle("://Proj/white.qss");
}

void MainWindow::on_styleBlack_triggered()
{
    com::setStyle("://Proj/black.qss");
}


void MainWindow::on_yesRadioButton_clicked()
{
    ui->checkBoxKun->setEnabled(true);
    ui->checkBoxFish->setEnabled(true);
    ui->checkBoxBird->setEnabled(true);
    ui->checkBoxBoth->setEnabled(true);

}

void MainWindow::on_noRadioButton_clicked()
{
     ui->checkBoxBird->setEnabled(false);
     ui->checkBoxBoth->setEnabled(false);
     ui->checkBoxKun->setEnabled(false);
     ui->checkBoxFish->setEnabled(false);
}


void MainWindow::on_closeAction_triggered()
{
    this->close();
}

void MainWindow::on_openAction_triggered()
{
    QFileDialog::getOpenFileName(this,"打开文件","/home/rabbitchenc/下载","*.txt");

}

void MainWindow::on_fontAction_triggered()
{
    bool flag;
    QFontDialog::getFont(&flag,this);
}

void MainWindow::on_colorAction_triggered()
{
    QColorDialog::getColor();
}

void MainWindow::on_aboutAction_triggered()
{
    QMessageBox::aboutQt(this);
}
