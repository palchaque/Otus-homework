#include "table.h"

table::table()
{

}

int table::insertIntoTable(int id, std::string name)
{
    auto keyInTable = keys.find(id);
    if (keyInTable == keys.end())
    {
        keys.emplace(id);
        tableContent.emplace(tableStruct(id, name));
        return -1;
    }
    else
    {
        return *(keyInTable);
    }
}

void table::truncateTable() noexcept
{
    tableContent.clear();
    keys.clear();
}

std::set<int> table::getKeys() const
{
    return this->keys;
}

joinedTablesOutput table::getIntersectionTable(table& tab) const
{
    joinedTablesOutput output;
    std::set<int> keysIntTable = tab.getKeys();
    for (auto key: keys)
    {
        if(keysIntTable.find(key) != keysIntTable.end())
        {
            output.emplace(key, std::make_pair(getNameById(key), tab.getNameById(key)));
        }
    }

    return output;
}

joinedTablesOutput table::getSymmetricDifferenceTable(table& tab) const
{
    joinedTablesOutput output;
    std::set<int> keysIntTable = tab.getKeys();
    for (auto key: keys)
    {
        if(keysIntTable.find(key) == keysIntTable.end()) output.emplace(key, std::make_pair(getNameById(key), tab.getNameById(key)));
    }
    for (auto key: keysIntTable)
    {
        if(keys.find(key) == keys.end()) output.emplace(key, std::make_pair(getNameById(key), tab.getNameById(key)));
    }
    return output;
}

std::string table::getNameById(int id) const
{
    if(keys.find(id) == keys.end()) return "";

    for (auto content: tableContent)
    {
        if(content.id == id) return content.name;
    }
}
