#include "report_writer.hpp"
#include "report.hpp"
Report_Writer::Report_Writer(Report* report) : report(report) {}
void Report_Writer::write_to_file()
   {
     ofstream f;
     f.open("TIC_TAC_TOE/text.txt");
     if (f.is_open())
    { 
       f << report->generate_report();
    }
    else
    {
    cout << "Sorry, the file could not be openend." << endl;
    }

    f.close();
   }
