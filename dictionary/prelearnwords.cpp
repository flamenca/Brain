#include "prelearnwords.h"
#include <QFile>
#include <QDebug>

#include "dbcontroler.h"

PreLearnWords::PreLearnWords()
{
}
void PreLearnWords::InitCi(){

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
                QString pattern("\\*(.*) ([abcdefghijklmnopqrstuvwxyzīíǐìāáǎàōóǒòūúǔùüǖǘǚǜēéěèńň,]*)笔划：(.*)部首：(.*)五笔输入法");
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
