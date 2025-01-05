#include <iostream>
#include <string>
using namespace std;

class Printer
{
public:
    virtual void PrinterBlackNWhite(string s) = 0;
    virtual void PrinterColor(string s) = 0;
};

class Scanner
{
public:
    virtual void ScannerFun(string s) = 0;
};

class DocumentA4Paper : public Printer, public Scanner
{
public:
    void PrinterBlackNWhite(string s) override
    {
        if (s == "PDF")
        {
            cout << "It can be printed in black and white" << endl;
        }
    }

    void PrinterColor(string s) override
    {
        if (s == "IMG")
        {
            cout << "It can be printed in color" << endl;
        }
    }

    void ScannerFun(string s) override
    {
        cout << "Scanning can be executed" << endl;
    }
};

class Client
{
    string printFormat;
public:
    Client(string docType) : printFormat{ docType } { }

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

    void executeScan(Scanner& scanner)
    {
        scanner.ScannerFun(printFormat);
    }
};

int main()
{
    DocumentA4Paper myDocument;

    Client robin("PDF");
    robin.executePrint(myDocument);  // Printing in black and white

    Client User2("IMG");
    User2.executePrint(myDocument);  // Printing in color

    robin.executeScan(myDocument);   // Executing scanning for "PDF"

    return 0;
}
