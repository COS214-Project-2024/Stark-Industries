#ifndef RESOURCEMANAGERMENT_H
#define RESOURCEMANAGERMENT_H

#include <string>
using namespace std;

class ResourceManagerment {

private:
	ResourceManagerment* onlyInstance;
	string resourceType;

public:
	ResourceManagerment* getInstance();

	void updateResourceData();

	void createResources();

	void supplyResources();

protected:
	void ResourceManagement();

public:
	string getResourceType();

	void requestUtilities();
};

#endif
