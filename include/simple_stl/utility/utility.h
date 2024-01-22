#pragma once



namespace sstl{
template<typename DataType>
static DataType Max(const DataType& a,const DataType & b){
    return a>b?a:b;
}

template<typename DataType>
static void Swap(DataType &left,DataType &right){
    DataType temp=left;
    left=right;
    right=temp;
}

}//namespace sstl