#pragma once

// Custom Classes
#include "CDTable.h"

struct CDMissionTasks {
	unsigned int id;                //!< The Mission ID that the task belongs to
	UNUSED_COLUMN(unsigned int locStatus);         //!< ???
	unsigned int taskType;          //!< The task type
	unsigned int target;            //!< The mission target
	std::string targetGroup;        //!< The mission target group
	int targetValue;       //!< The target value
	std::string taskParam1;    //!< The task param 1
	UNUSED_COLUMN(std::string largeTaskIcon); //!< ???
	UNUSED_COLUMN(unsigned int IconID);            //!< ???
	unsigned int uid;               //!< ???
	UNUSED_COLUMN(unsigned int largeTaskIconID);   //!< ???
	UNUSED_COLUMN(bool localize);          //!< Whether or not the task should be localized
	UNUSED_COLUMN(std::string gate_version);  //!< ???
};

class CDMissionTasksTable : public CDTable<CDMissionTasksTable> {
private:
	std::vector<CDMissionTasks> entries;

public:
	CDMissionTasksTable();
	// Queries the table with a custom "where" clause
	std::vector<CDMissionTasks> Query(std::function<bool(CDMissionTasks)> predicate);

	std::vector<CDMissionTasks*> GetByMissionID(uint32_t missionID);

	const std::vector<CDMissionTasks>& GetEntries(void) const;
};

