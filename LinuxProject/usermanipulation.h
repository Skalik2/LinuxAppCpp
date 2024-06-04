#ifndef USERMANIPULATION_H
#define USERMANIPULATION_H

#include <QProcess>
#include <QDebug>

class userManipulation
{
public:
    userManipulation();
    void addPassword(const QString &username, const QString &password);
    void addUser(const QString &username, const QString &sudoPassword);
    void userDel(const QString &username, const QString &sudoPassword);
};

#endif // USERMANIPULATION_H
