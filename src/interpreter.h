#ifndef MINIDB_INTERPRETER_H_
#define MINIDB_INTERPRETER_H_

#include <string>
#include <vector>

#include "minidb_api.h"
#include "sql_statement.h"

// interprate and execute SQL statements
// receives a SQL statement,formats,constructs a SQL statement object,passes this object in API

// the class interprating SQL statements
class Interpreter {
private:
  MiniDBAPI *api;
  std::string sql_statement_;
  std::vector<std::string> sql_vector_;
  int sql_type_;
  void TellSQLType();
  void FormatSQL();
  void Run();

public:
  Interpreter();
  ~Interpreter();
  void ExecSQL(std::string statement);
};

#endif /* MINIDB_INTERPRETER_H_ */
