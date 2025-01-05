//There are 3 devices PrinterBlackNWhite, PrinterBlackNWhite and Scanner.
//According to the document type(PDF, IMG) and Paper size(A4, A3) execute print should be handled.
//Here the problem is class PrintScanDevices is taking 2 responsibilities print and scan, making a fat interface

#include <iostream>
#include<string>
using namespace std;
class PrintScanDevices
{
public:
    virtual void PrinterBlackNWhite(string s) = 0;
    virtual void(string s) = 0;
    virtual void Scanner(string s) = 0;
};

class DocumentA4Paper : public PrintScanDevices
{
public:
    void PrinterBlackNWhite(string s)
    {
        if (s == "PDF")
        {
            cout << "It can be printed" << endl;
        }
    }
    void PrinterColor(string s)
    {
        if (s == "PDF" || s == "IMG")
        {
            cout << "It can be printed" << endl;
        }
    }
    void Scanner(string s)
    {
        cout << "Scanning can be executed" << endl;
    }
};

class Client
{
    string printFormat;
public:
    Client(string docType) :printFormat{ docType }
    {

    }

    void executePrint(DocumentA4Paper myDocument)
    {
        if (printFormat == "PDF")
        {
            myDocument.PrinterBlackNWhite(printFormat);
        }
        else if (printFormat == "IMG")
        {
            myDocument.PrinterColor(printFormat);
        }
    }

};


int main()
{
    DocumentA4Paper myDocument;
    Client robin("PDF");
    robin.executePrint(myDocument);

    Client User2("IMG");
    User2.executePrint(myDocument);
    return 0;
}
