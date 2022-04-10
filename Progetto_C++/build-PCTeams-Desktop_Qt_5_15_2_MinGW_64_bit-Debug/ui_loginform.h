/********************************************************************************
** Form generated from reading UI file 'loginform.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINFORM_H
#define UI_LOGINFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LoginForm
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_pic;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *LoginForm)
    {
        if (LoginForm->objectName().isEmpty())
            LoginForm->setObjectName(QString::fromUtf8("LoginForm"));
        LoginForm->resize(529, 519);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(LoginForm->sizePolicy().hasHeightForWidth());
        LoginForm->setSizePolicy(sizePolicy);
        LoginForm->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(LoginForm);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_pic = new QLabel(LoginForm);
        label_pic->setObjectName(QString::fromUtf8("label_pic"));
        label_pic->setMinimumSize(QSize(0, 200));
        label_pic->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_pic);

        label = new QLabel(LoginForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setTextFormat(Qt::RichText);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(LoginForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setTextFormat(Qt::RichText);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(LoginForm);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(0, 50));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color:white;"));
        lineEdit->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit);

        label_3 = new QLabel(LoginForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_3);

        lineEdit_2 = new QLineEdit(LoginForm);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEdit_2->sizePolicy().hasHeightForWidth());
        lineEdit_2->setSizePolicy(sizePolicy2);
        lineEdit_2->setMinimumSize(QSize(0, 50));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color:white;"));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        lineEdit_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lineEdit_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(LoginForm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMinimumSize(QSize(200, 50));
        pushButton->setStyleSheet(QString::fromUtf8("background-color:white;"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(LoginForm);

        QMetaObject::connectSlotsByName(LoginForm);
    } // setupUi

    void retranslateUi(QDialog *LoginForm)
    {
        LoginForm->setWindowTitle(QCoreApplication::translate("LoginForm", "Login", nullptr));
        label_pic->setText(QString());
        label->setText(QCoreApplication::translate("LoginForm", "<html><head/><body><p><span style=\" font-family:'Bradley Hand ITC'; font-size:16pt; font-weight:700;\">INSERISCI QUI LE TUE CREDENZIALI:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("LoginForm", "<html><head/><body><p><span style=\" font-family:'Bradley Hand ITC'; font-size:16pt; font-weight:700;\">USERNAME:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("LoginForm", "<html><head/><body><p><span style=\" font-family:'Bradley Hand ITC'; font-size:16pt; font-weight:700;\">PASSWORD:</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginForm", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginForm: public Ui_LoginForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINFORM_H
