#include <string_view>
#include <cassert>

class CaseBase
{
protected:
	std::string m_caseName;
public:
	CaseBase() = default;

	virtual void Run() = 0;

	std::string_view GetCaseName() const;
};