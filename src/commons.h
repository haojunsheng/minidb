#ifndef MINIDB_COMMONS_H_
#define MINIDB_COMMONS_H_

// File Format
#define FORMAT_RECORD 0
#define FORMAT_INDEX 1

// Data Type
#define T_INT 0
#define T_FLOAT 1
#define T_CHAR 2

//=	<>	<	>	<=	>=
#define SIGN_EQ 0
#define SIGN_NE 1
#define SIGN_LT 2
#define SIGN_GT 3
#define SIGN_LE 4
#define SIGN_GE 5

#endif



// sql_type_ -1 means EMPTY
// sql_type_ 10 means quit
// sql_type_ 20 means help
// sql_type_ 30 means create database
// sql_type_ 31 means create table
// sql_type_ 32 means create index
// sql_type_ 40 means show database
// sql_type_ 41 means show tables
// sql_type_ 50 means drop database
// sql_type_ 51 means drop table
// sql_type_ 52 means drop index
// sql_type_ 60 means use
// sql_type_ 70 means insert
// sql_type_ 80 means exec
// sql_type_ 90 means select
// sql_type_ 110 means delete
// sql_type_ 120 means update

// vector<std::string> sql_vector_ ： save sql statement
// *st means class SQL and subCLass,eg: SQLCreateIndex
// MiniDBAPI *api;

// CatalogManager *cm_;
// BufferManager *hdl_;

// vector<Database> dbs_

//int record_length_;

//int first_block_num_;
//int first_rubbish_num_;
//int block_count_;

//std::vector<Attribute> ats_;
//std::vector<Index> ids_;

//std::string attr_name_;
//int data_type_;
//int length_;
//int attr_type_; 0 means data, 1 means index

//int max_count_;
//int key_len_;
//int key_type_;
//int rank_;
//int rubbish_;
//int root_;
//int leaf_head_;
//int key_count_;
//int level_;
//int node_count_;
//std::string attr_name_;
//std::string name_;


//int key_type_; 0 int , 1 float, 2 string
//char *key_;
//int length_;

//BlockHandle *bhandle_;
//FileHandle *fhandle_;
//std::string path_;

//BlockInfo *first_block_;
//int bsize_;  // total #
//int bcount_; // usable #
//std::string path_;

//FileInfo *file_;
//int block_num_;
//char *data_;
//bool dirty_;
//long age_;
//BlockInfo *next_;

// std::string db_name_;
// int type_;               // 0: data file, 1: index file
// std::string file_name_;  // the name of the file
// int record_amount_;      // the number of record in the file
// int record_length_;      // the length of the record in the file
// BlockInfo *first_block_; // point to the first block within the file
// FileInfo *next_;         // the pointer points to the next file
