#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QTabWidget>
#include <QGraphicsWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <string>
#include <QChar>
#include <QProgressBar>
#include "farm.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(1525,790);


//:/farm_pic/G:/pro picturs/woodenplay.png
    timer=new QTimer;
    timer->setInterval(40);
    timer->start();
    ui->login_sign_pages->hide();
    ui->play_butt->hide();
    ui->progressBar->setValue(0);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_bar()));
    ui->login_sign_pages->setTabText(0,"Login");
    ui->login_sign_pages->setTabText(1,"Sign Up");

    QPixmap bkgnd(":/farm_pic/login 2.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

    QPixmap wooden(":/farm_pic/woodenplay.png");
    wooden=wooden.scaled(ui->label_3->size(),Qt::IgnoreAspectRatio);
    ui->label_3->setPixmap(wooden);
    ui->label_3->hide();
    ui->lineEdit_pass->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->lineEdit_l_pass->setEchoMode(QLineEdit::Password);
    ui->lineEdit_confirm->setEchoMode(QLineEdit::Password);

}
void MainWindow::update_bar()
{
    ui->progressBar->setValue(ui->progressBar->value()+1);
    if(ui->progressBar->value()==100)
    {

        timer->stop();
        ui->progressBar->hide();
        ui->label_3->show();
        ui->play_butt->show();

    }
}




void MainWindow::on_play_butt_clicked()
{
    ui->label_3->hide();
    ui->login_sign_pages->show();
}




bool is_st_pass(std::string password_)
{
     int n = password_.length();
      bool hasLower = false, hasUpper = false;
      bool hasDigit = false, specialChar = false;
      std::string normalChars = "abcdefghijklmnopqrstu" "vwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890 ";
      for (int i = 0; i < n; i++) {

         if (islower(password_[i]))
            hasLower = true;
         if (isupper(password_[i]))
           hasUpper = true;
         if (isdigit(password_[i]))
            hasDigit = true;
         size_t special = password_.find_first_not_of(normalChars);
         if (special != std::string::npos)
            specialChar = true;
      }


      if (hasLower && hasUpper && hasDigit &&
         specialChar && (n >= 8))
         return true;
      else
          return false;

}
void MainWindow::on_enter_butt_clicked()
{
    int i=0;
    if(ui->lineEdit_l_user->text().isEmpty()==true)
    {
        i++;
        ui->lineEdit_l_user->setPlaceholderText(" Necessary field !!!");
    }
    if(ui->lineEdit_l_pass->text().isEmpty())
    {
        i++;
        ui->lineEdit_l_pass->setPlaceholderText(" Necessary field !!!");
    }
//    if(!is_st_pass(ui->lineEdit_l_pass->text().toStdString()))
//    {
//         i++;
//         ui->lineEdit_l_pass->clear();
//         ui->lineEdit_l_pass->setPlaceholderText("Weak password,use special upper lower character &number.");

//    }
    if(i==0)
    {
        //try to login
        try{
            db.login(ui->lineEdit_l_user->text().toStdString(),ui->lineEdit_l_pass->text().toStdString());
            Farm_page *farmpage=new Farm_page;
            this->close();
            farmpage->show();
         }
        catch(QString err)
        {
            ui->lineEdit_l_pass->clear();
            ui->lineEdit_l_user->setPlaceholderText(" Necessary field !!!");
               QMessageBox::warning(this, "Error", err);

        }


    }

}



void MainWindow::on_create_butt_clicked()
{
    int i=0;
    if(ui->lineEdit_user->text().isEmpty()==true)
    {
        i++;
       ui->lineEdit_user->setPlaceholderText(" Necessary field !!!");
    }
    if(ui->lineEdit_boss->text().isEmpty()==true)
    {
        i++;
        ui->lineEdit_boss->setPlaceholderText(" Necessary field !!!");
    }
    if(ui->lineEdit_pass->text().isEmpty()==true)
    {
        i++;
        ui->lineEdit_pass->setPlaceholderText(" Necessary field !!!");
    }
    if(ui->lineEdit_confirm->text().isEmpty()==true)
    {
        i++;
        ui->lineEdit_confirm->setPlaceholderText(" Necessary field !!!");
    }
    if(ui->lineEdit_email->text().isEmpty()==true)
    {
        i++;
        ui->lineEdit_email->setPlaceholderText(" Necessary field !!!");
    }

    if(!is_st_pass(ui->lineEdit_pass->text().toStdString()))
    {
         i++;
         ui->lineEdit_pass->clear();
         ui->lineEdit_pass->setPlaceholderText("Weak password,use special upper lower character &number.");
         ui->lineEdit_confirm->clear();

    }
    if(ui->lineEdit_pass->text()!=ui->lineEdit_confirm->text())
    {
        i++;
        ui->lineEdit_pass->setPlaceholderText("Incompatibility of the password and its repetition");
        ui->lineEdit_confirm->clear();

    }
    if(i==0)
    {
        //create
        try{
        db.signup(ui->lineEdit_boss->text().toStdString(),ui->lineEdit_user->text().toStdString(),ui->lineEdit_pass->text().toStdString(),ui->lineEdit_email->text().toStdString());
         QMessageBox::information(this, "Successful registration", "Hope you enjoy the game, Boss");
        }
        catch(QString err)
        {
               QMessageBox::warning(this, "Error", err);
        }
    }


}


void MainWindow::on_pushButton_clicked()
{
    Farm_page *farmpage=new Farm_page;
    this->close();
    farmpage->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

