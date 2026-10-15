#include "functionalities.h"

void AdaptorInt(const IntContainer &data, PredicateInt fn)
{
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(int value : data)
    {
        if(fn(value))
        {
            std::cout<<value<<" ";
        }
    }
}

void AdaptorString(const StringContainer &data, PredicateString fn)
{

    // Exception for Empty COntainer
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(std::string str : data)
    {
        if(fn(str))
        {
            std::cout<<str<<" ";
        }
    }
}

void AdaptorForTransformString(StringContainer &data, UnaryString fn)
{

    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(std::string str : data)
    {
        std::cout<<fn(str)<<" ";
    }
}

void AdaptorForTransformInt(IntContainer &data, UnaryInt fn)
{
    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(int value : data)
    {
        std::cout<<fn(value)<<" ";
    }
}



///////////   adaptor for integer values  /////////////////
void AdaptorForTransformIntoFloat(IntContainer &data, UnaryFloat fn)
{

    if(data.empty())
    {
        throw EmptyContainerError("Data Container is Empty!!!\n");
    }

    for(int value : data)
    {
        std::cout<<fn(value)<<" ";
    }

}
