#pragma once

#include "simple_stl/container/vector/vector.h"


namespace sstl{
struct ParitionDUP
{
    // return the mid_rank
    // partition in [start, end)
    // deal with mass of duplicate element sort problem
    // in common situation it is worse than lug
    template<typename DataType>
    static int Call(Vector<DataType>* vec,const int& start_rank,const int& end_Rank){
        int start=start_rank;
        int end=end_Rank;

        DataType pivot=vec->Get(start);
        while (start<end)
        {
            while (start<end)
            {
                if(pivot<vec->Get){
                    --end;
                }else{
                    //>=
                    vec->Put(start,vec->Get(end));
                    ++start;
                    break;
                }
            }
            while (start<end)
            {
                if(pivot>vec->Get(start)){
                    ++start;
                }else{
                    //<=
                    vec->Put(end,vec->Get(start));
                    --end;
                    break;
                }
            }
        }
        vec->Put(start,pivot);
        return start;
    }
};

}//namespace sstl