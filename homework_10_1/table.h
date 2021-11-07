#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <set>
#include <map>

struct tableStruct
{
    tableStruct(int _id, std::string _name): id(_id), name(_name){};
    int id;
    std::string name;
    bool operator< (const tableStruct& T) const {return this->id<T.id;}
};

using joinedTablesOutput = std::map<int, std::pair<std::string, std::string>>;

class table
{
public:
    table();
    int insertIntoTable(int id, std::string name); //returns duplicate id or -1 if success
    joinedTablesOutput getIntersectionTable(table&) const;
    joinedTablesOutput getSymmetricDifferenceTable(table&) const;
    void truncateTable() noexcept;
    std::string getNameById(int id) const;
    std::set<int> getKeys() const;

private:
    std::set<tableStruct> tableContent;
    std::set<int> keys;
};

#endif // TABLE_H
