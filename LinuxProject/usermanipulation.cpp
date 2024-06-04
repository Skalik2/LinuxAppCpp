#include "usermanipulation.h"

userManipulation::userManipulation() {}

void userManipulation::addPassword(const QString &username, const QString &password) {
    QProcess process;

    // Adding user with home directory
    QStringList addUserArgs;
    addUserArgs << "passwd" << username;
    process.start("sudo", addUserArgs);
    process.write(password.toUtf8() + "\n");
    process.write(password.toUtf8() + "\n");
    process.waitForFinished();

    if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
        qDebug() << "Error adding password:" << process.readAllStandardError();
        return;
    }

    qDebug() << "User password added successfully: " << username;
}

void userManipulation::addUser(const QString &username, const QString &sudoPassword) {
    QProcess process;

    // Adding user with home directory
    QStringList addUserArgs;
    addUserArgs << "-S" << "useradd" << "-m" << username;
    process.start("sudo", addUserArgs);
    process.write(sudoPassword.toUtf8() + "\n");
    process.waitForFinished();

    if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
        qDebug() << "Error adding user:" << process.readAllStandardError();
        return;
    }

    qDebug() << "User added successfully with home directory:" << username;
}

void userManipulation::userDel(const QString &username, const QString &sudoPassword) {
    QProcess process;

    // Adding user with home directory
    QStringList addUserArgs;
    addUserArgs << "userdel" << "-f" << username;
    process.start("sudo", addUserArgs);
    process.write(sudoPassword.toUtf8() + "\n");
    process.waitForFinished();

    if (process.exitStatus() != QProcess::NormalExit || process.exitCode() != 0) {
        qDebug() << "Error deleting user:" << process.readAllStandardError();
        return;
    }

    qDebug() << "User deleted successfully: " << username;
}

