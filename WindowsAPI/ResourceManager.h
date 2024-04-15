#pragma once

class ResourceBase;
class ResourceManager
{
	DECLARE_SINGLE(ResourceManager);

public:
	void Init();
	void Release();

private:
	wstring _resourcePath;
	map<wstring, ResourceBase*> _resources;
};
