#include"functionalities.h"

int main(){

    //Lambda function for Square root 
    auto f1 = [](int n )
    {
        if(n<0)
        {
            throw NegativeNumberError("Negative Number!!");
        }
        return float(sqrt(n));
        // return std::pow(n , 0.5);

    };


    // Lambda function for Factorial
    auto f2 = [](int n){
        if(n<0){
            throw NegativeNumberError("The Number is Negative");
        }
        if(n>11){
            return -1;
        }
        else if(n== 0){
            return 1;
        }
        else{
            int factorial = 1;
            for(int i = n;n>0;n--){
                factorial *= n;
            }
            return factorial;
        }

    };


    //Lambda function for String Filteration
    auto f3 = [](std::string str)
    {
        if(str.length() == 0 && str.length()>10)
        {
            throw EmptyStringError("The String is Empty!!");
        }

        else if(str.length() >6)
        {
            return str[str.length() -1];
        }

        else
            {
                int count = 0;
                std::string vowels = "aeiouAEIOU";
                for(int i = 0 ; i<str.length() ; i++){
                    if(vowels.find(str[i]) != std::string::npos){
                        count++;
                    }
                }
                if(count == 0){return '0';}
                else if(count == 1){return '1';}
                else if(count == 2){return '2';}
                else if(count == 3){return '3';}
                else if(count == 4){return '4';}
                else if(count == 5){return '5';}
                else if(count == 6){return '6';}
                else if(count == 7){return '7';}
                else if(count == 8){return '8';}
                else{return '9';}
            }

    };

    auto f4 = [](int n){
        if(n<0){
            throw NegativeNumberError("The Number is Negative");
        }
        if(n ==1 ||n==2 || n==3){
            return true;
        }
        else
        {
            for(int i = 2; i<n;i++){
                if(n%i == 0){
                    return false;
                }
            }
            return true;
        }
    };


    ////////////          Creating Container        ///////////////////
    IntContainer _data{0,4,5,8,9,12,-5,64};
    StringContainer _string_data{"Aadi" , "Python" , "C++" , "Prashant"};



    ///////////      Adaptor having function signature for checking prime number ////
    std::cout<<"First Adaptor\n";
    try{
    AdaptorInt(_data , f4 );
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const NegativeNumberError& ex){
        std::cerr<<ex.what()<<"\n";
    }




    ///////////      Adaptor having function signature for converting number into its square root ////
    try
    {
        std::cout<<"Second Adaptor\n";
        AdaptorForTransformIntoFloat(_data , f1);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const NegativeNumberError& ex){
        std::cerr<<ex.what()<<"\n";
    }




    ///////////      Adaptor having function signature for factorila values ////
    try
    {
        std::cout<<"Third Adaptor\n";
        AdaptorForTransformInt(_data , f2);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const NegativeNumberError& ex){
        std::cerr<<ex.what()<<"\n";
    }





    ///////////      Adaptor having function signature for checking vowels count in a string ////    
    try
    {
        std::cout<<"Fourth Adaptor\n";
        AdaptorForTransformString(_string_data , f3);
    }
    catch(const EmptyContainerError& ex){
        std::cerr<<ex.what()<<"\n";
    }
    catch(const EmptyStringError& ex){
        std::cerr<<ex.what()<<"\n";
    }


    return 0;
}