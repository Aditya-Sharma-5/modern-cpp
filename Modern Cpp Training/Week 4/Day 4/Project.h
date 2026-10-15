#ifndef PROJECT_H
#define PROJECT_H

#include"ProjectType.h"
#include<iostream>

class Project
{
private:
    std::string m_project_id;
    float m_project_budget;
    int m_project_team_count;
    ProjectType m_project_type;
    float m_project_expected_revenue;
    std::string m_project_owner;
    std::string m_project_client;
public:
    Project() = default;
    ~Project() = default;

    Project(const Project&) = delete;
    Project(Project&&) = delete;

    Project& operator=(const Project&) = default;
    Project& operator=(Project&&) = default;

    Project(std::string id , float budget , int tcount , ProjectType ptype , float revenue , std::string owner , std::string client);

    float projectBudget() const { return m_project_budget; }
    void setProjectBudget(float project_budget) { m_project_budget = project_budget; }

    std::string projectId() const { return m_project_id; }
    void setProjectId(const std::string &project_id) { m_project_id = project_id; }

    int projectTeamCount() const { return m_project_team_count; }
    void setProjectTeamCount(int project_team_count) { m_project_team_count = project_team_count; }

    ProjectType projectType() const { return m_project_type; }
    void setProjectType(const ProjectType &project_type) { m_project_type = project_type; }

    float projectExpectedRevenue() const { return m_project_expected_revenue; }
    void setProjectExpectedRevenue(float project_expected_revenue) { m_project_expected_revenue = project_expected_revenue; }

    std::string projectOwner() const { return m_project_owner; }
    void setProjectOwner(const std::string &project_owner) { m_project_owner = project_owner; }

    std::string projectClient() const { return m_project_client; }
    void setProjectClient(const std::string &project_client) { m_project_client = project_client; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);

    void operator<<(const ProjectType& rhs);
};


#endif // PROJECT_H
