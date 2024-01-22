#pragma once

#include "include/sample_stl/container/vector/vector.h"
#include "include/sample_stl/algorithm/vector_algorithm/finder/vector_finder.h"


namespace sstl{
// for disordered vector
// you can use bitmap to improve the efficiency
// with bitmap you can get a average O(n) algorithm
// but it only suits for int, char, short,
// for other type you can use hash_map
// the best O(n)
// the worst O(n^2)
// return old_size - new_size

struct VectorDeduplicator
{
    template<typename DataType>
    static int Deduplicate(Vector<DataType>* vec){
        int old_size=vec->Size();
        int new_size=old_size;
        int left=1;
        int right=1;
        while (right<old_size)
        {
            if(VectorFinder::Find(*vec,0,left,(*vec)[right])<0){
                (*vec)[left]=(*vec)[right];
                ++left;
            }else{
                --new_size;
            }
            ++right;
        }
        vec->Remove(new_size,old_size);
        return old_size-new_size;
    }
};





}//namespace sstl