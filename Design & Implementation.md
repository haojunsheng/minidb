# Design & Implementation

There are 6 main modules in this database engine: Interpreter, API, Record Manager, Index Manager, Catalog Manager and Buffer Manager.

<img src="https://raw.githubusercontent.com/Anapodoton/ImageHost/master/20191012101020.png" style="zoom:50%;" />

#### Interpreter

The function of this module is to interprate and execute SQL statements. Everytime the interpreter receives a SQL statement; it formats the SQL statement, constructs a SQL statement object, and passes this object to the appropriate function in API. If it detects an incorrect syntax, it will throw a syntax error exception. There are the following main classes in this module:

- Interpreter: the class interprating SQL statements;
- TKey: a uniform class which stores values in SQL statements;
- SQL: base class for the following SQL statement classes storing statements;
- SQLCreateDatabase
- SQLDropDatabase
- SQLDropTable
- SQLDropIndex
- SQLUse
- SQLCreateTable
- SQLInsert
- SQLExec
- SQLSelect
- SQLCreateIndex
- SQLDelete
- SQLUpdate



#### API

This module wraps the interface Record Manager, Index Manager and Catalog Manager provide, so that the interpreter could use a uniform program interface.

There is only one class in this module:

- MiniDBAPI

#### Record Manager

This module provides programming interface for record manipulation including select, insert, delete, and update.

There is only one class in this module:

- RecordManager

Record Manager负责管理记录表中数据的数据文件。主要功能为实现数据文件的创建与删除（由表的定义与删除引起）、记录的插入、删除与查找操作，并对外提供相应的接口。其中记录的查找操作要求能够支持不带条件的查找和带一个条件的查找（包括等值查找、不等值查找和区间查找）。

数据文件由一个或多个数据块组成，块大小应与缓冲区块大小相同。一个块中包含一条至多条记录，为简单起见，只要求支持定长记录的存储，且不要求支持记录的跨块存储。

#### Index Manager

This module provides programming interface for index management such as create index. It includes an implementation of B+ tree.

There are three classes in this module:

- IndexManager
- BPlusTree: B+ tree
- BPlusTreeNode: B+ tree node

Index Manager负责B+树索引的实现，实现B+树的创建和删除（由索引的定义与删除引起）、等值查找、插入键值、删除键值等操作，并对外提供相应的接口。

B+树中节点大小应与缓冲区的块大小相同，B+树的叉数由节点大小与索引键大小计算得到。

#### Catalog Manager

This module manges the catalog information, and stores the information on disk using boost serialization library. The information includes databases, tables, indexes, and attributes.

There are five classes in this module:

- CatalogManager
- Database
- Table
- Attribute
- Index

Catalog Manager负责管理数据库的所有模式信息，包括：

1. 数据库中所有表的定义信息，包括表的名称、表中字段（列）数、主键、定义在该表上的索引。
2. 表中每个字段的定义信息，包括字段类型、是否唯一等。
3. 数据库中所有索引的定义，包括所属表、索引建立在那个字段上等。

Catalog Manager还必需提供访问及操作上述信息的接口，供Interpreter和API模块使用。

#### Buffer Manager

This module manages the buffer. The replacement policy used here is LRU (least recent used). In buffer manager, each block has a size of 4K.

There are two linked lists in this module.

##### Free Block Chain: BlockHandle

In this linked list, all blocks are free to use.

##### File Chain: FileHandle

In this chain, each file node has two linked lists, one of which is the current used block chain, and the other is the recycled block chain. When the database engine needs a new block, it first checks whether there is a usable recycled block chain. If not, it queries BlockHandle to ask whether it has a free block to offer. If not again, LRU will come into work.



1. 根据需要，读取指定的数据到系统缓冲区或将缓冲区中的数据写出到文件；

2. 实现缓冲区的替换算法，当缓冲区满时选择合适的页进行替换；

3. 记录缓冲区中各页的状态，如是否被修改过等；

4. 提供缓冲区页的pin功能，及锁定缓冲区的页，不允许替换出去。

为提高磁盘I/O操作的效率，缓冲区与文件系统交互的单位是块，块的大小应为文件系统与磁盘交互单位的整数倍，一般可定为4KB或8KB。



记录管理模块（RecordManager）和索引管理模块（IndexManager）向缓冲区管理申请所要的数据，缓冲区管理器首先在缓冲区中查看数据是否存在，若存在，直接返回，否则，从磁盘中将数据读入缓冲区，然后返回。

最近最少使用(LRU)算法：每次访问一个块的时候，如果是重新读取的话把该块的iTime置为1，如果是已经有的话把它的使用次数加一。采用这种方式记录主要是因为对于Index部分，比如根节点的使用率一直保持非常高。

换出脏块时需要写出块。

 