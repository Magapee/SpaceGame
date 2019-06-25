/*
#include "SettingsLoader.h"
using namespace std;

vector<int> SettingsLoader::settingsLoader()//Хуйня, которая все соединяет
{
    setNameList();
    try
    {
        ifstream settingsFile;
        string settingsRead;
        settingsFile.open(settingsFileDirectory);
        if (!settingsFile.is_open())
            setDefaultSettings();
        else
        {
            settingsFile >> settingsRead;
            if (settingsRead == "")
                throw -1;
            for (int i = 0; !settingsFile.eof(); i++)
            {
                int stage = 0;
                switch (stage)
                {
                case 0:
                    if (settingsRead != namesList[i])
                        {
                            settingsFile.close();
                            throw stage;
                        }
                    settingsRead = "";
                    stage++;
                case 1:
                    settingsFile >> settingsRead;
                    if (settingsRead != "=")
                        {
                            settingsFile.close();
                            throw stage;
                        }
                    settingsRead = "";
                    stage++;
                case 2:
                    settingsFile >> settingsRead;
                    for(int j = 0; j < settingsRead.size(); j++)
                        if (!((settingsRead[j] <= '9') && (settingsRead[j] >= '0')))
                        {
                            settingsFile.close();
                            throw stage;
                        }
                    stringstream newValue;
                    newValue << settingsRead;
                    int newValueI;
                    newValue >> newValueI;
                    settingsList.resize(settingsList.size()+1);
                    settingsList[i] = newValueI;
                case 3:
                    settingsRead = "";
                    settingsFile >> settingsRead;
                };
            }
        }
        settingsFile.close();
        return settingsList;
    }
    catch(int a)
    {
        setDefaultSettings();
        return settingsList;
    }
}

void SettingsLoader::setNameList()//Задает список имен настроек
{
    namesList.push_back("width");
    namesList.push_back("height");
    namesList.push_back("fullscreen");
    namesList.push_back("ticksPerSecond");
}

void SettingsLoader::setDefaultSettingsList()//Задает список стандартных настроек на случай долбоеба за компом
{
    defaultSettingsList.push_back(800);
    defaultSettingsList.push_back(600);
    defaultSettingsList.push_back(1);
    defaultSettingsList.push_back(30);
}

void SettingsLoader::setDefaultSettings()//Записывает дефолтные настройки в вектор и в файл
{
    setDefaultSettingsList();
    ofstream settingsFile;
    settingsFile.open(settingsFileDirectory);
    int listSize = defaultSettingsList.size();
    for (int i = 0; i < listSize; i++)
    {
        settingsList.resize(settingsList.size() + 1);
        settingsList[i] = defaultSettingsList[i];
        settingsFile << namesList[i] << " = " << defaultSettingsList[i] << endl;
    }
    settingsFile.close();
}*/
