/*#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

class SettingsLoader
{
private:
    vector<int> settingsList;//Хранит уже готовые настройки
    vector<int> defaultSettingsList;//Тут стандартные настройки
    vector<string> namesList;//Тут имена настроек
    void setDefaultSettingsList();//Закидывает дефолтные настройки в вектор
    void setNameList();//Как прошлая, только с именами
    void setDefaultSettings();//Вызывается при хуйне в файле, задает стандартные настройки в вектор и записывает их в файл
    string settingsFileDirectory = "settings.cfg";//Тут директория файла
public:
    vector<int> settingsLoader();//Функция, которое все это связывает и возаращает готовый вектор с настройками
};*/
