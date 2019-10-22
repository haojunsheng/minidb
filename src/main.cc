#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>
#include <readline/history.h>
#include <readline/readline.h>
#include "interpreter.h"

using namespace std;

int main(int argc, const char *argv[]) {

  string sql;
  // interprate and execute SQL statements
  // receives a SQL statement,formats,constructs a SQL statement object,passes this object in API
  Interpreter itp;

  char *line;
  size_t found;

  using_history();

  while (true) {
    // wating user input
    line = readline("MiniDB> ");
    sql = string(line);
    free(line);
    boost::algorithm::trim(sql);
    
    // if user inputs exit; or quit; then execsql quit and quit minidb
    if (sql.compare(0, 4, "exit") == 0 || sql.compare(0, 4, "quit") == 0) {
      itp.ExecSQL("quit");
      break;
    }
      
    // one sql statement ends in ";"
    // we use while get all input
    while ((found = sql.find(";")) == string::npos) {
      line = readline("");
      sql += "\n" + string(line);
      free(line);
    }
    
    // we use c++ open libraries -- readline to save sql
    if (sql.length() != 0) {
      add_history(sql.c_str());
    }
    // exec sql
    itp.ExecSQL(sql);
    std::cout << std::endl;
  }
  return 0;
}
