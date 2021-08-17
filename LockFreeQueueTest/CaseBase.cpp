#include "CaseBase.h"

std::string_view CaseBase::GetCaseName() const
{
    assert(false == m_caseName.empty());

    return m_caseName;
}
