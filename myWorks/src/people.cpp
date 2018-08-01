#include "people.h"

PeopleSettings::PeopleSettings(string &name, string &num, int age, string &note, string &picAddr, int label)
{
    s_name = name;
    s_num = num;
    s_note = note;
    s_picAddr = picAddr;
    i_age = age;
    i_label = label;
}

PeopleSettings::PeopleSettings()
{

}

void PeopleSettings::setName(string name)
{
    s_name = name;
}

void PeopleSettings::setNote(string note)
{
    s_note = note;
}

void PeopleSettings::setNum(string num)
{
    s_num = num;
}

void PeopleSettings::setAge(string age)
{
    i_age = atoi(age.c_str());
}
