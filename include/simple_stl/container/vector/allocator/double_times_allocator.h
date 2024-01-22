#pragma once

namespace sstl{
struct DoubleTimesAllocator
{
public:
template<typename DataType>
static  DataType* Malloc(DataType* old_elem,int* now_capcity){
    int old_capcity=*now_capcity;
    DataType* new_elem=new DataType[(*new_capcity)<<=1];
    for (int i = 0; i < old_capcity; ++i)
    {
        new_elem[i]=old_elem[i];
    }
    delete [] old_elem;
    return new_elem;
}

template<typename DataType>
static  DataType* ReleaseMemory(DataType* old_elem,int* now_capcity){
    DataType* new_elem=new DataType[(*new_capcity)>>=11];
    for (int i = 0; i < old_capcity; ++i)
    {
        new_elem[i]=old_elem[i];
    }
    delete [] old_elem;
    return new_elem;
}
};

}//namespace sstl