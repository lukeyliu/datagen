#include "zutils.h"
#include "qstring.h"
#include "qdir.h"
#include "qcoreapplication.h"
#include "qtextstream.h"

QString ZUtils::getAppPath()
{
    return QCoreApplication::applicationDirPath ();
}
bool ZUtils::isInt(QString value){
    bool ok=false;
    value.toInt(&ok);
    return ok;
}

bool ZUtils::isDouble(QString value){
    bool ok=false;
    value.toDouble(&ok);
    return ok;
}

bool ZUtils::isBool(QString value){
    if(value.compare("true")==0 || value.compare("false")==0){
        return true;
    }
    return false;
}


void ZUtils::split(QVector<QString>& svec, const QString& ssrc, const QString& seps)
{
    svec.clear();
    QString strForSplit(ssrc);
    char * pch = NULL;
    pch = strtok(const_cast<char *>(strForSplit.toStdString().c_str()), seps.toStdString().c_str());
    while (pch)
    {
        svec.push_back(pch);
        pch = strtok(NULL, seps.toStdString().c_str());
    }
}

bool ZUtils::saveToFile(QString filename, QString xstr)
{
    QFile::remove(filename);
    QFile* file = new QFile(filename);
    file->open(QFile::ReadWrite);
    QTextStream txtOutput(file);
    txtOutput<<xstr<<endl;
    file->flush();
    return true;
}
