
#include<stdexcept>

class IdNotFoundError: public std::exception
{
private:
    std::string _msg;
public:
    IdNotFoundError(const std::string& msg)
    : _msg{msg} {}

    ~IdNotFoundError() {}

    IdNotFoundError(const IdNotFoundError&) = delete;
    IdNotFoundError(IdNotFoundError&&) = default;

    IdNotFoundError& operator=(const IdNotFoundError&) = delete;
    IdNotFoundError& operator=(IdNotFoundError&&) = default;
    const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
    {
        return _msg.c_str();
    };

    std::string msg() const { return _msg; }


    // FUnction to convert string into a character
};

///// Fuctionalit
    if(N <=0 || N > data.size()){
        throw InvalidError("N is invalid , cannot perform operations");
    }


////// Main
    try{
        FindCarTypeById(car_data , "102");
    }
    catch(const IdNotFoundError& ex){
        std::cerr<<ex.what()<<"\n";
    }
