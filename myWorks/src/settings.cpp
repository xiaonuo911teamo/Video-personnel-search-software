#include "settings.h"
//#include "tinystr.h"
#include "tinyxml.h"
#include <string>

Settings::Settings()
{
    m_datas.clear();
    s_strangers=m_datas["strangers"]="D:/xiaonuo-Exclusive/Knowledge/QT/QT-exercise/myWorks/strangers/";
    s_video=m_datas["video"]="1-5.mp4";
    s_faceCascade=m_datas["faceCascade"]="./xml/haarcascade_frontalface_alt.xml";
    s_modelPCA=m_datas["modelPCA"]="./xml/facePCAModel.xml";
}

Settings::~Settings()
{

}

void Settings::addPeople(PeopleSettings* people)
{
    peopleSets.push_back(people);
    people->i_label=i_sum;          //label是内部属性，只会由内部赋值
    i_sum++;
}

void Settings::addPeople(string name, string num, string note, string picAddr, int age, int label)
{
    PeopleSettings* p = new PeopleSettings(name,num,age,note,picAddr,label);
    peopleSets.push_back(p);
    i_sum++;
}

void Settings::save(const char *filename)
{
    TiXmlDocument doc;
    TiXmlElement* data;
    TiXmlText* text;

    TiXmlDeclaration * decl = new TiXmlDeclaration( "1.0", "UTF-8", "" );
    doc.LinkEndChild( decl );

    TiXmlElement * root = new TiXmlElement( "MyApp" );
    doc.LinkEndChild( root );

    TiXmlComment* comment = new TiXmlComment();
    comment->SetValue(" Settings for MyApp ");
    root->LinkEndChild(comment);

    TiXmlElement* datas = new TiXmlElement("AppDatas");
    root->LinkEndChild(datas);

    m_datas["strangers"]=s_strangers;
    m_datas["video"]=s_video;
    m_datas["faceCascade"]=s_faceCascade;
    m_datas["modelPCA"]=s_modelPCA;

    data = new TiXmlElement("strangers");
    text = new TiXmlText(s_strangers.c_str());
    data->LinkEndChild(text);
    datas->LinkEndChild(data);

    data = new TiXmlElement("video");
    text = new TiXmlText(s_video.c_str());
    data->LinkEndChild(text);
    datas->LinkEndChild(data);

    data = new TiXmlElement("faceCascade");
    text = new TiXmlText(s_faceCascade.c_str());
    data->LinkEndChild(text);
    datas->LinkEndChild(data);

    data = new TiXmlElement("modelPCA");
    text = new TiXmlText(s_modelPCA.c_str());
    data->LinkEndChild(text);
    datas->LinkEndChild(data);

    TiXmlElement * peopleNode = new TiXmlElement( "Peoples" );
    root->LinkEndChild( peopleNode );

    vector<PeopleSettings*>::iterator iter;

    for (iter=peopleSets.begin(),i_sum=0; iter != peopleSets.end(); iter++,i_sum++)
    {
        const PeopleSettings* p=*iter;
        string s="people";

        TiXmlElement * people;
        people = new TiXmlElement(s.c_str());
        peopleNode->LinkEndChild( people );
        people->SetAttribute("name", p->s_name.c_str());
        people->SetAttribute("num",p->s_num.c_str());
        people->SetAttribute("age", p->i_age);
        people->SetAttribute("note", p->s_note.c_str());
        people->SetAttribute("picAddr", p->s_picAddr.c_str());
        people->SetAttribute("label", p->i_label);
    }

    TiXmlElement* sum = new TiXmlElement("Sum");
    root->LinkEndChild(sum);
    sum->SetAttribute("sum",i_sum);

    doc.SaveFile( filename );
}

bool Settings::load(const char *filename)
{
    TiXmlDocument doc(filename);
    if (!doc.LoadFile()) return false;

    TiXmlHandle hDoc(&doc);
    TiXmlElement* pElem;
    TiXmlHandle hRoot(0);

    // 创建根节点指针
    {
        pElem=hDoc.FirstChildElement().Element();
        // should always have a valid root but handle gracefully if it does
        if (!pElem) return false;

        // save this for later
        hRoot=TiXmlHandle(pElem);
    }

    // 读取配置选项
    {
        m_datas.clear(); // trash existing table

        pElem=hRoot.FirstChild( "AppDatas" ).FirstChild().Element();
        for( ; pElem; pElem=pElem->NextSiblingElement())
        {
            const char *pKey=pElem->Value();
            const char *pText=pElem->GetText();
            if (pKey && pText)
            {
                m_datas[pKey]=pText;
            }
        }
    }

    s_strangers = m_datas["strangers"];
    s_video = m_datas["video"];
    s_faceCascade = m_datas["faceCascade"];
    s_modelPCA = m_datas["modelPCA"];

    // 读取已登记人员的信息
    {
        peopleSets.clear(); // trash existing list

        TiXmlElement* pPeopleNode=hRoot.FirstChild( "Peoples" ).FirstChild().Element();
        for( ; pPeopleNode; pPeopleNode=pPeopleNode->NextSiblingElement())
        {
            PeopleSettings* p=new PeopleSettings;
            const char *pName=pPeopleNode->Attribute("name");
            if (pName) p->s_name=pName;

            const char *pNum=pPeopleNode->Attribute("num");
            if (pNum) p->s_num=pNum;

            const char *pNote=pPeopleNode->Attribute("note");
            if (pNote) p->s_note=pNote;

            const char *pPicAddr=pPeopleNode->Attribute("picAddr");
            if (pPicAddr) p->s_picAddr=pPicAddr;

            pPeopleNode->QueryIntAttribute("age", &p->i_age); // If this fails, original value is left as-is
            pPeopleNode->QueryIntAttribute("label", &p->i_label);

            peopleSets.push_back(p);

        }
    }

    pElem=hRoot.FirstChild( "AppDatas" ).FirstChild().Element();
    pElem->QueryIntAttribute("sum",&i_sum);

    return true;
}

void Settings::setFaceCascade(string faceCascade)
{
    s_faceCascade = faceCascade;
    m_datas["faceCascade"]=faceCascade;
}

void Settings::setModelPCA(string modelPCA)
{
    s_modelPCA = modelPCA;
    m_datas["modelPCA"]=modelPCA;
}

void Settings::setStrangers(string strangers)
{
    s_strangers = strangers;
    m_datas["strangers"]=strangers;
}

void Settings::setVideo(string video)
{
    s_video = video;
    m_datas["video"]=video;
}
