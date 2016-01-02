#pragma once

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>

class filewatcher
{
public:
	explicit filewatcher(const std::string &path);
	~filewatcher();

	bool check(std::vector<std::string> &modifications);

private:
	std::string _path;
	std::unique_ptr<unsigned char[]> _buffer;
	void *_handle, *_completion_handle;
	std::unordered_map<std::string, unsigned long> _file_times;
};