#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include "report.hpp"
using namespace  std;


class Report_Writer
{
   private:
   Report* report;
   
   public:
   Report_Writer(Report* report);
   void write_to_file();
};
