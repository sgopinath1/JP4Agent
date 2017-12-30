//
// Juniper P4 compiler 
//
/// @file  backend.cpp
/// @brief P4 compiler for Juniper AFI
//
// Created by Sandesh Kumar Sodhi, December, 2017
// Copyright (c) [2017] Juniper Networks, Inc. All rights reserved.
//
// All rights reserved.
//
// Notice and Disclaimer: This code is licensed to you under the Apache
// License 2.0 (the "License"). You may not use this code except in compliance
// with the License. This code is not an official Juniper product. You can
// obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0
//
// Third-Party Code: This code may depend on other components under separate
// copyright notice and license terms. Your use of the source code for those
// components is subject to the terms and conditions of the respective license
// as noted in the Third-Party source code file.
//


#include "errorcode.h"

namespace AFI {

bool
ErrorCodesVisitor::preorder(const IR::Type_Error* errors) {
    auto &map = *errorCodesMap;
    for (auto m : *errors->getDeclarations()) {
        BUG_CHECK(map.find(m) == map.end(), "Duplicate error");
        map[m] = map.size();
    }
    return false;
}

}  // namespace AFI
