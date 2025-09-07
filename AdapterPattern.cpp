/*
* project   : https://github.com/Robin005cr/Design_Patterns
* file name : AdapterPattern.cpp
* author    : Robin CR
* mail id   : robinchovallurraju@gmail.com
* LinkedIn  : https://www.linkedin.com/in/robin-cr/
* portfolio : https://robin005cr.github.io/
*
* Note : If any mistakes, errors, or inconsistencies are found in the code, please feel free to mail me.
* Suggestions for improvements or better methods are always welcome and appreciated.
* I value constructive feedback and aim to continuously improve the quality of the work.
*
*/
#include <iostream>
using namespace std;

class XMLDataHandler
{
    string XMLData;

public:
    XMLDataHandler(string mXMLData)
    {
        mXMLData = XMLData;
    }

    void xmlTojsonConverter()
    {
        cout << "Doing operations to convert xml to json" << endl;
    }
};

class DataHandlerTool
{
    string JSONdata;

public:
    DataHandlerTool() {}
    DataHandlerTool(string mJSONdata)
    {
        mJSONdata = JSONdata;
    }
    void evaluteData()
    {
        cout << "Evaluating data" << endl;
    }
    virtual void analyseData()
    {
        cout << "Handling JSON data" << endl;
        evaluteData();
    }
};

class XMLAdapter : public DataHandlerTool
{
    XMLDataHandler *xmlDataPtr;

public:
    XMLAdapter(XMLDataHandler *mxmlDataptr)
    {
        xmlDataPtr = mxmlDataptr;
    }
    void analyseData()
    {
        cout << "Handling XML data" << endl;
        xmlDataPtr->xmlTojsonConverter();
        evaluteData();
    }
};
class Client
{
public:
    void processData(DataHandlerTool *tool)
    {
        tool->analyseData();
    }
};
int main()
{
    XMLDataHandler *xmlData = new XMLDataHandler("XML data");

    DataHandlerTool *tool = new XMLAdapter(xmlData);
    Client *billingClient = new Client;
    billingClient->processData(tool);

    return 0;
}