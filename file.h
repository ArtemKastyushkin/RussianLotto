#if !defined FILE_H
#define FILE_H

#define USERS_FILE_PATH "users.txt"
#define RECORDS_FILE_PATH "records.txt"

#include "storage.h"

class File : public Storage
{
public:
	void Save(Game* game) override;
	Game Load(std::string nickname) override;
	bool IsUserExist(std::string nickname) override;
	void SaveRecord(Record record) override;
	std::vector<Record> GetRecords() override;
};

#endif#