//
//  templateExamples.h
//  UsingStd16
//
//  Created by Tweak on 23/10/16.
//  Copyright © 2016 Tweak. All rights reserved.
//

#ifndef templateExamples_h
#define templateExamples_h

#include <magicDataBase/MagicDataBase.h>

namespace templateExamples
{

template <typename DataType>
bool foo1(MagicDataBase<DataType> &dataBase,
          DataType data)
{
    dataBase.insert(data);
    return dataBase.size() == 1;
}




} // end namespace templateExamples

#endif /* templateExamples_h */
