
//Basic code for an all purpose memory pool. Very simple one but powerful if used correctly nonetheless.
//A memory pool is a data structs that stores information of an all purpose reserved data.
//I consider this the first thing you should learn once you get into intermediate C.
//Since this is not Cpp, It won't be object-oriented, which is fine because this is a data-oriented design pattern.


//This header will let us use some interesting int types instead of the generic ones
#include <stddef.h>
//Header for boolean type because C doesn't have it natively
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Data that has the information of the memory pool
typedef struct MemoryPool{

    void* reservedData;
    size_t elementsReserved;
    size_t bytesReserved;
    bool loaded;

} MemoryPool;

bool RESERVEDATA(size_t sizeOfElement, size_t numberToReserve, MemoryPool* poolReference){

    //Return value
    bool succesful = false;
    //If the pool wasn't loaded before
    if(!poolReference->loaded){
        //We reserve data
        poolReference->reservedData = malloc(sizeOfElement*numberToReserve);
        //if the data has been reserved succesfully
        if(poolReference != NULL){
            succesful = true;
            poolReference->elementsReserved = numberToReserve;
            poolReference->bytesReserved = numberToReserve*sizeOfElement;
        }
    }
    
    return succesful;

}

bool FREEDATA(MemoryPool* poolReference){
    bool succesful = false;

    if(poolReference->loaded){
        //We free the data
        free(poolReference->reservedData);
        succesful = true;
        poolReference->loaded = false;
    }

    return succesful;
}

//Any type of data that we want to store in RAM memory
typedef struct Data{
    
    unsigned int age;
    char gender[15];
    char name[30];
    char email[50];
    
}Data;

int main(){

    MemoryPool DataStorage;

    RESERVEDATA(sizeof(Data), 8,&DataStorage);

    Data* dataArray = (Data*)DataStorage.reservedData;
    
    Data* Antonio = &dataArray[0];
    
    Data* Sonic = &dataArray[7];
    
    strncpy(Antonio->name, "Antonio", 30);
    Antonio->age = 24;
    strncpy(Antonio->gender, "Male", 15);
    strncpy(Antonio->email, "tony.randalph@gmail.com", 50);;
    
    strncpy(Sonic->name, "Cool Hedgehog 101", 30);
    
    for(size_t i = 0; i < DataStorage.elementsReserved; i++){
        
        Data element = ((Data*)DataStorage.reservedData)[i];
        
        printf("Name: %s\n",element.name);
    }
    
    FREEDATA(&DataStorage);

    return 0;
}