#pragma once

#include <string_view>
#include <cassert>

class CaseBase
{
protected:
	std::string m_caseName;
public:
	CaseBase() = default;

	virtual void EnqueueWrap(int) = 0;

	virtual void DequeueWrap(int&) = 0;

	std::string_view GetCaseName() const;
};