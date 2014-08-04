#include <QtCore/QCoreApplication>

#include "mailsender.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MailSender test("smtp-server.example.com", "sender@example.com", QStringList("receiver@example.com"), "Subject", "<html><header></header><body><H1>Some body</H1></body></html>");
//    test.setSubject("some subject"),
//    test.setBody("<html><header></header><body><H1>some body</H1></body></html>");
    test.setContentType(MailSender::html);
    test.setLogin("user", "password");
    test.setSsl(true);
//    test.setPort(1234);
//    test.setBcc(QStringList("mail@example.com"));
//    test.setAttachments(QStringList("path-to-your-attachment"));
//    test.setPriority(MailSender::high);
    if(test.send()) 
    {
        // mail sent !
    }
    else
    {
        // failed to send mail
    }

    return 0;
}

