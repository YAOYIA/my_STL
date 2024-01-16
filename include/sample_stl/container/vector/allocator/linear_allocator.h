#pragma once

namespace sstl{
template <int EachTimeIncrease = 1>
struct LinearAllocator
{
    public:
    template<typename DataType>
    static DataType* Malloc(DataType* old_elem,int* now_capcity){
        int old_capicity=*now_capcity;
        (*now_capcity)+=EachTimeIncrease;
        DataType* new_elem=new DataType[(*now_capcity)];
        for (int i = 0; i < old_capicity; ++i)
        {
            new_elem[i]=old_elem[i];
        }
        delete [] old_elem;
        return new_elem;
    }//Malloc

    static DataType* ReleaseMemroy(DataType* old_elem,int* now_capcity){
        (*now_capcity)-=EachTimeIncrease;
        DataType* new_elem=new DataType[(*now_capcity)];
        for (int i = 0; i < (*now_capcity); ++i)
        {
            new_elem[i]=old_elem[i];
        }
        delete [] old_elem;
        return new_elem;
    }
};
}//namespace sstl

     


