#include "prelearnwords.h"
#include <QFile>
#include <QDebug>

#include "dbcontroler.h"

PreLearnWords::PreLearnWords()
{
}

void PreLearnWords::InitCi(){
    char line[1024];
    QFile fdic("dic_utf8.txt");
    QFile fdic_out("dic_utf8_out.txt");

    QString Zi;
    QStringList ZiYinList;
    QString ZiYin;

    QString Ci;
    QString CiYin;

    bool isciyin = false;
    QString LastLine;

    QStringList section;
    section.clear();

    fdic_out.open(QIODevice::WriteOnly | QIODevice::Text );
    if ( fdic.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        while( !fdic.atEnd() ){
            memset((char *)line,0,1024);
            fdic.readLine(line,1024);

            QString str = QString::fromUtf8(line).trimmed();
            QString pattern_zi("\\*(.*) ([abcdefghijklmnopqrstuvwxyzīíǐìāáǎàōóǒòūúǔùüǖǘǚǜēéěèńň,]*)笔划:(.*)部首:(.*)五笔输入法");
            QString pattern_ci("(^[abcdefghijklmnopqrstuvwxyzīíǐìāáǎàōóǒòūúǔùüǖǘǚǜēéěèńň,'-]+)$");

            QRegExp rx_zi(pattern_zi);
            int pos_zi = str.indexOf(rx_zi);
            if( pos_zi >= 0 ){
                for(int i = 0 ; i < section.size() ; i ++){
                    fdic_out.write(section.at(i).toUtf8());
                }

                section.clear();
                ZiYin = rx_zi.cap(2);
                ZiYinList=ZiYin.split(",");
                Zi = rx_zi.cap(1);
            }else{
                QRegExp rx_ci(pattern_ci);
                int pos_ci = str.indexOf(rx_ci);

                if( pos_ci >= 0){
                    CiYin = rx_ci.cap(1).trimmed();
                    QStringList::iterator i = qFind(ZiYinList.begin(),ZiYinList.end(),CiYin );
                    if( i != ZiYinList.end() ){//it is a zi
                        Ci = Zi;
                        isciyin = true;
                    }else{
                        for(QStringList::iterator i=ZiYinList.begin();i!=ZiYinList.end();i++){
                            if( CiYin.contains(*i)){
                                isciyin = true;
                                Ci=LastLine;
                                break;
                            }
                        }
                    }
                }else{
                    if(isciyin){
                        if(Ci.contains("解释:")){
                            QString newziyin="";

                            QString firstline = section.at(0);
                            if( !firstline.contains(CiYin)){
                                if(ZiYin.size() == 0 || ZiYin.endsWith(",")){
                                    newziyin = ZiYin  + CiYin + ",";
                                }else{
                                    newziyin = ZiYin  + "," +CiYin +",";
                                }

                                qDebug() << "0 " << firstline;

                                firstline.replace(ZiYin+"笔划:",newziyin+"笔划:");
                                section[0] = firstline;

                                qDebug() << "1 " << firstline;
                            }

                        }
                        /*
                        QString pattern_zixing("【(.*)】");
                        QRegExp rx_zixing(pattern_zixing);
                        int pos_zixing = str.indexOf(rx_zixing);
                        if(pos_zixing>=0){
                            if(Ci.contains("解释:")){
                                qDebug() << Ci << ":" << rx_zixing.cap(1);
                            }
                        }*/
                        isciyin = false;
                    }
                }
            }

            section.append(line);
            LastLine = str;
        }

        for(int i = 0 ; i < section.size() ; i ++){
            fdic_out.write(section.at(i).toUtf8());
        }
        fdic_out.close();
        fdic.close();
    }
}

void PreLearnWords::InitZi(){
    char line[1024];
    QFile fdic("dic_utf8.txt");
    DBControler::OpenDB();
    DBControler::CreateZITable();
    int index=0;
    if ( fdic.open( QIODevice::ReadOnly | QIODevice::Text ) ){
        while( !fdic.atEnd() ){
            memset((char *)line,0,1024);
            fdic.readLine(line,1024);
            QString str = QString::fromUtf8(line);
            if( str.startsWith("*")){
                QString pattern("\\*(.*) ([abcdefghijklmnopqrstuvwxyzīíǐìāáǎàōóǒòūúǔùüǖǘǚǜēéěèńň,]*)笔划:(.*)部首:(.*)五笔输入法");
                QRegExp rx(pattern);

                int pos = str.indexOf(rx);
                if(pos < 0){
                }else{
                    QStringList pinyin = rx.cap(2).split(",");
                    if( pinyin.size() == 0 || pinyin.at(0).length() == 0){
                        //qDebug() << rx.cap(1) << rx.cap(2) << rx.cap(3) << rx.cap(4);
                        DBControler::AddZItoTable(index++,rx.cap(1),rx.cap(2),rx.cap(3),rx.cap(4));
                    }else{
                        for( int i = 0 ; i < pinyin.size() ; i++){
                            if( pinyin.at(i).length() == 0) break;
                            else
                                DBControler::AddZItoTable(index++,rx.cap(1),pinyin.at(i),rx.cap(3),rx.cap(4));
                        }
                    }
                }
            }
        }

        fdic.close();
    }
}
