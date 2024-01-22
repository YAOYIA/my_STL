#pragma once 

#include "simple_stl/container/vector/vector.h"
#include "simple_stl/utility/utility.h"


namespace sstl{
struct VectorReverser
{
    //reverse in [start,end]
    template<typename DataType>
    static void Reverse(Vector<DataType> *vec,const int& start_rank,const int& end_rank){
        if(vec->Size()>1){
            int leftindex=start_rank;
            int rightindex=end_rank;
            while (leftindex<rightindex)
            {
                Swap(&(*vec)[leftindex],&(*vec)[rightindex]);
                ++leftindex;
                ++rightindex;
            }
            
        }
    }

    template<typename DataType>
    static void Reverse(Vector<DataType>* vec){
        Reverse<DataType>(vec,0,vec->Size());
    }
};

}//namespace sstl