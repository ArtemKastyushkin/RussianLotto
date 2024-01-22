#if !defined STORAGE_H
#define STORAGE_H

#include "game.h"
#include "record.h"
#include <vector>
#include "ShortCardObject.h"

class Storage
{
public:
	virtual void Save(Game* game) { };
	virtual Game Load(std::string nickname) { return Game(std::string()); };
	virtual void SaveRecord(Record record) { };
	virtual std::vector<Record> GetRecords() { return std::vector<Record>(); };
	virtual bool IsUserExist(std::string nickname) { return false; }
};

#endif#