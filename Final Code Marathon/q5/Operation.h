#ifndef OPERATION_H
#define OPERATION_H

#include"Chasis.h"
#include<list>
#include<memory>
#include<unordered_set>
#include<functional>
#include<queue>
#include<thread>
#include<vector>
#include<mutex>

using Cptr = std::shared_ptr<Chasis>;
using Container = std::list<Cptr>;
using VContainer = std::vector<Cptr>;
using Set = std::unordered_set<ChasisMaterial>;
using Pair = std::pair<float  , float>;
using Predicate = std::function<bool(Cptr)>;
using Comparator = std::function<bool(const Cptr &, const Cptr &)>;

using PQ = std::priority_queue<Cptr , VContainer , Comparator>;
using ThContainer = std::list<std::thread>;


class Operation
{
private:


    static std::shared_ptr<Operation> m_instance;
    Container m_chasis_instances;
    Set m_chasis_material_set;
    Pair m_length_width_pair;
    Predicate m_predicate_function{[&](const Cptr& ptr){return ptr.get()->isChasisNcapCompliant();}};
    Container m_filtered_chasis_instances;
    PQ m_prioritized_chasis_instances{};
    Comparator m_comparator_function{[&](const Cptr& ptr1 , const Cptr& ptr2){return ptr1.get()->chasisLength() > ptr2.get()->chasisLength();} };
    // PQ m_prioritized_chasis_instances{m_comparator_function};
    ThContainer data ; 




    Operation() = default;
    Operation( PQ pq );

    Operation(const Operation&) = default;
    Operation(Operation&&) = default;

    Operation& operator=(const Operation&) = default;
    Operation& operator=(Operation&&) = default;
public:
    ~Operation() = default;

    static std::shared_ptr<Operation> getInstance();


    // This function is used to create the objects of Chasis
    void CreateObject();

    //This function is used to create the unordered set of Unique Elements
    void CreateSet();

    // This function is used to create the Pair 
    void CreatePair();


    // This function is used to store the filtered Chasis Elements
    void FIlteredChasis();


    //This function is used to create the priority queue
    void CreatePriorityQueue();


    //This function is used to display the priority queue
    void displayPriorityQueue();

    //This function is used to display the pair 
    void displayPair();

    //This function is used to display the Unordered Set
    void displaySet();

    //This function is used to display the filtered objects
    void displayFilteredObjects();

    //This function is used to create the thread
    void createThread();

    //This function is used to join the thread ();
    void JoinThread();





};

#endif // OPERATION_H
