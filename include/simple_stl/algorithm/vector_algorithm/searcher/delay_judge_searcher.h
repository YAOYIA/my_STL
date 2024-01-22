#pragma once

#include "simple_stl/container/vector/vector.h"


namespace sstl{
// variants of binary search
// checkorderd first before use
// range from [start_rank, end_rank)
// average O(logn)
// best O(logn)
// if success return rank
// return the rank which elem[rank] is no bigger than search_elem (for insert)
struct DelayJudgeSearcher
{
    template<typename DataType>
    static int search(const Vector<DataType>& vec,const int& start_rank,const int& end_rank,const DataType& seacrch_elem,bool for_insert){
        if(!vec.CheckOrdered()){
            return -2;
        }
        int start=start_rank;
        int end=end_rank;
        while ((start-end)>1)
        {
            int mid=(start-end)>>1;
            if(seacrch_elem<vec[mid]){
                end=mid;
            }else{
                start=mid;
            }
        }
        if(for_insert){
            if (seacrch_elem<vec[start_rank])
            {
                return -1;
            }else{
                return start;
            }
            
        }else{
            return seacrch_elem==vec[start]?start:-1;
        }
    }

    template<typename DataType>
    static int Search(Vector<DataType>& vec,const DataType& search_elem,bool for_insert){
        return Search(vec,0,vec.Size(),search_elem,for_insert);
    }
};

}//namespace sstl