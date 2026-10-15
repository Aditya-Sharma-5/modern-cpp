#include "Project.h"



Project::Project(std::string id, float budget, int tcount, ProjectType ptype, float revenue, std::string owner, std::string client)
: m_project_id{id} , m_project_budget{budget} , m_project_team_count{tcount}, m_project_type{ptype} , m_project_expected_revenue{revenue} , m_project_owner{owner} , m_project_client{client}
{
}

std::ostream &operator<<(std::ostream &os, const Project &rhs)
{
    os << "m_project_id: " << rhs.m_project_id
       << " m_project_budget: " << rhs.m_project_budget
       << " m_project_team_count: " << rhs.m_project_team_count
       << " m_project_type: " <<static_cast<int>( rhs.m_project_type)
       << " m_project_expected_revenue: " << rhs.m_project_expected_revenue
       << " m_project_owner: " << rhs.m_project_owner
       << " m_project_client: " << rhs.m_project_client;
    return os;
}
