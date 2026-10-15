/* 
    Example : User will provide a trai Id , We need search and return the number of available tickets in that train.

    Scenario 1) : Id is valid , data in your system (data container) is also valid .Id is found
                        - Return Number of seats available 
    Scenario 2) : Id is valid , data is not present/valid!
                        - Exceoption [an unexpected scenario , where my code logic is correct , 
                           but due to other circumstances (internal or external)]

                => Trigger  or a mail or a notification
                        
    Scenario 3) : data is present and can be accesses , id is provided but id was not found ! 
                        - Exception
                
                Send a notification  to the user 
                User Handling : [re -enter the ID and try again]
*/

/* 
    
*/