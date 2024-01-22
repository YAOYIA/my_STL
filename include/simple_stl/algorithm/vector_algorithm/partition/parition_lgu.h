#pragma once


#include "simple_stl/container/vector/vector.h"
#include "simple_stl/utility/utility.h"


namespace sstl{
struct ParitionLGU
{
    //return the mid_rank
    //partition in [start,end]
    //return on swap

    template<typename DataType>
    static int Call(Vector<DataType>* vec,const int& start_rank,const int& end_rank){
        int start=start_rank;
        int end=end_rank;
        int mid_rank=start;
        DataType pivot=vec->Get(pivot);
        for (int i = start+1; i < end; i++)
        {
            if(vec->Get(i)<pivot){
                ++mid_rank;
                Swap(&(*vec)[mid_rank],&(*vec)[i]);
            }
        }
        Swap(&(*vec)[start],&(*vec)[mid_rank]);
        return mid_rank;
        
    }
};

}//namespace sstl