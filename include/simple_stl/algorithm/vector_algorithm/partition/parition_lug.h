#pragma once

#include "simple_stl/container/vector/vector.h"


namespace sstl{
struct ParitionLUG
{
    // return the mid_rank
    // partition in [start, end)
    template<typename DataType>
    static int Call(Vector<DataType> *vec,const int& start_rank,const int& end_rank){
        int start=start_rank;
        int end=end_rank-1;
        DataType pivot=vec->Get(start);
        while (start<end)
        {
            while (start<end&&vec->Get(end)>=pivot)
            {
                --end;
            }
            vec->Put(start,vec->Get(end));
            while (start<end&&vec->Get(start)<=pivot)
            {
                ++start;
            }
            vec->Put(end,vec->Get(start));
        }
        vec->Put(start,pivot);
        return start;

    }
};

}//namspace sst