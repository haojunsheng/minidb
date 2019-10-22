#ifndef MINIDB_FILE_INFO_H_
#define MINIDB_FILE_INFO_H_

#include <string>
#include "commons.h"

class BlockInfo;

class FileInfo {
private:
  std::string db_name_;
  int type_;               // 0: data file, 1: index file
  std::string file_name_;  // the name of the file
  int record_amount_;      // the number of record in the file
  int record_length_;      // the length of the record in the file
  BlockInfo *first_block_; // point to the first block within the file
  FileInfo *next_;         // the pointer points to the next file
public:
  FileInfo()
      : db_name_(""), type_(FORMAT_RECORD), file_name_(""), record_amount_(0),
        record_length_(0), first_block_(0), next_(0) {}
  FileInfo(std::string db, int tp, std::string file, int reca, int recl,
           FileInfo *nex, BlockInfo *firb)
      : db_name_(db), type_(tp), file_name_(file), record_amount_(reca),
        record_length_(recl), first_block_(firb), next_(nex) {}
  ~FileInfo() {}

  std::string db_name() { return db_name_; }

  int type() { return type_; }

  std::string file_name() { return file_name_; }

  // 获取用于替换的内存块
  // 首先遍历文件节点，判断每个文件节点下是否有dullNode，有的话返回。
  // 其次如果块数未达到MAX_BLOCK，申请内存。
  // 如没有可用块，遍历所有的块节点使用LRU算法找到没有使用的时间最长的块（itime最大），从文件节点下移去，itime置为1；并将该块返回。
  BlockInfo *first_block() { return first_block_; }
    
  void set_first_block(BlockInfo *bp) { first_block_ = bp; }

  FileInfo *next() { return next_; }
  void set_next(FileInfo *fp) { next_ = fp; }

  void IncreaseRecordAmount() { record_amount_++; }
  void IncreaseRecordLength() { record_length_ += 4096; }
};

#endif
